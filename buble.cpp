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

#include <cmath>

#include "buble.h"

using namespace std;

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

    this->acceleration_i.x = 0;
    this->acceleration_i.y = -Mover::gravity;
    this->acceleration_i.z = 0;

    this->damping = 0.8;

}

Buble::~Buble() {
}

void Buble::draw() {

    Attack::draw();

    if (particles.size() == 0) {
        glPushMatrix();
        this->material.apply();
        glTranslatef(this->position.x, this->position.y, this->position.z);
        glutSolidSphere(0.3, 50, 50);
        glPopMatrix();
    } else {
        for (int i = 0; i < particles.size(); i++) {
            particles[i].draw();
        }
    }

}

void Buble::idle() {
   
    if (particles.size() == 0) {
        Attack::idle();
    } else {
        bool active = false;
        for (int i = 0; i < particles.size(); i++) {
            particles[i].idle();
            active |= particles[i].active;
        }
        this->active = active;
    }
    
}

void Buble::collisionDetection() {

    Attack::collisionDetection();

    bool explode = false;

    if (this->position.y < 0.3) {

        explode = true;

    }

    if ((sqrt(pow((this->position.x - (this->target->position.x * this->target->scale.x)), 2)
            + pow((this->position.y - (this->target->position.y * this->target->scale.y)), 2)
            + pow((this->position.z - (this->target->position.z * this->target->scale.z)), 2)))
            < (2 * 0.3)) {

        explode = true;

    }

    if (explode) {
        for (int i = 0; i < 250; i++) {
            particles.push_back(Particle(this->time, this->position));
        }
    }

}
