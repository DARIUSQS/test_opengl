cmake_minimum_required(VERSION 3.13)
project(program)            
set(CMAKE_CXX_STANDARD 14)        

file(GLOB SRC_FILES *.cpp)
file(GLOB INCLUDE_FILES *.h)

add_executable(program ${SRC_FILES} ${INCLUDE_FILES})
target_include_directories(program PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(program glfw)
