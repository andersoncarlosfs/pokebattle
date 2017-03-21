/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   mover.h
 * Author: lsdfusion
 *
 * Created on 17 March 2017, 10:48
 */

#ifndef MOVER_H
#define MOVER_H

#include "object.h"

class Mover : public Object {
public:
    static const float gravity; // m/s^2
    float damping;
    double time;
    vec3 position_i;
    vec3 velocity_i;
    vec3 acceleration_i;
    bool active;
    Mover(double);
    virtual ~Mover();
    virtual void idle();
    virtual void collisionDetection() = 0;
private:
};

#endif /* MOVER_H */

