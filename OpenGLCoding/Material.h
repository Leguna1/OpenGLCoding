#pragma once

#include "Shader.h"
#include "glad/glad.h"

class Material {

public:
    unsigned int shaderProgram;
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
