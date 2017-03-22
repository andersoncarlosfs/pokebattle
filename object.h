/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   object.h
 * Author: deboramorita
 *
 * Created on March 16, 2017, 6:17 PM
 */

#ifndef OBJECT_H
#define OBJECT_H

#include "libraries/glm/vec3.hpp"
#include "libraries/glm/vec4.hpp"

#include "material.h"

using namespace glm;

class Object {
public:
    Material::Material material;
    vec3 scale;
    vec3 dimensions;
    vec3 position;
    vec4 rotation;
    vec3 velocity;
    vec3 acceleration;
    Object();
    virtual ~Object();
    virtual void draw() = 0;
    virtual void idle() = 0;
private:
};

#endif /* OBJECT_H */

