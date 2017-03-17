/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   attack.h
 * Author: deboramorita
 *
 * Created on March 16, 2017, 11:15 PM
 */

#ifndef ATTACK_H
#define ATTACK_H

#include "mover.h"

class Attack : public Mover {
public:
    Attack(double);
    virtual ~Attack();
private:
};

#endif /* ATTACK_H */

