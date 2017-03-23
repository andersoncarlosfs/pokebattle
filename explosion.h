/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   explosion.h
 * Author: deboramorita
 *
 * Created on March 23, 2017, 3:45 PM
 */

#ifndef EXPLOSION_H
#define EXPLOSION_H

#include "particle.h"

class Explosion : public Particle {
public:
    Explosion(double, vec3, double, Material::Material);
    virtual ~Explosion();
    void idle();
    void draw();
    void collisionDetection();
private:
};

#endif /* EXPLOSION_H */

