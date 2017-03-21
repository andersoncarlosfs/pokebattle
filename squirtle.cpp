/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   squirtle.cpp
 * Author: deboramorita
 * 
 * Created on March 15, 2017, 1:41 AM
 */

#include "squirtle.h"
#include "bubble.h"

Squirtle::Squirtle(double time, char* file) : Pokemon(time, file) {

    this->material = Material::blue;

    this->scale.x = 5;
    this->scale.y = 5;
    this->scale.z = 5;

    this->position.x = -1.2;
    this->position.y = 1;
    this->position.z = 6;

    this->rotation.x = 0;
    this->rotation.y = 1;
    this->rotation.z = 0;
    this->rotation.w = 135;

}

Squirtle::~Squirtle() {
}

