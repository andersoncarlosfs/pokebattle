/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   buble.cpp
 * Author: deboramorita
 * 
 * Created on March 16, 2017, 11:16 PM
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h> 
#endif

#include "buble.h"

Buble::Buble(double time, vec3 position) : Attack(time) {

    this->material = Material::white;

    this->scale.x = 1;
    this->scale.y = 1;
    this->scale.z = 1;

    this->position = position;

    this->position_i = position;

    this->velocity.y = 0;
    this->velocity.x = 0;
    this->velocity.z = 0;

    this->velocity_i.y = 20;
    this->velocity_i.x = 20;
    this->velocity_i.z = -35;

    this->acceleration.y = 0;
    this->acceleration.x = 0;
    this->acceleration.z = 0;

    this->acceleration_i.y = 0;
    this->acceleration_i.x = -Mover::gravity;
    this->acceleration_i.z = 0;
    
    this->damping = 0.8;

}

Buble::~Buble() {
}

void Buble::draw() {
    Attack::draw();
    glPushMatrix();
    this->material.apply();
    glTranslatef(this->position.x, this->position.y, this->position.z);
    glutSolidSphere(0.3, 50, 50);
    glPopMatrix();
}

void Buble::collisionDetection() {
    if (this->position.y < 0.3) {
        this->position.y = this->position_i.y;
        this->velocity.y = -this->velocity.y;
    }
}
