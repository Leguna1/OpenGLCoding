#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Window.h"
#include "Mesh.h"
#include "Shader.h"
#include "Triangle.h"

using namespace std;

void processInput(GLFWwindow*);

int main() {
    Window window{ 800, 600 };

    // Create triangles
    float vertices1[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };

    float vertices2[] = {
        0.5f, -0.5f, 0.0f,
       -0.5f,  0.5f, 0.0f,
        0.5f,  0.5f, 0.0f
    };

    Mesh mesh1{ vertices1, sizeof(vertices1) / sizeof(float) };
    Mesh mesh2{ vertices2, sizeof(vertices2) / sizeof(float) };

    Shader vertexShaderSource{ R"(
        #version 330 core
        layout (location = 0) in vec3 aPos;
        void main() {
            gl_Position = vec4(aPos, 1.0);
        }
    )", GL_VERTEX_SHADER };

    Shader orangeVertexShader{ R"(
        #version 330 core
        layout (location = 0) in vec3 aPos;
        void main() {
            gl_Position = vec4(aPos, 1.0);
        }
    )", GL_VERTEX_SHADER };

    Shader orangeFragmentShader{ R"(
        #version 330 core
        out vec4 FragColor;
        void main() {
            FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
        }
    )", GL_FRAGMENT_SHADER };

    Shader yellowVertexShader{ R"(
        #version 330 core
        layout (location = 0) in vec3 aPos;
        void main() {
            gl_Position = vec4(aPos, 1.0);
        }
    )", GL_VERTEX_SHADER };

    Shader yellowFragmentShader{ R"(
        #version 330 core
        out vec4 FragColor;
        void main() {
            FragColor = vec4(1.0f, 1.0f, 0.0f, 1.0f);
        }
    )", GL_FRAGMENT_SHADER };

    Material orangeMaterial{ orangeVertexShader, orangeFragmentShader };
    Material yellowMaterial{ yellowVertexShader, yellowFragmentShader };

    Triangle triangle1{ &orangeMaterial, &mesh1 };
    Triangle triangle2{ &yellowMaterial, &mesh2 };

    while (!window.shouldClose()) {
        window.processInput();

        window.clear();

        triangle1.render();
        triangle2.render();

        window.present();
    }

    // Cleans up to avoid copies
    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}
