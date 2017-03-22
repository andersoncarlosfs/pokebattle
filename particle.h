//https://github.com/krlgrgn/OpenGL-Particles
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   particle.h
 * Author: deboramorita
 *
 * Created on March 20, 2017, 10:55 PM
 */

#ifndef PARTICLE_H
#define PARTICLE_H

#include "Mover.h"

class Particle : public Mover {
public:
    float lifetime;
    float decay;
    double size;
    Particle(double, vec3);
    virtual ~Particle();
    void idle();
    void draw();
    void collisionDetection();
private:
};

#endif /* PARTICLE_H */

