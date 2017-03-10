/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pokemon.h
 * Author: lsdfusion
 *
 * Created on 10 March 2017, 14:03
 */

#ifndef POKEMON_H
#define POKEMON_H

#include <vector>       // std::vector

#include <GL/gl.h>      // OpenGL
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4

using namespace std;

using namespace glm;

class Pokemon {
public:
    vector<vec3> vertexes;
    vector<vec2> textures;
    vector<vec3> normals;
    vector<vec3> faces;
    vector<GLushort> elements;
    Pokemon();
    Pokemon(const Pokemon&);
    virtual ~Pokemon();
    void load(const char*);
private:

};

#endif /* POKEMON_H */

