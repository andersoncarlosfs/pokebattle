//https://github.com/krlgrgn/OpenGL-Particles
//ftp://ftp.sgi.com/sgi/opengl/contrib/mjk/tips/particles/index.html
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
    float direction;
    double size;
    Particle(double, vec3, double);
    virtual ~Particle();
    virtual void idle();
    virtual void draw();
    virtual void collisionDetection();
private:
};

#endif /* PARTICLE_H */

