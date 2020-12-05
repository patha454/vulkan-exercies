#ifndef VULKANEXERCISES_01_BASE_CODE_VULKANAPPLICATION_H
#define VULKANEXERCISES_01_BASE_CODE_VULKANAPPLICATION_H

#include "GLFW//glfw3.h"

class VulkanApplication
{
public:
    void run();

private:
    static const uint32_t WINDOW_WIDTH = 800;
    static const uint32_t WINDOW_HEIGHT = 600;
    GLFWwindow* window = nullptr;


    void initVulkan();

    GLFWwindow* setupWindow();

    void cleanupWindow();

    void mainLoop();

    void cleanup();
};

#endif
