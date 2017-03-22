/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   mover.cpp
 * Author: lsdfusion
 * 
 * Created on 17 March 2017, 10:48
 */

#include "mover.h"

const float Mover::gravity = 9.8; // m/s^2

Mover::Mover(double time) : Object() {
    
    this->active = true;
    
    this->time = time;
    
}

Mover::~Mover() {
}

void Mover::idle() {

    ////////////////////////////////////
    // Numerical integration

    this->velocity.x = this->velocity_i.x + (this->acceleration_i.x * this->time);
    this->velocity.y = this->velocity_i.y + (this->acceleration_i.y * this->time);
    this->velocity.z = this->velocity_i.z + (this->acceleration_i.z * this->time);

    this->position.x = this->position_i.x + (this->velocity.x * this->time);
    this->position.y = this->position_i.y + (this->velocity.y * this->time);
    this->position.z = this->position_i.z + (this->velocity.z * this->time);

    ////////////////////////////////////
    // Collision test

    this->collisionDetection();

    ////////////////////////////////////
    // Acceleration calculation: ajouter la viscosité

    this->acceleration.x = -(this->velocity.x * this->damping);
    this->acceleration.y = -Mover::gravity - (this->velocity.y * this->damping);
    this->acceleration.z = -(this->velocity.z * this->damping);

    ////////////////////////////////////
    // System update

    this->acceleration_i.x = this->acceleration.x;
    this->acceleration_i.y = this->acceleration.y;
    this->acceleration_i.z = this->acceleration.z;

    this->velocity_i.x = this->velocity.x;
    this->velocity_i.y = this->velocity.y;
    this->velocity_i.z = this->velocity.z;

    this->position_i.x = this->position.x;
    this->position_i.y = this->position.y;
    this->position_i.z = this->position.z;

    ////////////////////////////////////

}

