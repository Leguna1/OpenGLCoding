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
    Window window{ 1280, 800 };

    // Triangle 1
    float vertices1[] = {
         0.0f,  0.0f, 0.0f,
         -0.8f,  0.0f, 0.0f,
         -0.4f,  0.8f, 0.4f
    };

    // Triangle 2
    float vertices2[] = {
         0.0f,  0.0f, 0.0f,
         0.8f,  0.0f, 0.0f,
         0.4f,  0.8f, 0.4f
    };

    // Triangle 3
    float vertices3[] = {
         0.8f,  0.0f, 0.0f,
         1.6f,  0.0f, 0.0f,
         1.2f,  0.8f, 0.4f
    };


    Mesh mesh1{ vertices1, sizeof(vertices1) / sizeof(float) };
    Mesh mesh2{ vertices2, sizeof(vertices2) / sizeof(float) };
    Mesh mesh3{ vertices3, sizeof(vertices3) / sizeof(float) };


    Shader vertexShaderSource{ "vertexShader.glsl", GL_VERTEX_SHADER};

    Shader redVertexShader{ "vertexShader.glsl", GL_VERTEX_SHADER};
    Shader greenVertexShader{ "vertexShader.glsl", GL_VERTEX_SHADER };
    Shader blueVertexShader{ "vertexShader.glsl", GL_VERTEX_SHADER };

    Shader redFragmentShader{ "fragmentShader.glsl", GL_FRAGMENT_SHADER};
    Shader greenFragmentShader{ "fragmentShader.glsl", GL_FRAGMENT_SHADER };
    Shader blueFragmentShader{ "fragmentShader.glsl", GL_FRAGMENT_SHADER };

    Material redMaterial{ redVertexShader, redFragmentShader };
    Material greenMaterial{ greenVertexShader, greenFragmentShader };
    Material blueMaterial{ blueVertexShader, blueFragmentShader };


    Triangle triangle1{ &redMaterial, &mesh1 };
    triangle1.red = 1;
    Triangle triangle2{ &greenMaterial, &mesh2 };
    Triangle triangle3{ &blueMaterial, &mesh3 };

    while (!window.shouldClose()) {
        window.processInput();

        window.clearBgColor();

        triangle1.render();
        triangle2.render();
        triangle3.render();

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