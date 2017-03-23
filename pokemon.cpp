//https://github.com/ameithor/OpenGL/tree/master/Bubble%20Booble%202D
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   pokemon.cpp
 * Author: lsdfusion
 * 
 * Created on 10 March 2017, 14:03
 */

#include <iostream>     // std::iostream
/*
#include <fstream>      // std::iostream
#include <string>       // std::string
#include <regex>        // std::regex
 */
#include "pokemon.h"
#include "explosion.h"
/*
const regex regex_comment("^(\\s*)?(#)");
const regex regex_vertex("^(\\s*)?(v\\s)");
const regex regex_texture("^(\\s*)?(vt\\s)");
const regex regex_normal("^(\\s*)?(vn\\s)");
const regex regex_face("^(\\s*)?(f\\s)");
//http://stackoverflow.com/questions/15814592/how-do-i-include-negative-decimal-numbers-in-this-regular-expression
const regex regex_numeric("-?\\d*\\.{0,1}\\d+");

const regex_token_iterator<string::iterator> regex_iterator_end;
 */

//https://www.opengl.org/discussion_boards/showthread.php/171931-Loading-OBJ-and-MTL-files
//https://www.opengl.org/discussion_boards/showthread.php/171245-texture-mapping

Pokemon::Pokemon(double time, char* file) : Mover(time) {

    this->model = glmReadOBJ(file);

    //glmUnitize(this->model);
    glmFacetNormals(model);

    //
    GLfloat dimensions[3];

    glmDimensions(model, dimensions);

    this->dimensions.x = dimensions[0];
    this->dimensions.y = dimensions[1];
    this->dimensions.z = dimensions[2];

    this->attacks = 0;

}

/*
//http://stackoverflow.com/questions/23710829/why-is-my-obj-parser-rendering-meshes-like-this
//http://www.opengl-tutorial.org/beginners-tutorials/tutorial-7-model-loading/
//https://en.wikibooks.org/wiki/OpenGL_Programming/Modern_OpenGL_Tutorial_Load_OBJ
//https://www.d.umn.edu/~ddunham/cs5721f07/schedule/resources/lab_opengl07.html
//http://netization.blogspot.fr/2014/10/loading-obj-files-in-opengl.html
//https://www.raywenderlich.com/48293/how-to-export-blender-models-to-opengl-es-part-1
Pokemon::Pokemon(const char* file) {
    ifstream stream(file, ios::in);
    if (stream.is_open()) {
        string line;
        while (getline(stream, line)) {
            if (regex_search(line, regex_comment)) {
                continue;
            }
            regex_token_iterator<std::string::iterator> iterator(line.begin(), line.end(), regex_numeric);
            if (regex_search(line, regex_vertex)) {
                vec3 vertex;
                vertex.x = stof(*iterator++);
                vertex.y = stof(*iterator++);
                vertex.z = stof(*iterator++);
                vertexes.push_back(vertex);
                continue;
            }
            if (regex_search(line, regex_texture)) {
                vec2 texture;
                texture.x = stof(*iterator++);
                texture.y = stof(*iterator++);
                textures.push_back(texture);
                continue;
            }
            if (regex_search(line, regex_normal)) {
                vec3 normal;
                normal.x = stof(*iterator++);
                normal.y = stof(*iterator++);
                normal.z = stof(*iterator++);
                normals.push_back(normal);
                cout << normal.z << endl;
                continue;
            }
            if (regex_search(line, regex_face)) {
                while (iterator != regex_iterator_end) {
                    faces.push_back(stoi(*iterator++));
                }
                continue;
            }
        }
    } else {
        cout << "Can not open the file" << endl;
    }
}
 */

Pokemon::~Pokemon() {
}

//http://www.sgglnow.com/tutorial-10-using-textures-for-color/

void Pokemon::draw() {

    if (!this->active) {
        return;
    }

    if (particles.size() == 0) {

        glPushMatrix();
        this->material.apply();
        //glScalef(this->scale.x, this->scale.y, this->scale.z);
        glTranslatef(this->position.x, this->position.y, this->position.z);
        glRotatef(this->rotation.w, this->rotation.x, this->rotation.y, this->rotation.z);
        //model->position[0] = this->position.x;
        //model->position[1] = this->position.y;
        //model->position[2] = this->position.z;    
        glmDraw(model, GLM_NONE | GLM_SMOOTH);
        glPopMatrix();

        if (this->isAttacking()) {
            this->attacks->draw();
        }

    } else {
        for (int i = 0; i < particles.size(); i++) {
            particles[i].draw();
        }
    }

}

void Pokemon::idle() {

    if (!this->active) {
        return;
    }

    if (this->particles.size() == 0) {
        if (this->isAttacking()) {
            this->attacks->idle();
        }
    } else {
        bool active = false;
        for (int i = 0; i < particles.size(); i++) {
            this->particles[i].idle();
            active |= this->particles[i].active;
        }
        this->active = active;        
    }

    //cout << "Pokemon" << "\t" << "idle()" << endl;
}

void Pokemon::collisionDetection() {
    //cout << "Pokemon:" << "\t" << this << "\t" << "collisionDetection()" << endl;
}

void Pokemon::attack(Pokemon* target) {
    if (this->attacks != 0) {
        this->attacks->target = target;
        this->attacks->reset();
        this->attacks->active = true;
    }
}

bool Pokemon::isAttacking() {
    return this->attacks != 0 && this->attacks->active;
}

void Pokemon::die() {

    float size = max(this->dimensions.x, max(this->dimensions.y, this->dimensions.z));

    vec3 position = this->position;

    position.y *= 0.5;

    for (int i = 0; i < 500; i++) {

        particles.push_back(Explosion(this->time, position, size, this->material));

    }

}

void Pokemon::reborn() {
    
    this->active = true;
    
    this->particles.clear();
    
}