/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   color.h
 * Author: deboramorita
 *
 * Created on March 16, 2017, 6:25 PM
 */

#ifndef MATERIAL_H
#define MATERIAL_H

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#else
#include <GL/gl.h>  
#endif

#include <vector>

using namespace std;

namespace Material {

    class Material {
    public:
        vector<GLfloat> specular;
        vector<GLfloat> ambient;
        vector<GLfloat> diffuse;
        vector<GLfloat> shininess;
        Material();
        Material(const GLfloat*, const GLfloat*, const GLfloat*, const GLfloat*);
        virtual ~Material();
    private:
    };

    const Material blue((GLfloat[]){0.75, 0.75, 0.75, 1}, (GLfloat[]) {0, 0, 1, 1}, (GLfloat[]) {0.5, 0.5, 0.5, 1}, (GLfloat[]) {128});
    const Material yellow((GLfloat[]){0.75, 0.75, 0.75, 1.0}, (GLfloat[]) {1, 1, 0, 1}, (GLfloat[]) {0.5, 0.5, 0.5, 1}, (GLfloat[]) {128});

}
#endif /* MATERIAL_H */
