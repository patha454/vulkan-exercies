add_executable(00_test main.cpp)

target_include_directories(00_test
    PRIVATE
    "${GLM_INCLUDE_PATH}"
    "${GLFW_INCLUDE_PATH}"
    "${Vulkan_INCLUDE_DIRS}")

target_link_libraries(00_test
    "${GLFW_LIBRARY_PATH}"
    "${Vulkan_LIBRARIES}")
