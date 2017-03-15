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

Squirtle::Squirtle(char* file) : Pokemon(file) {

    color.x = 0;
    color.y = 0;
    color.z = 1;

    scale.x = 5;
    scale.y = 5;
    scale.z = 5;

    position.x = -1;
    position.y = 1;
    position.z = 6;

}

Squirtle::~Squirtle() {
}

