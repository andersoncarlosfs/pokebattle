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

#include "buble.h"

const float Buble::damping = 0;

Buble::Buble(vec3 position) {


    this->material = Material::white;

    this->scale.x = 1;
    this->scale.y = 1;
    this->scale.z = 1;

    this->position.x = -1.2;
    this->position.y = 1;
    this->position.z = 6;

    this->position_i.x = -1.2;
    this->position_i.y = 1;
    this->position_i.z = 6;

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
    this->acceleration_i.x = - Mover::gravity;
    this->acceleration_i.z = 0;

}

Buble::~Buble() {
}

void Buble::draw() {
    glPushMatrix();
    this->material.apply();

    glPopMatrix();
}
