/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   lake.cpp
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

#include "lake.h"

Lake::Lake() {
    this->material = Material::white;
}

Lake::~Lake() {
}

void Lake::draw() {
    glPushMatrix();
    this->material.apply();
    for (int i = 15; i <= 50; i += 5) {
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
        glVertex3f(i, 0, 15);
        glVertex3f(i, 0, 50);

        // Stop drawing lines
        glEnd();
    }
    glPopMatrix();
}

void Lake::idle() {

}
