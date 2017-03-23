/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   land.h
 * Author: deboramorita
 *
 * Created on March 23, 2017, 2:17 AM
 */

#ifndef PLOT_H
#define PLOT_H

#include "object.h"

class Land : public Object {
public:
    Land();
    virtual ~Land();
    void draw();
    void idle();
private:
};

#endif /* PLOT_H */

