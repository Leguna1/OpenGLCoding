#pragma once

#include "glad/glad.h"
#include <string>

class Shader {
    unsigned int shaderId;

public:
    Shader(const char* source, int shaderType) {
        shaderId = glCreateShader(shaderType);
        glShaderSource(shaderId, 1, &source, nullptr);
        glCompileShader(shaderId);
    }

    ~Shader() {
        glDeleteShader(shaderId);
    }

    unsigned int getShaderId() const {
        return shaderId;
    }
};
