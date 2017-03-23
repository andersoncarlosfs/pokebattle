/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   explosion.cpp
 * Author: deboramorita
 * 
 * Created on March 23, 2017, 3:45 PM
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

#include "explosion.h"

Explosion::Explosion(double time, vec3 position, double size) : Particle(time, position, size) {

    float angle = ((60.0 + (70.0 - 60.0) * rand()) * atan(1) * 4) / 180.0;

    float velocity = 2 - (rand() % 5);

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

Explosion::~Explosion() {
}

void Explosion::idle() {

    if ((this->active == true) && (this->lifetime > 0.0)) {

        Mover::idle();

        this->lifetime -= this->decay;

        this->position.x += cos(this->direction);
        this->position.y += atan(this->direction);
        ;
        this->position.z += sin(this->direction);

    } else {

        this->active = false;

    }

}

void Explosion::draw() {

    if ((this->active == true) && (this->lifetime > 0.0)) {
        glPushMatrix();
        this->material.apply();
        glBegin(GL_TRIANGLE_STRIP);
        glVertex3f(this->position.x + this->size, this->position.y + this->size, this->position.z); // top    right
        glVertex3f(this->position.x - this->size, this->position.y + this->size, this->position.z); // top    left
        glVertex3f(this->position.x + this->size, this->position.y - this->size, this->position.z); // bottom right
        glVertex3f(this->position.x - this->size, this->position.y - this->size, this->position.z); // bottom left
        glEnd();
        glPopMatrix();
    }

}

void Explosion::collisionDetection() {

    if (this->position.y < this->size) {

        this->active = false;

    }

}