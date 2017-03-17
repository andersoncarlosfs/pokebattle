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

const float Buble::damping = 0;

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
    this->velocity_i.x = 25;
    this->velocity_i.z = -35;

    this->acceleration.y = 0;
    this->acceleration.x = 0;
    this->acceleration.z = 0;

    this->acceleration_i.y = 0;
    this->acceleration_i.x = -Mover::gravity;
    this->acceleration_i.z = 0;

}

Buble::~Buble() {
}

void Buble::draw() {
    glPushMatrix();
    this->material.apply();
    glutSolidSphere(0.3, 50, 50);
    glPopMatrix();
}

void Buble::idle() {

    /*
    ////////////////////////////////////
    // Numerical integration

    sphere_vx = sphere_ivx + (sphere_iax * dt);
    sphere_vy = sphere_ivy + (sphere_iay * dt);
    sphere_vz = sphere_ivz + (sphere_iaz * dt);

    sphere_x = sphere_ix + (sphere_vx * dt);
    sphere_y = sphere_iy + (sphere_vy * dt);
    sphere_z = sphere_iz + (sphere_vz * dt);

    ////////////////////////////////////
    // Collision test

    if (sphere_y < 0.3) {
        sphere_y = sphere_iy;
        sphere_vy = -sphere_vy;
    }

    ////////////////////////////////////
    // Acceleration calculation: ajouter la viscosité

    sphere_ax = -(sphere_vx * B);
    sphere_ay = -G - (sphere_vy * B);
    sphere_az = -(sphere_vz * B);

    ////////////////////////////////////
    // System update

    sphere_iax = sphere_ax;
    sphere_iay = sphere_ay;
    sphere_iaz = sphere_az;

    sphere_ivx = sphere_vx;
    sphere_ivy = sphere_vy;
    sphere_ivz = sphere_vz;

    sphere_ix = sphere_x;
    sphere_iy = sphere_y;
    sphere_iz = sphere_z;

    ////////////////////////////////////
     */
}
