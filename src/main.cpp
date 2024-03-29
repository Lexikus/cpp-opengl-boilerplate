#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

void errorCallback(int error, const char *description)
{
    std::cout << "GLFW error " << error << ":" << description << std::endl;
}

GLFWwindow *initialize()
{
    int glfwInitRes = glfwInit();
    if (!glfwInitRes)
    {
        std::cout << "Unable to initialize GLFW" << std::endl;
        return nullptr;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow *window = glfwCreateWindow(1280, 720, "OpenGL Boilerplate", nullptr, nullptr);
    if (!window)
    {
        std::cout << "Unable to create GLFW window" << std::endl;
        glfwTerminate();
        return nullptr;
    }

    glfwMakeContextCurrent(window);

    int gladInitRes = gladLoadGL();
    if (!gladInitRes)
    {
        std::cout << "Unable to initialize glad" << std::endl;
        glfwDestroyWindow(window);
        glfwTerminate();
        return nullptr;
    }

    return window;
}

int main()
{
    auto v = glm::vec3{1, 2, 3};
    std::cout << "glm is working - v.x: " << v.x << std::endl;

    glfwSetErrorCallback(errorCallback);

    GLFWwindow *window = initialize();
    if (!window)
    {
        return 0;
    }

    // Set the clear color to a nice green
    glClearColor(0.15f, 0.6f, 0.4f, 1.0f);

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}