/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   color.cpp
 * Author: deboramorita
 * 
 * Created on March 16, 2017, 6:25 PM
 */

#include <algorithm>

#include "material.h"

Material::Material::Material() {
}

Material::Material::Material(const GLfloat* specular, const GLfloat* ambient, const GLfloat* diffuse, const GLfloat* shininess) {
    copy(specular, specular + 4, back_inserter(this->specular));
    copy(ambient, ambient + 4, back_inserter(this->ambient));
    copy(diffuse, diffuse + 4, back_inserter(this->diffuse));
    copy(shininess, shininess + 1, back_inserter(this->shininess));
}

Material::Material::~Material() {
}

