/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   portal.cpp
 * Author: deboramorita
 * 
 * Created on March 23, 2017, 8:12 PM
 */

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>   
#include <GLUT/glut.h>
#else
#include <GL/gl.h> 
#include <GL/glut.h>   
#endif

#include <cmath>

#include "portal.h"

Portal::Portal(vec3 dimensions, vec3 position) {

    this->material = Material::tin;
    
    this->position = position;

    this->rotation.x = 0;
    this->rotation.y = 0;
    this->rotation.z = 0;
    this->rotation.w = 15;

    float sin = std::sin(this->rotation.w * (atan(1) * 4) / 360);

    this->inner = 0.5;

    this->outter = max(dimensions.x, max(dimensions.y, dimensions.z)) + 2;
    
    this->position.y = (2 * this->outter + this->inner) * sin + this->inner + ((1 - sin) * this->inner) - (this->inner * 1 / 10);    

    this->axis = 0;

    this->increment = 2 * (atan(1) * 4) / 30;

}

Portal::~Portal() {
}

void Portal::draw() {

    this->rotation.x = sin(this->axis);
    this->rotation.z = cos(this->axis);

    glPushMatrix();
    this->material.apply();
    glPushMatrix();
    glTranslatef(this->position.x, 3 * this->position.y, this->position.z);
    glRotatef(this->rotation.w, this->rotation.x, this->rotation.y, this->rotation.z);
    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    glutSolidTorus(this->inner, this->outter, 15, 25);
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(this->position.x, 2 * this->position.y, this->position.z);
    glRotatef(-this->rotation.w, this->rotation.x, this->rotation.y, this->rotation.z);
    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    glutSolidTorus(this->inner, this->outter, 15, 25);
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(this->position.x, this->position.y, this->position.z);
    glRotatef(this->rotation.w, this->rotation.x, this->rotation.y, this->rotation.z);
    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    glutSolidTorus(this->inner, this->outter, 15, 25);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

}

void Portal::idle() {
    this->axis += this->increment;
}


