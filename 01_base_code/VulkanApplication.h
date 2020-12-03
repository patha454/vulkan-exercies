#ifndef VULKANEXERCISES_01_BASE_CODE_VULKANAPPLICATION_H
#define VULKANEXERCISES_01_BASE_CODE_VULKANAPPLICATION_H

class VulkanApplication
{
public:
    void run();

private:
    void initVulkan();

    void mainLoop();

    void cleanup();
};

#endif
