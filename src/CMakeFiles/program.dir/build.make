# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/darius/Dev/cpp/opengl/test_opengl/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/darius/Dev/cpp/opengl/test_opengl/src

# Include any dependencies generated for this target.
include CMakeFiles/program.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/program.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/program.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/program.dir/flags.make

CMakeFiles/program.dir/IndexBuffer.cpp.o: CMakeFiles/program.dir/flags.make
CMakeFiles/program.dir/IndexBuffer.cpp.o: IndexBuffer.cpp
CMakeFiles/program.dir/IndexBuffer.cpp.o: CMakeFiles/program.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/darius/Dev/cpp/opengl/test_opengl/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/program.dir/IndexBuffer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/program.dir/IndexBuffer.cpp.o -MF CMakeFiles/program.dir/IndexBuffer.cpp.o.d -o CMakeFiles/program.dir/IndexBuffer.cpp.o -c /home/darius/Dev/cpp/opengl/test_opengl/src/IndexBuffer.cpp

CMakeFiles/program.dir/IndexBuffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/program.dir/IndexBuffer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/darius/Dev/cpp/opengl/test_opengl/src/IndexBuffer.cpp > CMakeFiles/program.dir/IndexBuffer.cpp.i

CMakeFiles/program.dir/IndexBuffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/program.dir/IndexBuffer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/darius/Dev/cpp/opengl/test_opengl/src/IndexBuffer.cpp -o CMakeFiles/program.dir/IndexBuffer.cpp.s

CMakeFiles/program.dir/Texture.cpp.o: CMakeFiles/program.dir/flags.make
CMakeFiles/program.dir/Texture.cpp.o: Texture.cpp
CMakeFiles/program.dir/Texture.cpp.o: CMakeFiles/program.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/darius/Dev/cpp/opengl/test_opengl/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/program.dir/Texture.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/program.dir/Texture.cpp.o -MF CMakeFiles/program.dir/Texture.cpp.o.d -o CMakeFiles/program.dir/Texture.cpp.o -c /home/darius/Dev/cpp/opengl/test_opengl/src/Texture.cpp

CMakeFiles/program.dir/Texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/program.dir/Texture.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/darius/Dev/cpp/opengl/test_opengl/src/Texture.cpp > CMakeFiles/program.dir/Texture.cpp.i

CMakeFiles/program.dir/Texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/program.dir/Texture.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/darius/Dev/cpp/opengl/test_opengl/src/Texture.cpp -o CMakeFiles/program.dir/Texture.cpp.s

CMakeFiles/program.dir/VertexArray.cpp.o: CMakeFiles/program.dir/flags.make
CMakeFiles/program.dir/VertexArray.cpp.o: VertexArray.cpp
CMakeFiles/program.dir/VertexArray.cpp.o: CMakeFiles/program.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/darius/Dev/cpp/opengl/test_opengl/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/program.dir/VertexArray.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/program.dir/VertexArray.cpp.o -MF CMakeFiles/program.dir/VertexArray.cpp.o.d -o CMakeFiles/program.dir/VertexArray.cpp.o -c /home/darius/Dev/cpp/opengl/test_opengl/src/VertexArray.cpp

CMakeFiles/program.dir/VertexArray.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/program.dir/VertexArray.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/darius/Dev/cpp/opengl/test_opengl/src/VertexArray.cpp > CMakeFiles/program.dir/VertexArray.cpp.i

CMakeFiles/program.dir/VertexArray.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/program.dir/VertexArray.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/darius/Dev/cpp/opengl/test_opengl/src/VertexArray.cpp -o CMakeFiles/program.dir/VertexArray.cpp.s

CMakeFiles/program.dir/VertexBuffer.cpp.o: CMakeFiles/program.dir/flags.make
CMakeFiles/program.dir/VertexBuffer.cpp.o: VertexBuffer.cpp
CMakeFiles/program.dir/VertexBuffer.cpp.o: CMakeFiles/program.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/darius/Dev/cpp/opengl/test_opengl/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/program.dir/VertexBuffer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/program.dir/VertexBuffer.cpp.o -MF CMakeFiles/program.dir/VertexBuffer.cpp.o.d -o CMakeFiles/program.dir/VertexBuffer.cpp.o -c /home/darius/Dev/cpp/opengl/test_opengl/src/VertexBuffer.cpp

CMakeFiles/program.dir/VertexBuffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/program.dir/VertexBuffer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/darius/Dev/cpp/opengl/test_opengl/src/VertexBuffer.cpp > CMakeFiles/program.dir/VertexBuffer.cpp.i

CMakeFiles/program.dir/VertexBuffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/program.dir/VertexBuffer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/darius/Dev/cpp/opengl/test_opengl/src/VertexBuffer.cpp -o CMakeFiles/program.dir/VertexBuffer.cpp.s

