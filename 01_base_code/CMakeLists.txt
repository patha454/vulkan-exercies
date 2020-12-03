add_executable(01_base_code
    main.cpp
    VulkanApplication.cpp)

target_include_directories(01_base_code
    PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${GLM_INCLUDE_PATH}"
    "${GLFW_INCLUDE_PATH}"
    "${VULKAN_INCLUDE_PATH}")

target_link_libraries(01_base_code
    "${GLFW_LIBRARY_PATH}"
    "${Vulkan_LIBRARIES}")
