/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   pokemon.h
 * Author: lsdfusion
 *
 * Created on 10 March 2017, 14:03
 */

#ifndef POKEMON_H
#define POKEMON_H

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#else
#include <GL/gl.h> 
#endif

#include <vector>

#include "glm.h"

#include "mover.h"
#include "attack.h"
#include "explosion.h"

/*
using namespace std;
 */

class Attack;

class Pokemon : public Mover {
public:
    GLMmodel* model;
    Attack* attacks;
    Pokemon(double, char*);
    virtual ~Pokemon();
    virtual void draw();
    void idle();
    void collisionDetection();
    virtual void attack(Pokemon*);
    virtual void defend(bool) = 0;
    virtual void die();
    virtual bool isAttacking();
    virtual bool isDefending() = 0;
private:
    /*
       vector<vec3> vertexes;
       vector<vec2> textures;
       vector<vec3> normals;
       vector<GLushort> faces;
     */
    vector<Explosion> particles;
};

#endif /* POKEMON_H */

