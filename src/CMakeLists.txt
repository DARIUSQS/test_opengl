cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)



cmake_policy(SET CMP0069 NEW) 
set(CMAKE_POLICY_DEFAULT_CMP0069 NEW)
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)

project(opengl)

add_subdirectory(vendor/glad)
add_subdirectory(vendor/stb_image)
add_subdirectory(vendor/glm)
add_subdirectory(vendor/imgui)

add_executable(opengl main.cpp)

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS "include/*.cpp")

target_sources(opengl PRIVATE ${SOURCE_FILES})

target_include_directories(opengl PUBLIC "include/")

target_link_libraries(opengl PRIVATE glm glfw glad stb_image imgui)

