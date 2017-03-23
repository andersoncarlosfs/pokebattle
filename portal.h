/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   portal.h
 * Author: deboramorita
 *
 * Created on March 23, 2017, 8:12 PM
 */

#ifndef PORTAL_H
#define PORTAL_H

#include "object.h"

class Portal : public Object {
public:
    Portal(vec3, vec3);
    virtual ~Portal();
    void draw();
    void idle();
private:
    float inner;
    float outter;
    float axis;
    float increment;
};

#endif /* PORTAL_H */

