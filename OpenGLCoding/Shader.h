#pragma once

#include "glad/glad.h"

class Shader
{
public:
    unsigned int shaderId;
    Shader() { // when constructed: load shader on GPU
        const char* vertexShaderSource{ };
        shaderId = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(shaderId, 1, &vertexShaderSource, nullptr);
        glCompileShader(shaderId);
    }
    Shader(const Shader&) = delete; // avoid it being cloned

    ~Shader() { // when destructed: delete the shader from GPU
        glDeleteShader(shaderId);
    }
};