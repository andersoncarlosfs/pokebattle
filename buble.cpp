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
#include <iostream>

void Buble::collisionDetection() {

    Attack::collisionDetection();

    if (this->position.y < 0.3) {

        this->active = false;

        return;

    }

    cout << "x\t" << this->position.x << "\t" << this->target->position.x * this->target->scale.x << endl;
    cout << "y\t" << this->position.y << "\t" << this->target->position.y * this->target->scale.y << endl;
    cout << "z\t" << this->position.z << "\t" << this->target->position.z * this->target->scale.z << endl;
    cout << "v\t" << sqrt(pow((this->position.x - (this->target->position.x * this->target->scale.x)), 2)
            + pow((this->position.y - (this->target->position.y * this->target->scale.y)), 2)
            + pow((this->position.z - (this->target->position.z * this->target->scale.z)), 2)) << endl;

    if ((sqrt(pow((this->position.x - (this->target->position.x * this->target->scale.x)), 2)
            + pow((this->position.y - (this->target->position.y * this->target->scale.y)), 2)
            + pow((this->position.z - (this->target->position.z * this->target->scale.z)), 2)))
            < (2 * 0.3)) {

        this->active = false;


        cout << "Buble\t" << true << endl;

        return;

    }

}
