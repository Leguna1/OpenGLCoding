#pragma once

#include "glad/glad.h"

class Mesh
{
    unsigned int VAO;
public:
    Mesh() {
        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);

        static const GLfloat g_vertex_buffer_data[] = {
            -0.5f,-0.5f,-0.5f,
            -0.5f,-0.5f, 0.5f,
            -0.5f, 0.5f, 0.5f,
             0.5f, 0.5f,-0.5f,
            -0.5f,-0.5f,-0.5f,
            -0.5f, 0.5f,-0.5f,
             0.5f,-0.5f, 0.5f,
            -0.5f,-0.5f,-0.5f,
             0.5f,-0.5f,-0.5f,
             0.5f, 0.5f,-0.5f,
             0.5f,-0.5f,-0.5f,
            -0.5f,-0.5f,-0.5f,
            -0.5f,-0.5f,-0.5f,
            -0.5f, 0.5f, 0.5f,
            -0.5f, 0.5f,-0.5f,
             0.5f,-0.5f, 0.5f,
            -0.5f,-0.5f, 0.5f,
            -0.5f,-0.5f,-0.5f,
            -0.5f, 0.5f, 0.5f,
            -0.5f,-0.5f, 0.5f,
             0.5f,-0.5f, 0.5f,
             0.5f, 0.5f, 0.5f,
             0.5f,-0.5f,-0.5f,
             0.5f, 0.5f,-0.5f,
             0.5f,-0.5f,-0.5f,
             0.5f, 0.5f, 0.5f,
             0.5f,-0.5f, 0.5f,
             0.5f, 0.5f, 0.5f,
             0.5f, 0.5f,-0.5f,
            -0.5f, 0.5f,-0.5f,
             0.5f, 0.5f, 0.5f,
            -0.5f, 0.5f,-0.5f,
            -0.5f, 0.5f, 0.5f,
             0.5f, 0.5f, 0.5f,
            -0.5f, 0.5f, 0.5f,
             0.5f,-0.5f, 0.5f
        };

        GLuint VBO;
        glGenBuffers(1, &VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    }

    void render() {
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 36); // 36 vertices for a cube (12 triangles)
    }
};
