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

    // Draw triangles
    float vertices1[] = {
         -1.0f,  -1.0f, 0.0f, //First Column (X coordinates):
         1.0f,  0.0f, 0.0f, //First Column (Y coordinates):
         0.0f,  0.0f, 0.0f  //First Column (Z coordinates):
    };

    /*float vertices2[] = {
       -0.5f, -0.5f, 0.0f,
        0.5f,  0.1f, 0.0f,
        0.5f,  0.5f, 0.0f
    };*/

    Mesh mesh1{ vertices1, sizeof(vertices1) / sizeof(float) };
   // Mesh mesh2{ vertices2, sizeof(vertices2) / sizeof(float) };


    Shader vertexShaderSource{ "vertexShader.glsl", GL_VERTEX_SHADER};

    Shader orangeVertexShader{ "vertexShader.glsl", GL_VERTEX_SHADER};
    Shader orangeFragmentShader{ "fragmentShader.glsl", GL_FRAGMENT_SHADER};


    Shader yellowVertexShader{ "vertexShader.glsl", GL_VERTEX_SHADER };
    Shader yellowFragmentShader{ "fragmentShader.glsl", GL_FRAGMENT_SHADER };

    Material orangeMaterial{ orangeVertexShader, orangeFragmentShader };
    Material yellowMaterial{ yellowVertexShader, yellowFragmentShader };

    Triangle triangle1{ &orangeMaterial, &mesh1 };
    //Triangle triangle2{ &yellowMaterial, &mesh2 };

    while (!window.shouldClose()) {
        window.processInput();

        window.clear();

        triangle1.render();
        //triangle2.render();

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