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
    float time;  // Add a member variable for time
public:
    inline Triangle(Material* _material, Mesh* _mesh) : mesh(_mesh), material(_material), time(0.0f) {}

    void setTime(float t) {
        time = t;  // Set the time value
    }

    void render() {
        material->use();

        int tintLocation = glGetUniformLocation(material->shaderProgram, "tintColor");
        glUniform4f(tintLocation, 0, 0, 0, 1);

        // Pass the time value to the shader
        int timeLocation = glGetUniformLocation(material->shaderProgram, "time");
        glUniform1f(timeLocation, time);

        mesh->render();
    }
};
