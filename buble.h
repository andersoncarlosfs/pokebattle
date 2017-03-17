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

#ifndef BUBLE_H
#define BUBLE_H

#include "attack.h"

class Buble : public Attack {
public:
    static const float damping;
    Buble(double, vec3 position);
    virtual ~Buble();
    void draw();
    void idle();
private:
};

#endif /* BUBLE_H */

