/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   buble.h
 * Author: deboramorita
 *
 * Created on March 16, 2017, 11:16 PM
 */

#ifndef BUBBLE_H
#define BUBBLE_H

#include "attack.h"
#include "particle.h"

class Bubble : public Attack {
public:
    double size;
    double size_s;
    Bubble(double, vec3);
    virtual ~Bubble();
    void draw();
    void idle();
    void collisionDetection();
    void explode();
    void reset();
private:
    vec3 position_s;    
    vector<Particle> particles;
};

#endif /* BUBBLE_H */

