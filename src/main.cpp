#include <iostream>

#include <OpenGL/gl3.h>
#include <GLFW/glfw3.h>

#include "shader.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

int main() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialise GLFW\n";
        return 1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    GLFWwindow *window = glfwCreateWindow(
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
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
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    std::cout << "OpenGL: " << glGetString(GL_VERSION) << '\n';
    std::cout << "Renderer: " << glGetString(GL_RENDERER) << '\n';
    std::cout << "Vendor: " << glGetString(GL_VENDOR) << '\n';

    Shader ourShader("shaders/basic.vert", "shaders/basic.frag");

    float vertices[] = {
        // positions         // colors
         0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // bottom right
        -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // bottom left
         0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // top 
    };    

    unsigned int VBO1, VAO1;
    glGenVertexArrays(1,&VAO1);
    glGenBuffers(1, &VBO1);

    glBindVertexArray(VAO1);

    glBindBuffer(GL_ARRAY_BUFFER, VBO1);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Linking vertex attributes
    // Position Attributes
    glVertexAttribPointer(
        0,                      // Location
        3,                      // Size of the vertex attribute (we are using vec3 so it's 3)
        GL_FLOAT,               // Data type
        GL_FALSE,               // Normalise
        6 * sizeof(float),      // Stride - space between vertex attributes
        (void*)0                // offset
    );
    glEnableVertexAttribArray(0);

    // Color attributes
    glVertexAttribPointer(
        1,                      // Location
        3,                      // Size of the vertex attribute (we are using vec3 so it's 3)
        GL_FLOAT,               // Data type
        GL_FALSE,               // Normalise
        6 * sizeof(float),      // Stride - space between vertex attributes
        (void*) (3 * sizeof(float))                // offset
    );
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);   // Unbind
    glBindVertexArray(0);

    while (!glfwWindowShouldClose(window)) {
        processInput(window);

        // Render commands
        glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        ourShader.use();
        glBindVertexArray(VAO1);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // De-allocate
    glDeleteVertexArrays(1, &VAO1);
    glDeleteBuffers(1, &VBO1);

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
void processInput(GLFWwindow *window);
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}
