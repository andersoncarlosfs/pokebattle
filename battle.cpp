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

#include "pokemon.h"
#include "squirtle.h"
#include "electrode.h"
#include "bubble.h"

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
vector<Pokemon*> pokemons;

//
Pokemon* squirtle;
Pokemon* electrode;

//
Attack* bubble;

// Pas de temps
double dt = 0.01;

/* code ASCII pour la touche escape*/
#define ESCAPE 27

/* Idantifiant de la fenêtre GLUT */
int window;

/* Déclaration des en-têtes */

void Draw3DSGrid();
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


    // Dessin de la grille
    glPushMatrix();
    Draw3DSGrid();
    glPopMatrix();

    //////////////////////////////////////////////////

    for (int i = 0; i < pokemons.size(); i++) {

        pokemons[i]->draw();
        // Attacking pokemons

    }

    // Permutation des buffers
    glutPostRedisplay();
    glutSwapBuffers();
}

/* Fonction de gestion du clavier */
void keyPressed(unsigned char key, int x, int y) {

    if (key == ESCAPE) {
        /* Eteindre la fenêtre */
        glutDestroyWindow(window);

        /* Sortire du programme */
        exit(0);
    }
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
            
        case 'r':
            
            bubble->reset();

        default:
            break;
    }

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

/* Dessin d'une grille 3D */
void Draw3DSGrid() {

    glMaterialfv(GL_FRONT, GL_SPECULAR, Material::yellow.specular.data());
    glMaterialfv(GL_FRONT, GL_SHININESS, Material::yellow.shininess.data());
    glMaterialfv(GL_FRONT, GL_AMBIENT, Material::yellow.ambient.data());
    glMaterialfv(GL_FRONT, GL_DIFFUSE, Material::yellow.diffuse.data());

    // Draw a 1x1 grid along the X and Z axis'
    float i;
    for (i = -50; i <= 50; i += 5) {
        // Start drawing some lines
        glBegin(GL_LINES);

        // Do the horizontal lines (along the X)
        glVertex3f(-50, 0, i);
        glVertex3f(50, 0, i);

        // Do the vertical lines (along the Z)
        glVertex3f(i, 0, -50);
        glVertex3f(i, 0, 50);

        // Stop drawing lines
        glEnd();
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

    // Loading pokemons
    // Squirtle
    squirtle = new Squirtle(dt, "models/Squirtle/Squirtle.obj");
    // Electrode
    electrode = new Electrode(dt, "models/Electrode/Electrode.obj");
    
    //
    pokemons.push_back(squirtle);
    pokemons.push_back(electrode);
    
    // Loading attacks
    squirtle->attacks = bubble = new Bubble(dt, vec3(-4.25, 3.45, 29.05));

}

/* Défintion de la fonction IDLE */
void idle_function() {

    for (int i = 0; i < pokemons.size(); i++) {
        pokemons[i]->idle();
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
    window = glutCreateWindow("TD Animation 3D");

    /* Spécification de la fontion de dessin */
    glutDisplayFunc(&DrawGLScene);

    /* Spécification de la routine de fond */

    glutIdleFunc(idle_function);

    /* Spécification de la fontion de redimensionnement */
    glutReshapeFunc(&ReSizeGLScene);

    /* Spécification de la fontion de de gestion du clavier */
    glutKeyboardFunc(&keyPressed);

    /* Spécification de la fontion special de gestion du clavier */
    glutSpecialFunc(Special_key);

    /* Spécification de la fontion special de gestion de la souris */
    glutMouseFunc(Special_click);

    /* Intitialisation des paramètres de l'affichage et de la fenêtre */
    InitGL(640, 480);

    /* Lancement de la boucle OpenGL */
    glutMainLoop();

    return 1;
}

