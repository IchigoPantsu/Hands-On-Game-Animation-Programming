cmake_minimum_required(VERSION 3.8)
project(vulkan_renderer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -g")

find_package(Vulkan REQUIRED)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin/$<IF:$<CONFIG:Debug>,Debug,Release>")

## Config vulkan
#if (WIN32)
#    set(Vulkan_INCLUDE_DIRS "$ENV{VULKAN_SDK}/Include")
#    if (CMAKE_SIZEOF_VOID_P EQUAL 8)
#        set(VULKAN_LIBRARY "$ENV{VULKAN_SDK}/Lib/vulkan-1.lib")
#        set(VULKAN_STATIC_LIBRARY "$ENV{VULKAN_SDK}/Lib/vkstatic.1.lib")
#    else()
#        set(VULKAN_LIBRARY "$ENV{VULKAN_SDK}/Lib32/vulkan-1.lib")
#        set(VULKAN_STATIC_LIBRARY "$ENV{VULKAN_SDK}/Lib32/vkstatic.1.lib")
#    endif()
#elseif (APPLE)
#    set(CMAKE_FIND_FRAMEWORK NEVER)
#    find_library(VULKAN_LIBRARY MoltenVK)
#    set(CMAKE_FIND_FRAMEWORK ONLY)
#    find_library(VULKAN_STATIC_LIBRARY MoltenVK)
#    find_path(VULKAN_INCLUDE_DIR NAMES vulkan/vulkan.h HINTS
#            "${VULKAN_LIBRARY}/Headers")
#else()
#    find_path(VULKAN_INCLUDE_DIR NAMES vulkan/vulkan.h HINTS
#            "$ENV{VULKAN_SDK}/include")
#    find_library(VULKAN_LIBRARY NAMES vulkan HINTS
#            "$ENV{VULKAN_SDK}/lib")
#endif()
#include_directories(${Vulkan_INCLUDE_DIRS})
#list(APPEND LIBS ${VULKAN_LIBRARY})
#message(STATUS "Vulkan Include dirs: ${Vulkan_INCLUDE_DIRS} and libs: ${VULKAN_LIBRARY}")

# Config glfw3
option(GLFW_BUILD_DOCS OFF)
option(GLFW_BUILD_EXAMPLES OFF)
option(GLFW_BUILD_TESTS OFF)
add_subdirectory(third_party/glfw)
include_directories(third_party/glfw/include)
list(APPEND LIBS glfw)

#list(APPEND LIBS m)

add_subdirectory(./Chapter01/Sample00)

#add_subdirectory(./Chapter02/Sample00)

#add_subdirectory(./Chapter03/Sample00)
add_subdirectory(./Chapter03/Sample01)

#add_subdirectory(./Chapter04/Sample00)

#add_subdirectory(./Chapter05/Sample00)

#add_subdirectory(./Chapter06/Sample00)
add_subdirectory(./Chapter06/Sample01)

#add_subdirectory(./Chapter07/Sample00)

#add_subdirectory(./Chapter08/Sample00)
add_subdirectory(./Chapter08/Sample01)

#add_subdirectory(./Chapter09/Sample00)
add_subdirectory(./Chapter09/Sample01)

#add_subdirectory(./Chapter10/Sample00)
add_subdirectory(./Chapter10/Sample01)
add_subdirectory(./Chapter10/Sample02)

#add_subdirectory(./Chapter11/Sample00)
add_subdirectory(./Chapter11/Sample01)
add_subdirectory(./Chapter11/Sample02)
add_subdirectory(./Chapter11/Sample03)

#add_subdirectory(./Chapter12/Sample00)
add_subdirectory(./Chapter12/Sample01)
add_subdirectory(./Chapter12/Sample02)
add_subdirectory(./Chapter12/Sample03)

#add_subdirectory(./Chapter13/Sample00)
add_subdirectory(./Chapter13/Sample01)
add_subdirectory(./Chapter13/Sample02)
add_subdirectory(./Chapter13/Sample03)

#add_subdirectory(./Chapter14/Sample00)
add_subdirectory(./Chapter14/Sample01)

#add_subdirectory(./Chapter15/Sample00)
add_subdirectory(./Chapter15/Sample01)

#add_subdirectory(./AllChapters)
# Compiling Shaders
if (WIN32)
  if (${CMAKE_HOST_SYSTEM_PROCESSOR} STREQUAL "AMD64")
    set(GLSL_VALIDATOR "$ENV{VULKAN_SDK}/Bin/glslangValidator.exe")
  else()
    set(GLSL_VALIDATOR "$ENV{VULKAN_SDK}/Bin32/glslangValidator.exe")
  endif()
elseif (UNIX)
  set(GLSL_VALIDATOR "/usr/bin/glslc")
endif()

file(GLOB_RECURSE GLSL_SOURCE_FILES
    "${PROJECT_SOURCE_DIR}/data/shaders/*.frag"
    "${PROJECT_SOURCE_DIR}/data/shaders/*.vert"
    "${PROJECT_SOURCE_DIR}/data/shaders/*.comp"
)

foreach(GLSL ${GLSL_SOURCE_FILES})
  message(STATUS "BUILDING SHADER")
  get_filename_component(FILE_NAME ${GLSL} NAME)
  #set(SPIRV "${PROJECT_SOURCE_DIR}/data/shaders/${FILE_NAME}.spv")
  set(SPIRV "${PROJECT_SOURCE_DIR}/data/shaders/spirv/${FILE_NAME}.spirv")
  message(STATUS ${GLSL})
  if (WIN32)
    add_custom_command(
      OUTPUT  ${SPIRV}
      COMMAND ${GLSL_VALIDATOR} -V ${GLSL} -o ${SPIRV}
      DEPENDS ${GLSL})
  elseif (UNIX)
    add_custom_command(
      OUTPUT  ${SPIRV}
      COMMAND ${GLSL_VALIDATOR} ${GLSL} -o ${SPIRV}
      DEPENDS ${GLSL})
  endif()
  list(APPEND SPIRV_BINARY_FILES ${SPIRV})
endforeach(GLSL)

add_custom_target(
    Shaders 
    DEPENDS ${SPIRV_BINARY_FILES}
	  SOURCES ${GLSL_SOURCE_FILES}
)
