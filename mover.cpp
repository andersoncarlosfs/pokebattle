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

Mover::Mover(double time) {
    this->time = time;
}

Mover::~Mover() {
}

