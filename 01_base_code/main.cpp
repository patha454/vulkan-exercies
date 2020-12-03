#include <iostream>
#include <stdexcept>
#include <cstdlib>

#include "VulkanApplication.h"

int main()
{
    VulkanApplication app;
    try
    {
        app.run();
    }
    catch (const std::exception &exception)
    {
        std::cerr << exception.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
