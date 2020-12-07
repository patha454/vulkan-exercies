#ifndef VULKANEXERCISES_01_BASE_CODE_VULKANAPPLICATION_H
#define VULKANEXERCISES_01_BASE_CODE_VULKANAPPLICATION_H

#include "vulkan/vulkan.h"
#include "GLFW/glfw3.h"

class VulkanApplication
{
public:
    void run();

private:
    static const uint32_t WINDOW_WIDTH = 800;
    static const uint32_t WINDOW_HEIGHT = 600;
    GLFWwindow* window = nullptr;
    VkInstance vkInstance;

    void initVulkan();

    void setupWindow();

    void setupAppInfo(VkApplicationInfo* appInfo);

    void createVkInstance();

    void cleanupWindow();

    void mainLoop();

    void cleanup();
};

#endif
