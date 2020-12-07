#include <stdexcept>
#include <iostream>
#include "VulkanApplication.h"

void VulkanApplication::setupWindow()
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
    this->window = window;
}

void VulkanApplication::setupAppInfo(VkApplicationInfo* appInfo)
{
   appInfo->sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
   appInfo->pApplicationName = "Vulkan Exercise";
   appInfo->applicationVersion = VK_MAKE_VERSION(0, 0, 0);
   appInfo->pEngineName = "No engine";
   appInfo->engineVersion = VK_MAKE_VERSION(0, 0, 0);
   appInfo->apiVersion = VK_API_VERSION_1_0;
}

void VulkanApplication::createVkInstance()
{
    VkApplicationInfo appInfo{};
    VkInstanceCreateInfo createInfo{};
    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions = nullptr;
    this->setupAppInfo(&appInfo);
    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
    if (glfwExtensions == nullptr)
    {
        throw std::runtime_error("Could not get GLFW VK extensions");
    }
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;
    createInfo.enabledExtensionCount = glfwExtensionCount;
    createInfo.ppEnabledExtensionNames = glfwExtensions;
    createInfo.enabledLayerCount = 0;
    VkResult result = vkCreateInstance(&createInfo, nullptr, &this->vkInstance);
    if (result != VK_SUCCESS)
    {
        throw std::runtime_error("Failed to create Vulkan instance.");
    }
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
    this->setupWindow();
    this->createVkInstance();
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
