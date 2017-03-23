/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   land.cpp
 * Author: deboramorita
 * 
 * Created on March 23, 2017, 2:17 AM
 */

#ifdef __APPLE__
#include <OpenGL/OpenGL.h> 
#include <GLUT/glut.h>
#else
#include <GL/gl.h> 
#include <GL/glut.h>   
#endif

#include "land.h"

Land::Land() {
    this->material = Material::yellow;
}

Land::~Land() {
}

void Land::draw() {
    glPushMatrix();
    this->material.apply();
    for (int i = -50; i <= 15; i += 5) {
        // Start drawing some lines
        glBegin(GL_LINES);

        // Do the horizontal lines (along the X)
        glVertex3f(-50, 0, i);
        glVertex3f(50, 0, i);

        // Stop drawing lines
        glEnd();
    }
    for (int i = -50; i <= 50; i += 5) {
        // Start drawing some lines
        glBegin(GL_LINES);

        // Do the vertical lines (along the Z)
        glVertex3f(i, 0, -50);
        glVertex3f(i, 0, 15);

        // Stop drawing lines
        glEnd();
    }
    glPopMatrix();
}

void Land::idle() {

}
