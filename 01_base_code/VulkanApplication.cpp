#include <stdexcept>
#include "GLFW/glfw3.h"
#include "VulkanApplication.h"

GLFWwindow* VulkanApplication::setupWindow()
{
    GLFWwindow* window = nullptr;
    if (glfwInit() == GLFW_FALSE)
    {
        throw std::runtime_error("GLFW could not be initialised.");
    }
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    window = glfwCreateWindow(
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        "Vulkan",
        nullptr,
        nullptr);
    if (window == nullptr)
    {
        throw std::runtime_error("GLFW window could not be created.");
    }
    return window;
}

void VulkanApplication::cleanupWindow()
{
    if (this->window)
    {
        glfwDestroyWindow(this->window);
    }
    glfwTerminate();
}

void VulkanApplication::run()
{
    this->initVulkan();
    this->mainLoop();
    this->cleanup();
}

void VulkanApplication::initVulkan()
{
    this->window = this->setupWindow();

}

void VulkanApplication::mainLoop()
{
    while (!glfwWindowShouldClose(this->window))
    {
        glfwPollEvents();
    }
}

void VulkanApplication::cleanup()
{
    this->cleanupWindow();
}
