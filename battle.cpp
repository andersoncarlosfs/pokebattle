//https://github.com/weehowe-z/Backup/tree/master/opengl/GLTank
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: lsdfusion
 *
 * Created on 10 March 2017, 11:04
 */

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <OpenGL/glu.h>    
#include <GLUT/glut.h>
#else
#include <GL/gl.h> 
#include <GL/glu.h>  
#include <GL/glut.h>   
#endif

#include <cstdlib>
#include <iostream>     
#include <cmath>       
#include <vector>

#include "land.h"
#include "lake.h"
#include "pokemon.h"
#include "squirtle.h"
#include "electrode.h"
#include "bubble.h"
#include "bubbles.h"

using namespace std;

/* Définition des paramètes dynamiques */
#define G 9.8 // m/s^2
#define B 0.8 // Damping


/* Source de lumière */
GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 0.0}; /*  composante diffuse */
GLfloat light_position[] = {0.0, 10.0, 10.0, 0.0}; /*  position */

/* Variables d'animation */
float up_down = 0.0, left_right = -1.57;
float cam_pos_x = 0.0;
float cam_pos_z = 50.0;
float cam_look_x = 0.0;
float cam_look_z = 0.0;
float vect_x = 0.0;
float vect_z = 0.0;
double d = 30;

//
vector<Object*> objects;

//
Land* land;
Lake* lake;

//
Pokemon* squirtle;
Pokemon* electrode;

//
Attack* bubble;
Attack* bubbles;

// Pas de temps
double dt = 0.07;

/* code ASCII pour la touche escape*/
#define ESCAPE 27

/* Idantifiant de la fenêtre GLUT */
int window;

/* Déclaration des en-têtes */
void rotate_camera(double speed);
void move_camera(double speed);
void InitDynamicParam();

/* Fonction d'initialisation */
void InitGL(int Width, int Height) {
    // Couleur d'effacement du buffer de couleur
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    // paramètrage du Z-buffer
    glClearDepth(1.0);
    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);

    // Activation de l'éclairage
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);

    // Activation du lissage
    glShadeModel(GL_SMOOTH);

    // Projection perceptive
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (GLfloat) Width / (GLfloat) Height, 0.1f, 100.0f);

    glMatrixMode(GL_MODELVIEW);

    // #
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Initialisation des paramètres dynamiques
    InitDynamicParam();

}

/* Fonction de redimensionnement de la fenêtre */
void ReSizeGLScene(int Width, int Height) {
    if (Height == 0)
        Height = 1;

    glViewport(0, 0, Width, Height);

    // Projection perceptive
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (GLfloat) Width / (GLfloat) Height, 0.1f, 100.0f);

    glMatrixMode(GL_MODELVIEW);

    // #
    glLoadIdentity();

    // #
    glDepthFunc(GL_LEQUAL);

    // #
    glEnable(GL_CULL_FACE);

}

/* Focntion de dessin */
void DrawGLScene() {
    // Effacement du buffer de couleur et de profondeur
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(cam_pos_x, 10.0, cam_pos_z, cam_look_x, 5.0, cam_look_z, 0.0, 1.0, 0.0);

    //////////////////////////////////////////////////

    for (int i = 0; i < objects.size(); i++) {

        objects[i]->draw();

    }

    // Permutation des buffers
    glutPostRedisplay();
    glutSwapBuffers();
}

/* Fonction de gestion du clavier */
void keyPressed(unsigned char key, int x, int y) {

    switch (key) {

        case ESCAPE:
            /* Eteindre la fenêtre */
            glutDestroyWindow(window);
            /* Sortir du programme */
            exit(0);
            break;

        case 'd':
            electrode->defend(true);
            break;

    }

    glutPostRedisplay();
    glutSwapBuffers();

}

/* Fonction de gestion du clavier */
void keyReleased(unsigned char key, int x, int y) {

    switch (key) {

        case 'd':
            electrode->defend(false);
            break;

    }

    glutPostRedisplay();
    glutSwapBuffers();

}

