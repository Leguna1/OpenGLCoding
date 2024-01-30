#pragma once
#include <cstddef>
#include "glad/glad.h"

struct Vector3
{
    float x, y, z;
};

struct Color
{
    static const Color red;
    static const Color green;
    static const Color blue;
    float r, g, b, a;
};


struct Vertex
{
    Vector3 pos;
    Color col{ 0, 0, 1, 1 };
};

class Mesh
{
    unsigned int VAO;
    size_t vertexCount;

public:
    void render() {
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(vertexCount));
    }

    Mesh(Vertex* vertices, size_t count) {
        vertexCount = count;
        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);

        unsigned int VBO;
        glGenBuffers(1, &VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);

        glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * count, vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_TRUE, sizeof(Vertex), (void*)offsetof(Vertex, pos));
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 4, GL_FLOAT, GL_TRUE, sizeof(Vertex), (void*)offsetof(Vertex, col));
        glEnableVertexAttribArray(1);
    }
};
