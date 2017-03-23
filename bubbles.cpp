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
#include <iostream>
#include "bubbles.h"

using namespace std;

Bubbles::Bubbles(double time, int size, vec3 position) : Attack(time) {

    for (int i = 0; i < size; i++) {
        this->bubbles.push_back(Bubble(time, position));
    }

}

Bubbles::~Bubbles() {
}

void Bubbles::draw() {

    for (int i = 0; i < bubbles.size(); i++) {
        this->bubbles[i].draw();
    }

}

void Bubbles::idle() {

    for (int i = 0; i < bubbles.size(); i++) {
        this->bubbles[i].idle();
    }

}

void Bubbles::collisionDetection() {

}

void Bubbles::reset() {

    if (!this->active) {
        for (int i = 0; i < bubbles.size(); i++) {
            this->bubbles[i].target = this->target;
            this->bubbles[i].reset();
            this->bubbles[i].size = ((rand() % 9) / 10.0) + 0.1;
            this->bubbles[i].size_s = ((rand() % 9) / 10.0) + 0.1;
            this->bubbles[i].velocity_i.y = (rand() % 19) + 11;
            this->bubbles[i].velocity_i.x = (rand() % 19) + 11;
            this->bubbles[i].velocity_i.z = ((rand() % 30) + 15) * (-1);
            this->bubbles[i].active = true;
        }
    }

}
