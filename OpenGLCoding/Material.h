#pragma once

#include "Shader.h"
#include "glad/glad.h"

class Material {
    unsigned int shaderProgram;

public:
    Material(Shader& vertexShader, Shader& fragmentShader) {

        shaderProgram = glCreateProgram();
        glAttachShader(shaderProgram, vertexShader.getShaderId());
        glAttachShader(shaderProgram, fragmentShader.getShaderId());
        glLinkProgram(shaderProgram);
    }

    void use() const {
        glUseProgram(shaderProgram);
    }
};
