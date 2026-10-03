#include <iostream>

#include <OpenGL/gl3.h>
#include <GLFW/glfw3.h>

int main() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialise GLFW\n";
        return 1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(
        800,
        600,
        "OpenGL Test", 
        nullptr,
        nullptr
    );

    if (!window) {
        std::cerr << "Failed to create window'n";
        glfwTerminate();
        return 1;
    }

    glfwMakeContextCurrent(window);

    std::cout << "OpenGL: "
              << glGetString(GL_VERSION)
              << '\n';

    std::cout << "Renderer: "
              << glGetString(GL_RENDERER)
              << '\n';

    std::cout << "Vendor: "
              << glGetString(GL_VENDOR)
              << '\n';

    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
