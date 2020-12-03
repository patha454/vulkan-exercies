cmake_minimum_required(VERSION 3.17)
project(VulkanExercises)
set(CMAKE_CXX_STANDARD 17)

# Find GLM

if (WIN32)
    find_path(GLM_INCLUDE_PATH "glm/glm.hpp"
        PATHS
            "${GLM_ROOT_DIR}"
            "${PROJECT_SOURCE_DIR}"
            "$ENV{ProgramFiles}"
            "$ENV{ProgramFiles}\\glm"
        PATH_SUFFIXES "include" "glm"
        DOC "The GLM include path, where `glm/glm.hpp` is located."
        REQUIRED)
else()
    find_path(GLM_INCLUDE_PATH "glm/glm.hpp"
        PATHS
            "/usr/include"
            "/usr/local/include"
            "${GLM_ROOT_DIR}"
        PATH_SUFFIXES "include" "glm"
        DOC "The GLM include path, where `glm/glm.hpp` is located."
        REQUIRED)
endif()

message(NOTICE "GLM Path: ${GLM_INCLUDE_PATH}")

# Find GLFW

if (WIN32)
    find_path(GLFW_INCLUDE_PATH "GLFW/glfw3.h"
        PATHS
            "${GLFW_ROOT_DIR}"
            "${PROJECT_SOURCE_DIR}"
            "$ENV{ProgramFiles}"
            "$ENV{ProgramFiles}\\glfw"
        PATH_SUFFIXES "include" "glfw"
        DOC "The GLFW include path, where `glfw/glfw.hpp` is located."
        REQUIRED)

    if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
        string(REGEX MATCH "^[0-9]*" MSVC_VERSION "${CMAKE_CXX_COMPILER_VERSION}")
        find_library(GLFW_LIBRARY_PATH NAMES "glfw3.lib"
        PATHS
            "${GLFW_ROOT_DIR}"
            "${PROJECT_SOURCE_DIR}"
            "$ENV{ProgramFiles}"
            "$ENV{ProgramFiles}\\glfw"
        PATH_SUFFIXES "lib-vc20${MSVC_VERSION}"
        REQUIRED)
    else()
        message(FATAL_ERROR "`${CMAKE_CXX_COMPILER_ID}` compiler is not supported.")
    endif()
else()
    find_path(GLFW_INCLUDE_PATH "GLFW/glfw3.hpp"
        PATHS
        "/usr/include"
        "/usr/local/include"
        "${GLFW_ROOT_DIR}"
        PATH_SUFFIXES "include" "glm"
        DOC "The GLFW include path, where `glfw/glfw.hpp` is located."
        REQUIRED)

    message(FATAL_ERROR "UNIX build not yet supported. GLFW library selection not implemented.")
endif()

message(NOTICE "GLFW Include Path: ${GLFW_INCLUDE_PATH}")
message(NOTICE "GLFW Library Path: ${GLFW_LIBRARY_PATH}")

find_package(Vulkan)

if (NOT Vulkan_FOUND)
    message(FATAL_ERROR "Vulkan Library not found.")
endif()

message(NOTICE "Vulkan Include Path: ${Vulkan_INCLUDE_DIRS}")
message(NOTICE "Vulkan Library Path: ${Vulkan_LIBRARIES}")

add_subdirectory(00_test)
