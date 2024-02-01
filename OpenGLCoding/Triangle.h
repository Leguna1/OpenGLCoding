#pragma once
#include "Mesh.h"
#include "Material.h"
#include "Shader.h"
#include <iostream>
#include "GLFW/glfw3.h"

class Triangle
{
    Mesh* mesh;
    Material* material;
    float time;
    float horizontalOffset; // Add this line to declare horizontalOffset
public:
    inline Triangle(Material* _material, Mesh* _mesh) : mesh(_mesh), material(_material), time(0.0f), horizontalOffset(0.0f) {}

    void setTime(float t) {
        time = t;
    }

    void setHorizontalOffset(float offset) { // Add this function
        horizontalOffset = offset;
    }

    void render() {
        material->use();

        int tintLocation = glGetUniformLocation(material->shaderProgram, "tintColor");
        glUniform4f(tintLocation, 1, 1, 0, 1);

        int timeLocation = glGetUniformLocation(material->shaderProgram, "time");
        glUniform1f(timeLocation, time);

        int offsetLocation = glGetUniformLocation(material->shaderProgram, "horizontalOffset");
        glUniform1f(offsetLocation, horizontalOffset);

        // Use glUniform1i for texture units
        int diffuseLocation = glGetUniformLocation(material->shaderProgram, "diffuseTexture");
        glUniform1i(diffuseLocation, 0); // Use GL_TEXTURE0

        int blendLocation = glGetUniformLocation(material->shaderProgram, "blendTexture");
        glUniform1i(blendLocation, 1); // Use GL_TEXTURE1

        mesh->render();
    }
};
