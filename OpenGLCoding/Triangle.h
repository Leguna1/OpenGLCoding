#pragma once
#include "Mesh.h"
#include "Material.h"
#include "Shader.h"

class Triangle
{
    Mesh* mesh;
    Material* material;
public:
    Triangle(Material* _material, Mesh* _mesh) : mesh(_mesh), material(_material) {}

    float red;
    float blue;
    float green;

    void render() {
        material->use();

        int tintLocation = glGetUniformLocation(material->shaderProgram, "tintColor");
        glUniform4f(tintLocation, red, green, blue, 1);
        mesh->render();
    }
};
