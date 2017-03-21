/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   particle.cpp
 * Author: deboramorita
 * 
 * Created on March 20, 2017, 10:55 PM
 */

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>  
#include <GLUT/glut.h>
#else
#include <GL/gl.h> 
#include <GL/glut.h>   
#endif

#include <cstdlib>

#include "particle.h"

Particle::Particle(double time, vec3 position) : Mover(time) {

    this->material = Material::white;

    this->scale.x = 1;
    this->scale.y = 1;
    this->scale.z = 1;

    this->position = position;

    this->position_i = position;

    this->velocity.y = 0;
    this->velocity.x = 0;
    this->velocity.z = 0;

    this->velocity_i.x = rand() % 10 + (-4);
    this->velocity_i.y = rand() % 10 + (-4);
    this->velocity_i.z = rand() % 10 + (-4);

    this->acceleration.y = 0;
    this->acceleration.x = 0;
    this->acceleration.z = 0;

    this->acceleration_i.x = 0;
    this->acceleration_i.y = -Mover::gravity * (rand() % 1 + (0.4));
    this->acceleration_i.z = 0;

    this->damping = 0.8;

    this->active = true;

    this->lifetime = rand() % 100;

    this->decay = 1;

}

Particle::~Particle() {
}

void Particle::idle() {

    if ((this->active == true) && (this->lifetime > 0.0)) {

        Mover::idle();

        this->lifetime -= this->decay;

        this->position.x += rand() % 10 + (-4);
        this->position.y += rand() % 10 + (-4);
        this->position.z += rand() % 10 + (-4);

        this->velocity.x += rand() % 10 + (-4);
        this->velocity.y += rand() % 10 + (-4);
        this->velocity.z += rand() % 10 + (-4);

    } else {

        this->active = false;

    }

}

void Particle::draw() {

    if ((this->active == true) && (this->lifetime > 0.0)) {
        glPushMatrix();
        this->material.apply();
        glScalef(this->scale.x, this->scale.y, this->scale.z);
        glTranslatef(this->position.x, this->position.y, this->position.z);
        glutSolidSphere(0.2, 50, 50);
        glPopMatrix();
    }

}

void Particle::collisionDetection() {
    
    if (this->position.y < 0.2) {

        this->active = false;

    }
    
}