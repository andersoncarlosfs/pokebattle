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

#include "bubble.h"

using namespace std;

Bubble::Bubble(double time, vec3 position) : Attack(time) {

    this->material = Material::white;

    this->scale.x = 1;
    this->scale.y = 1;
    this->scale.z = 1;

    this->position_s = this->position_i = this->position = position;

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
    
    this->size = ((rand() % 4) / 10.0) + 0.1;

}

Bubble::~Bubble() {
}

void Bubble::draw() {

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

void Bubble::idle() {

    if (particles.size() == 0) {
        Attack::idle();
    } else {
        bool active = false;
        for (int i = 0; i < particles.size(); i++) {
            particles[i].idle();
            active |= particles[i].active;
        }
        this->active = active;
        if (!this->active) {
            this->particles.clear();
        }
    }

}

void Bubble::collisionDetection() {

    if (this->size < 0.5) {

        this->size += ((rand() % 49) / 100.0) + 0.01;

    }
    
    if (particles.size() != 0) {
        return;
    }

    if (this->position.y < 0.5) {

        this->active = false;

    }

    Attack::collisionDetection();

    float radius = max(this->target->dimensions.x, max(this->target->dimensions.y, this->target->dimensions.z)) * 0.5;

    if ((sqrt(pow((this->position.x - (this->target->position.x)), 2)
            + pow((this->position.y - (this->target->position.y + this->target->dimensions.y * 0.5)), 2)
            + pow((this->position.z - (this->target->position.z)), 2)))
            < (radius - this->size)) {

        for (int i = 0; i < 500; i++) {
            particles.push_back(Particle(this->time, this->position));
        }

    }

}

void Bubble::reset() {

    if (!this->active) {
        this->material = Material::white;

        this->scale.x = 1;
        this->scale.y = 1;
        this->scale.z = 1;

        this->position_i = this->position = this->position_s;

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

        this->particles.clear();
    }
}
