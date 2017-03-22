/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   bubles.h
 * Author: deboramorita
 *
 * Created on March 16, 2017, 11:16 PM
 */

#ifndef BUBBLES_H
#define BUBBLES_H

#include "attack.h"
#include "bubble.h"

class Bubbles : public Attack {
public:        
    Bubbles(double, int, vec3);
    virtual ~Bubbles();
    void draw();
    void idle();
    void collisionDetection();
    void reset();
private:
    vector<Bubble> bubbles;
};

#endif /* BUBBLES_H */

