//http://stackoverflow.com/questions/23710829/why-is-my-obj-parser-rendering-meshes-like-this
//http://www.opengl-tutorial.org/beginners-tutorials/tutorial-7-model-loading/
//https://en.wikibooks.org/wiki/OpenGL_Programming/Modern_OpenGL_Tutorial_Load_OBJ
//https://en.wikibooks.org/wiki/OpenGL_Programming/Modern_OpenGL_Tutorial_Load_OBJ
//https://www.d.umn.edu/~ddunham/cs5721f07/schedule/resources/lab_opengl07.html
//http://netization.blogspot.fr/2014/10/loading-obj-files-in-opengl.html

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pokemon.cpp
 * Author: lsdfusion
 * 
 * Created on 10 March 2017, 14:03
 */

#include "Pokemon.h"

#include <iostream>     // std::iostream
#include <fstream>      // std::iostream
#include <string>       // std::string
#include <regex>        // std::regex

const regex comment("^(\\s*)?(#)");
const regex vertex("^(\\s*)?(v\\s)");
const regex element("^(\\s*)?(f\\s)");

Pokemon::Pokemon() {
}

Pokemon::Pokemon(const Pokemon& pokemon) {
}

Pokemon::~Pokemon() {
}

void Pokemon::load(const char* file) {
    ifstream stream(file, ios::in);
    if (stream.is_open()) {
        string line;
        while (stream.good()) {
            if (regex_search(line, comment)) {
                continue;
            }
            if (regex_search(line, vertex)) {
                vec3 vertex;
                
                continue;
            }
            if (regex_search(line, element)) {
                continue;
            }
        }
    } else {
        cout << "Can not open the file" << endl;
    }
}
