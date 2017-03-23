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
        void apply();
    private:
    };

    // Defining materials
    const Material white((GLfloat[]){1, 1, 1, 1}, (GLfloat[]) {1, 1, 1, 1}, (GLfloat[]) {1, 1, 1, 1}, (GLfloat[]) {128 * 0.4});
    const Material grey((GLfloat[]){0.75, 0.75, 0.75, 1}, (GLfloat[]) {0.5, 0.5, 0.5, 1.0}, (GLfloat[]) {0.5, 0.5, 0.5, 1}, (GLfloat[]) {128 * 0.6});
    const Material blue((GLfloat[]){0.75, 0.75, 0.75, 1}, (GLfloat[]) {0, 0, 1, 1}, (GLfloat[]) {0.5, 0.5, 0.5, 1}, (GLfloat[]) {128});
    const Material green((GLfloat[]){0.633, 0.727811, 0.633, 1}, (GLfloat[]) {0.0215, 0.1745, 0.0215, 1}, (GLfloat[]) {0.07568, 0.61424, 0.07568, 1}, (GLfloat[]) {128});
    const Material yellow((GLfloat[]){0.75, 0.75, 0.75, 1.0}, (GLfloat[]) {1, 1, 0, 1}, (GLfloat[]) {0.5, 0.5, 0.5, 1}, (GLfloat[]) {128});
    const Material red((GLfloat[]){0.75, 0.75, 0.75, 1.0}, (GLfloat[]) {1, 0, 0, 1}, (GLfloat[]) {0.8, 0.5, 0.5, 1}, (GLfloat[]) {128});
    const Material bronze((GLfloat[]){0.774597, 0.458561, 0.200621, 1.0}, (GLfloat[]) {0.25, 0.148, 0.06475, 1}, (GLfloat[]) {0.4, 0.2368, 0.1036, 1}, (GLfloat[]) {76.8});
    
}
#endif /* MATERIAL_H */
