#pragma once
#include "Mesh.h"
#include "Material.h"
#include "Shader.h"
#include <iostream>
//#include "GLFW/glfw3.h"

class Triangle
{
    Mesh* mesh;
    Material* material;
public:
    inline Triangle (Material* _material, Mesh* _mesh) : mesh(_mesh), material(_material) {}

    

    void render() {
        material->use();
        //glUniform
        int tintLocation = glGetUniformLocation(material->shaderProgram, "tintColor");
        glUniform4f(tintLocation, 0, 0, 0, 1);
        mesh->render();
    }
};
