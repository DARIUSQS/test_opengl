# CMAKE generated file: DO NOT EDIT!
# Generated by CMake Version 3.30
cmake_policy(SET CMP0009 NEW)

# SOURCE_FILES at CMakeLists.txt:21 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/home/darius/Dev/cpp/test_opengl/src/include/*.cpp")
set(OLD_GLOB
  "/home/darius/Dev/cpp/test_opengl/src/include/IndexBuffer.cpp"
  "/home/darius/Dev/cpp/test_opengl/src/include/Texture.cpp"
  "/home/darius/Dev/cpp/test_opengl/src/include/VertexArray.cpp"
  "/home/darius/Dev/cpp/test_opengl/src/include/VertexBuffer.cpp"
  "/home/darius/Dev/cpp/test_opengl/src/include/VertexBufferLayout.cpp"
  "/home/darius/Dev/cpp/test_opengl/src/include/camera.cpp"
  "/home/darius/Dev/cpp/test_opengl/src/include/map.cpp"
  "/home/darius/Dev/cpp/test_opengl/src/include/shader.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/home/darius/Dev/cpp/test_opengl/src/CMakeFiles/cmake.verify_globs")
endif()
