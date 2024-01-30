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

    Vertex vertices1[] = 
    {                   // [X]    [Y]   [Z] 
         Vertex{Vector3{  0.0f,  0.0f, 0.0f}, Color::red},
         Vertex{Vector3{ -0.8f,  0.0f, 0.0f}, Color::green},
         Vertex{Vector3{ 0.4f,  0.8f, 0.4f}, Color::blue},
         Vertex{Vector3{ 0.4f,  0.8f, 0.4f}, Color::blue}
    };

    Vertex vertices2[] = {
          Vertex{Vector3{ 0.0f,  0.0f, 0.0f}, Color::blue},
          Vertex{Vector3{ 0.8f,  0.0f, 0.0f}, Color::red},
          Vertex{Vector3{ 0.4f,  0.8f, 0.4f}, Color::green},
    };

    Vertex vertices3[] = {
           Vertex{Vector3{0.8f,  0.0f, 0.0f}, Color::green},
           Vertex{Vector3{1.6f,  0.0f, 0.0f}, Color::red},
           Vertex{Vector3{1.2f,  0.8f, 0.4f}, Color::blue}
    };


    Mesh mesh1{ vertices1, sizeof(vertices1) / sizeof(Vertex) };
    Mesh mesh2{ vertices2, sizeof(vertices2) / sizeof(Vertex) };
    Mesh mesh3{ vertices3, sizeof(vertices3) / sizeof(Vertex) };


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
    
    Triangle triangle2{ &greenMaterial, &mesh2 };
    
    Triangle triangle3{ &blueMaterial, &mesh3 };
   
    while (!window.shouldClose()) {
        window.processInput();

        window.clearBgColor();

        // Update the time value for each frame
        float currentTime = glfwGetTime();
        triangle1.setTime(currentTime);
        triangle2.setTime(currentTime);
        triangle3.setTime(currentTime);

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