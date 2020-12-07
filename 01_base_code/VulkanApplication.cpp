#include <algorithm>
#include <stdexcept>
#include <cstring>
#include <iostream>
#include <vector>
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

void VulkanApplication::checkExtensions(char** requiredExtensions, uint32_t requiredExtensionsCount)
{
    uint32_t extensionCount = 0;
    std::vector<VkExtensionProperties> extensions;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
    extensions = std::vector<VkExtensionProperties>(extensionCount);
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());
    for (int i = 0; i < requiredExtensionsCount; i++)
    {
        char* requiredExtension = requiredExtensions[i];
        auto result = std::find_if(
            extensions.begin(),
            extensions.end(),
            [=](auto a)
            {
                return strcmp(a.extensionName, requiredExtension) == 0;
            });
        if (result == std::end(extensions))
        {
            throw std::runtime_error("Required extension unavailable: " + std::string(requiredExtension));
        }
        else
        {
            std::cout << "Found required extension " << requiredExtension << std::endl;
        }
    }
}


void VulkanApplication::createVkInstance()
{
    VkApplicationInfo appInfo{};
    VkInstanceCreateInfo createInfo{};
    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions = nullptr;
    this->setupAppInfo(&appInfo);
    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
    this->checkExtensions((char**) glfwExtensions, glfwExtensionCount);
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