CMakeFiles/program.dir/VertexBufferLayout.cpp.o: CMakeFiles/program.dir/flags.make
CMakeFiles/program.dir/VertexBufferLayout.cpp.o: VertexBufferLayout.cpp
CMakeFiles/program.dir/VertexBufferLayout.cpp.o: CMakeFiles/program.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/darius/Dev/cpp/opengl/test_opengl/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/program.dir/VertexBufferLayout.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/program.dir/VertexBufferLayout.cpp.o -MF CMakeFiles/program.dir/VertexBufferLayout.cpp.o.d -o CMakeFiles/program.dir/VertexBufferLayout.cpp.o -c /home/darius/Dev/cpp/opengl/test_opengl/src/VertexBufferLayout.cpp

CMakeFiles/program.dir/VertexBufferLayout.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/program.dir/VertexBufferLayout.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/darius/Dev/cpp/opengl/test_opengl/src/VertexBufferLayout.cpp > CMakeFiles/program.dir/VertexBufferLayout.cpp.i

CMakeFiles/program.dir/VertexBufferLayout.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/program.dir/VertexBufferLayout.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/darius/Dev/cpp/opengl/test_opengl/src/VertexBufferLayout.cpp -o CMakeFiles/program.dir/VertexBufferLayout.cpp.s

CMakeFiles/program.dir/main.cpp.o: CMakeFiles/program.dir/flags.make
CMakeFiles/program.dir/main.cpp.o: main.cpp
CMakeFiles/program.dir/main.cpp.o: CMakeFiles/program.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/darius/Dev/cpp/opengl/test_opengl/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/program.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/program.dir/main.cpp.o -MF CMakeFiles/program.dir/main.cpp.o.d -o CMakeFiles/program.dir/main.cpp.o -c /home/darius/Dev/cpp/opengl/test_opengl/src/main.cpp

CMakeFiles/program.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/program.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/darius/Dev/cpp/opengl/test_opengl/src/main.cpp > CMakeFiles/program.dir/main.cpp.i

CMakeFiles/program.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/program.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/darius/Dev/cpp/opengl/test_opengl/src/main.cpp -o CMakeFiles/program.dir/main.cpp.s

CMakeFiles/program.dir/shader.cpp.o: CMakeFiles/program.dir/flags.make
CMakeFiles/program.dir/shader.cpp.o: shader.cpp
CMakeFiles/program.dir/shader.cpp.o: CMakeFiles/program.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/darius/Dev/cpp/opengl/test_opengl/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/program.dir/shader.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/program.dir/shader.cpp.o -MF CMakeFiles/program.dir/shader.cpp.o.d -o CMakeFiles/program.dir/shader.cpp.o -c /home/darius/Dev/cpp/opengl/test_opengl/src/shader.cpp

CMakeFiles/program.dir/shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/program.dir/shader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/darius/Dev/cpp/opengl/test_opengl/src/shader.cpp > CMakeFiles/program.dir/shader.cpp.i

CMakeFiles/program.dir/shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/program.dir/shader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/darius/Dev/cpp/opengl/test_opengl/src/shader.cpp -o CMakeFiles/program.dir/shader.cpp.s

# Object files for target program
program_OBJECTS = \
"CMakeFiles/program.dir/IndexBuffer.cpp.o" \
"CMakeFiles/program.dir/Texture.cpp.o" \
"CMakeFiles/program.dir/VertexArray.cpp.o" \
"CMakeFiles/program.dir/VertexBuffer.cpp.o" \
"CMakeFiles/program.dir/VertexBufferLayout.cpp.o" \
"CMakeFiles/program.dir/main.cpp.o" \
"CMakeFiles/program.dir/shader.cpp.o"

# External object files for target program
program_EXTERNAL_OBJECTS =

program: CMakeFiles/program.dir/IndexBuffer.cpp.o
program: CMakeFiles/program.dir/Texture.cpp.o
program: CMakeFiles/program.dir/VertexArray.cpp.o
program: CMakeFiles/program.dir/VertexBuffer.cpp.o
program: CMakeFiles/program.dir/VertexBufferLayout.cpp.o
program: CMakeFiles/program.dir/main.cpp.o
program: CMakeFiles/program.dir/shader.cpp.o
program: CMakeFiles/program.dir/build.make
program: CMakeFiles/program.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/darius/Dev/cpp/opengl/test_opengl/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable program"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/program.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/program.dir/build: program
.PHONY : CMakeFiles/program.dir/build

CMakeFiles/program.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/program.dir/cmake_clean.cmake
.PHONY : CMakeFiles/program.dir/clean

CMakeFiles/program.dir/depend:
	cd /home/darius/Dev/cpp/opengl/test_opengl/src && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/darius/Dev/cpp/opengl/test_opengl/src /home/darius/Dev/cpp/opengl/test_opengl/src /home/darius/Dev/cpp/opengl/test_opengl/src /home/darius/Dev/cpp/opengl/test_opengl/src /home/darius/Dev/cpp/opengl/test_opengl/src/CMakeFiles/program.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/program.dir/depend

