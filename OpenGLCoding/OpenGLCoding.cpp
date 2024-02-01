#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Window.h"
#include "Mesh.h"
#include "Shader.h"
#include "Triangle.h"
#include "stb_image.h"

using namespace std;

void processInput(GLFWwindow*);

int main() {
    Window window{ 1280, 800 };
    int width, height, nrChannels;

    unsigned char* data = stbi_load("wall.jpg", &width, &height, &nrChannels, 0);
    unsigned int textureId;
    glGenTextures(1, &textureId);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureId);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(data);

    unsigned char* data1 = stbi_load("brickwall9.jpg", &width, &height, &nrChannels, 0);
    unsigned int textureId1; // Rename the variable to textureId1
    glGenTextures(1, &textureId1);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, textureId1);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data1);
    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(data1);

    Vertex vertices1[] = {
        Vertex{Vector3{  0.0f,  -1.0f, 0.0f}, Color::red},
        Vertex{Vector3{ 0.8f,  0.0f, 0.0f}, Color::green},
        Vertex{Vector3{ 0.4f,  0.8f, 0.4f}, Color::blue},
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

    for (int i = 0; i < 3; ++i) {
        vertices1[i].pos.y *= -1.0f;
        vertices2[i].pos.y *= -1.0f; // Invert y for vertices2 as well
        vertices3[i].pos.y *= -1.0f; // Invert y for vertices3 as well
    }

    Mesh mesh1{ vertices1, sizeof(vertices1) / sizeof(Vertex) };
    Mesh mesh2{ vertices2, sizeof(vertices2) / sizeof(Vertex) };
    Mesh mesh3{ vertices3, sizeof(vertices3) / sizeof(Vertex) };

    Shader vertexShaderSource{ "vertexShader.glsl", GL_VERTEX_SHADER };

    Shader redVertexShader{ "vertexShader.glsl", GL_VERTEX_SHADER };
    Shader greenVertexShader{ "vertexShader.glsl", GL_VERTEX_SHADER };
    Shader blueVertexShader{ "vertexShader.glsl", GL_VERTEX_SHADER };

    Shader redFragmentShader{ "fragmentShader.glsl", GL_FRAGMENT_SHADER };
    Shader greenFragmentShader{ "fragmentShader.glsl", GL_FRAGMENT_SHADER };
    Shader blueFragmentShader{ "fragmentShader.glsl", GL_FRAGMENT_SHADER };

    Shader textureShader{ "textureShader.glsl", GL_FRAGMENT_SHADER }; // Add this line

    Material redMaterial{ redVertexShader, redFragmentShader };
    Material greenMaterial{ greenVertexShader, greenFragmentShader };
    Material blueMaterial{ blueVertexShader, blueFragmentShader };

    Material textured{ redVertexShader, textureShader }; // Use textureShader

    Triangle triangle1{ &redMaterial, &mesh1 };
    Triangle triangle2{ &greenMaterial, &mesh2 };
    Triangle triangle3{ &blueMaterial, &mesh3 };

    while (!window.shouldClose()) {
        window.processInput();

        window.clearBgColor();

        float currentTime = glfwGetTime();
        triangle1.setTime(currentTime);
        triangle2.setTime(currentTime);
        triangle3.setTime(currentTime);

        triangle1.render();
        triangle2.render();
        triangle3.render();

        window.present();
    }

    glfwTerminate();
    return 0;
    }

        void processInput(GLFWwindow* window) {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);
    }
