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
#include <cmath>

#include "particle.h"

Particle::Particle(double time, vec3 position, double size) : Mover(time) {

    float angle = ((60.0 + (70.0 - 60.0) * rand()) * atan(1) * 4) / 180.0;

    float velocity = (rand() % 10 + (-4));
    
    this->material = Material::white;

    this->scale.x = 1;
    this->scale.y = 1;
    this->scale.z = 1;

    this->position = position;

    this->position_i = position;

    this->velocity.y = 0;
    this->velocity.x = 0;
    this->velocity.z = 0;

    this->velocity_i.x = velocity * cos(angle);
    this->velocity_i.y = velocity * atan(angle);
    this->velocity_i.z = velocity * sin(angle);

    this->acceleration.y = 0;
    this->acceleration.x = 0;
    this->acceleration.z = 0;

    this->acceleration_i.x = 0;
    this->acceleration_i.y = -Mover::gravity * (rand() % 1 + (0.4));
    this->acceleration_i.z = 0;

    this->damping = 0.8;

    this->active = true;
    
    this->lifetime = rand() % 99 + 1;

    this->decay = fmod(rand(), this->lifetime * 0.5) + 1;
    
    this->direction = ((0.0 + (360.0 - 0.0) * rand()) * atan(1) * 4) / 180.0;

    this->size = fmod(rand(), (size / 4.0)) + 0.001;

}

Particle::~Particle() {
}

void Particle::idle() {

    if ((this->active == true) && (this->lifetime > 0.0)) {

        Mover::idle();

        this->lifetime -= this->decay;

        this->position.x += cos(this->direction);
        this->position.y += 0;
        this->position.z += sin(this->direction);
        
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
        glutSolidSphere(this->size, 50, 50);
        glPopMatrix();
    }

}

void Particle::collisionDetection() {

    if (this->position.y < 0.2) {

        this->active = false;

    }

}