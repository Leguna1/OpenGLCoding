#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Window.h"
#include "Mesh.h"

using namespace std;

int main() {
    Window window{ 1024, 768 };
    Mesh cubeMesh;

    if (!window.success) {
        cout << "Failed to create window" << endl;
        return -1;
    }

    while (!window.shouldClose()) {
        window.processInput();
        window.clear();
        cubeMesh.render();
        window.present();
    }

    glfwTerminate();
    return 0;
}