/* Fonction de gestion du clavier special */
void Special_key(int key, int x, int y) {

    switch (key) {
        case GLUT_KEY_RIGHT:
            left_right += 0.03;
            rotate_camera(left_right);
            break;

        case GLUT_KEY_LEFT:
            left_right -= 0.03;
            rotate_camera(left_right);
            break;

        case GLUT_KEY_UP:
            move_camera(0.02);
            break;

        case GLUT_KEY_DOWN:
            move_camera(-0.02);
            break;

        default:
            break;
    }

    glutPostRedisplay();
    glutSwapBuffers();

}

/* Fonction de gestion du clavier special */
void SpecialUp_key(int key, int x, int y) {

    glutPostRedisplay();
    glutSwapBuffers();

}

/* Fonction de gestion du clavier special */
void Special_click(int button, int state, int x, int y) {

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        // Attacking pokemons    
        squirtle->attack(electrode);
    }

    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {

    }

}

/* Gestion du déplacement de la caméra  */
void move_camera(double speed) {
    vect_x = cam_look_x - cam_pos_x;
    vect_z = cam_look_z - cam_pos_z;

    cam_pos_x += vect_x * speed;
    cam_pos_z += vect_z * speed;

    cam_look_x += vect_x * speed;
    cam_look_z += vect_z * speed;
}

/* Gestion de l'orientation de la caméra */
void rotate_camera(double speed) {
    vect_x = cam_look_x - cam_pos_x;
    vect_z = cam_look_z - cam_pos_z;

    // Calculate the sine and cosine of the angle once
    float cosTheta = (float) cos(speed);
    float sinTheta = (float) sin(speed);

    double new_x = sqrt(pow(vect_x, 2) + pow(vect_z, 2)) * cosTheta;
    double new_z = sqrt(pow(vect_x, 2) + pow(vect_z, 2)) * sinTheta;

    cam_look_x = cam_pos_x + new_x;
    cam_look_z = cam_pos_z + new_z;
}

void InitDynamicParam() {

    // Loading environment
    // Land
    land = new Land();
    lake = new Lake();

    // Loading pokemons
    // Squirtle
    squirtle = new Squirtle(dt, "models/Squirtle/Squirtle.obj");
    // Electrode
    electrode = new Electrode(dt, "models/Electrode/Electrode.obj");

    //
    objects.push_back(land);
    objects.push_back(lake);
    objects.push_back(squirtle);
    objects.push_back(electrode);

    // Loading attacks
    bubble = new Bubble(dt, vec3(-4.25, 3.45, 28.05));
    squirtle->attacks = bubbles = new Bubbles(dt, 50, vec3(-4.25, 3.45, 28.05));

}

/* Défintion de la fonction IDLE */
void idle_function() {

    for (int i = 0; i < objects.size(); i++) {
        objects[i]->idle();
    }

}

int main(int argc, char **argv) {

    /* Initialize GLUT state - glut will take any command line arguments that pertain to it or 
       X Windows - look at its documentation at http://reality.sgi.com/mjk/spec3/spec3.html */
    glutInit(&argc, argv);

    /*  Activation des buffers :   
       Double buffer 
       RGBA color
       Alpha
       Depth buffer */
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);

    /* Création de la fenêtre */
    glutInitWindowSize(640, 480);

    /* Positionnement de la fenêtre */
    glutInitWindowPosition(0, 0);

    /* Ouverture de la fenêtre */
    window = glutCreateWindow("Pokemon Battle");

    /* Spécification de la fonction de dessin */
    glutDisplayFunc(&DrawGLScene);

    /* Spécification de la routine de fond */

    glutIdleFunc(idle_function);

    /* Spécification de la fonction de redimensionnement */
    glutReshapeFunc(&ReSizeGLScene);

    /* Spécification de la fonction de de gestion du clavier */
    glutKeyboardFunc(&keyPressed);

    /* Spécification de la fonction de de gestion du clavier */
    glutKeyboardUpFunc(&keyReleased);

    /* Spécification de la fonction special de gestion du clavier */
    glutSpecialFunc(Special_key);

    /* Spécification de la fonction special de gestion du clavier */
    glutSpecialUpFunc(SpecialUp_key);

    /* Spécification de la fonction special de gestion de la souris */
    glutMouseFunc(Special_click);

    /* Intitialisation des paramètres de l'affichage et de la fenêtre */
    InitGL(640, 480);

    /* Lancement de la boucle OpenGL */
    glutMainLoop();

    return 1;
}

