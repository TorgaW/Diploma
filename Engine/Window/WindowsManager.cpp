#include "WindowsManager.hpp"

Window *WindowsManager::CreateWindow(const uint16_t width, const uint16_t height)
{
    GLFWwindow* window = glfwCreateWindow(width, height, "CEngine", nullptr, nullptr);
    return new Window(width, height, window);
}

Window *WindowsManager::CreateWindow()
{
    const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    
    glfwWindowHint(GLFW_RED_BITS, mode->redBits);
    glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
    glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
    glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);
    
    GLFWwindow* window = glfwCreateWindow(mode->width, mode->height, "OpenGL View", glfwGetPrimaryMonitor(), nullptr);
    return new Window(mode->width, mode->height, window);
}