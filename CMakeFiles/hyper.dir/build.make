# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.25.1/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.25.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/balazs/Developer/Git/personal/opengl-engine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/balazs/Developer/Git/personal/opengl-engine

# Include any dependencies generated for this target.
include CMakeFiles/hyper.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/hyper.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/hyper.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hyper.dir/flags.make

CMakeFiles/hyper.dir/src/cpp/Camera.cpp.o: CMakeFiles/hyper.dir/flags.make
CMakeFiles/hyper.dir/src/cpp/Camera.cpp.o: src/cpp/Camera.cpp
CMakeFiles/hyper.dir/src/cpp/Camera.cpp.o: CMakeFiles/hyper.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/balazs/Developer/Git/personal/opengl-engine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hyper.dir/src/cpp/Camera.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hyper.dir/src/cpp/Camera.cpp.o -MF CMakeFiles/hyper.dir/src/cpp/Camera.cpp.o.d -o CMakeFiles/hyper.dir/src/cpp/Camera.cpp.o -c /Users/balazs/Developer/Git/personal/opengl-engine/src/cpp/Camera.cpp

CMakeFiles/hyper.dir/src/cpp/Camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hyper.dir/src/cpp/Camera.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/balazs/Developer/Git/personal/opengl-engine/src/cpp/Camera.cpp > CMakeFiles/hyper.dir/src/cpp/Camera.cpp.i

CMakeFiles/hyper.dir/src/cpp/Camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hyper.dir/src/cpp/Camera.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/balazs/Developer/Git/personal/opengl-engine/src/cpp/Camera.cpp -o CMakeFiles/hyper.dir/src/cpp/Camera.cpp.s

CMakeFiles/hyper.dir/src/cpp/Display.cpp.o: CMakeFiles/hyper.dir/flags.make
CMakeFiles/hyper.dir/src/cpp/Display.cpp.o: src/cpp/Display.cpp
CMakeFiles/hyper.dir/src/cpp/Display.cpp.o: CMakeFiles/hyper.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/balazs/Developer/Git/personal/opengl-engine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/hyper.dir/src/cpp/Display.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hyper.dir/src/cpp/Display.cpp.o -MF CMakeFiles/hyper.dir/src/cpp/Display.cpp.o.d -o CMakeFiles/hyper.dir/src/cpp/Display.cpp.o -c /Users/balazs/Developer/Git/personal/opengl-engine/src/cpp/Display.cpp

CMakeFiles/hyper.dir/src/cpp/Display.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hyper.dir/src/cpp/Display.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/balazs/Developer/Git/personal/opengl-engine/src/cpp/Display.cpp > CMakeFiles/hyper.dir/src/cpp/Display.cpp.i

CMakeFiles/hyper.dir/src/cpp/Display.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hyper.dir/src/cpp/Display.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/balazs/Developer/Git/personal/opengl-engine/src/cpp/Display.cpp -o CMakeFiles/hyper.dir/src/cpp/Display.cpp.s

CMakeFiles/hyper.dir/src/cpp/Framebuffer.cpp.o: CMakeFiles/hyper.dir/flags.make
CMakeFiles/hyper.dir/src/cpp/Framebuffer.cpp.o: src/cpp/Framebuffer.cpp
CMakeFiles/hyper.dir/src/cpp/Framebuffer.cpp.o: CMakeFiles/hyper.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/balazs/Developer/Git/personal/opengl-engine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/hyper.dir/src/cpp/Framebuffer.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hyper.dir/src/cpp/Framebuffer.cpp.o -MF CMakeFiles/hyper.dir/src/cpp/Framebuffer.cpp.o.d -o CMakeFiles/hyper.dir/src/cpp/Framebuffer.cpp.o -c /Users/balazs/Developer/Git/personal/opengl-engine/src/cpp/Framebuffer.cpp

CMakeFiles/hyper.dir/src/cpp/Framebuffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hyper.dir/src/cpp/Framebuffer.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/balazs/Developer/Git/personal/opengl-engine/src/cpp/Framebuffer.cpp > CMakeFiles/hyper.dir/src/cpp/Framebuffer.cpp.i

CMakeFiles/hyper.dir/src/cpp/Framebuffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hyper.dir/src/cpp/Framebuffer.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/balazs/Developer/Git/personal/opengl-engine/src/cpp/Framebuffer.cpp -o CMakeFiles/hyper.dir/src/cpp/Framebuffer.cpp.s

CMakeFiles/hyper.dir/src/cpp/GLSLProgram.cpp.o: CMakeFiles/hyper.dir/flags.make
CMakeFiles/hyper.dir/src/cpp/GLSLProgram.cpp.o: src/cpp/GLSLProgram.cpp
CMakeFiles/hyper.dir/src/cpp/GLSLProgram.cpp.o: CMakeFiles/hyper.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/balazs/Developer/Git/personal/opengl-engine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/hyper.dir/src/cpp/GLSLProgram.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hyper.dir/src/cpp/GLSLProgram.cpp.o -MF CMakeFiles/hyper.dir/src/cpp/GLSLProgram.cpp.o.d -o CMakeFiles/hyper.dir/src/cpp/GLSLProgram.cpp.o -c /Users/balazs/Developer/Git/personal/opengl-engine/src/cpp/GLSLProgram.cpp

CMakeFiles/hyper.dir/src/cpp/GLSLProgram.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hyper.dir/src/cpp/GLSLProgram.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/balazs/Developer/Git/personal/opengl-engine/src/cpp/GLSLProgram.cpp > CMakeFiles/hyper.dir/src/cpp/GLSLProgram.cpp.i

CMakeFiles/hyper.dir/src/cpp/GLSLProgram.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hyper.dir/src/cpp/GLSLProgram.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/balazs/Developer/Git/personal/opengl-engine/src/cpp/GLSLProgram.cpp -o CMakeFiles/hyper.dir/src/cpp/GLSLProgram.cpp.s

CMakeFiles/hyper.dir/src/cpp/Keyboard.cpp.o: CMakeFiles/hyper.dir/flags.make
CMakeFiles/hyper.dir/src/cpp/Keyboard.cpp.o: src/cpp/Keyboard.cpp
CMakeFiles/hyper.dir/src/cpp/Keyboard.cpp.o: CMakeFiles/hyper.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/balazs/Developer/Git/personal/opengl-engine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/hyper.dir/src/cpp/Keyboard.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hyper.dir/src/cpp/Keyboard.cpp.o -MF CMakeFiles/hyper.dir/src/cpp/Keyboard.cpp.o.d -o CMakeFiles/hyper.dir/src/cpp/Keyboard.cpp.o -c /Users/balazs/Developer/Git/personal/opengl-engine/src/cpp/Keyboard.cpp

CMakeFiles/hyper.dir/src/cpp/Keyboard.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hyper.dir/src/cpp/Keyboard.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/balazs/Developer/Git/personal/opengl-engine/src/cpp/Keyboard.cpp > CMakeFiles/hyper.dir/src/cpp/Keyboard.cpp.i

CMakeFiles/hyper.dir/src/cpp/Keyboard.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hyper.dir/src/cpp/Keyboard.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/balazs/Developer/Git/personal/opengl-engine/src/cpp/Keyboard.cpp -o CMakeFiles/hyper.dir/src/cpp/Keyboard.cpp.s

CMakeFiles/hyper.dir/src/cpp/Light.cpp.o: CMakeFiles/hyper.dir/flags.make
CMakeFiles/hyper.dir/src/cpp/Light.cpp.o: src/cpp/Light.cpp
CMakeFiles/hyper.dir/src/cpp/Light.cpp.o: CMakeFiles/hyper.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/balazs/Developer/Git/personal/opengl-engine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/hyper.dir/src/cpp/Light.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hyper.dir/src/cpp/Light.cpp.o -MF CMakeFiles/hyper.dir/src/cpp/Light.cpp.o.d -o CMakeFiles/hyper.dir/src/cpp/Light.cpp.o -c /Users/balazs/Developer/Git/personal/opengl-engine/src/cpp/Light.cpp

CMakeFiles/hyper.dir/src/cpp/Light.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hyper.dir/src/cpp/Light.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/balazs/Developer/Git/personal/opengl-engine/src/cpp/Light.cpp > CMakeFiles/hyper.dir/src/cpp/Light.cpp.i

CMakeFiles/hyper.dir/src/cpp/Light.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hyper.dir/src/cpp/Light.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/balazs/Developer/Git/personal/opengl-engine/src/cpp/Light.cpp -o CMakeFiles/hyper.dir/src/cpp/Light.cpp.s

CMakeFiles/hyper.dir/src/cpp/Mesh.cpp.o: CMakeFiles/hyper.dir/flags.make
CMakeFiles/hyper.dir/src/cpp/Mesh.cpp.o: src/cpp/Mesh.cpp
CMakeFiles/hyper.dir/src/cpp/Mesh.cpp.o: CMakeFiles/hyper.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/balazs/Developer/Git/personal/opengl-engine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/hyper.dir/src/cpp/Mesh.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hyper.dir/src/cpp/Mesh.cpp.o -MF CMakeFiles/hyper.dir/src/cpp/Mesh.cpp.o.d -o CMakeFiles/hyper.dir/src/cpp/Mesh.cpp.o -c /Users/balazs/Developer/Git/personal/opengl-engine/src/cpp/Mesh.cpp

CMakeFiles/hyper.dir/src/cpp/Mesh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hyper.dir/src/cpp/Mesh.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/balazs/Developer/Git/personal/opengl-engine/src/cpp/Mesh.cpp > CMakeFiles/hyper.dir/src/cpp/Mesh.cpp.i

CMakeFiles/hyper.dir/src/cpp/Mesh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hyper.dir/src/cpp/Mesh.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/balazs/Developer/Git/personal/opengl-engine/src/cpp/Mesh.cpp -o CMakeFiles/hyper.dir/src/cpp/Mesh.cpp.s

CMakeFiles/hyper.dir/src/cpp/Model.cpp.o: CMakeFiles/hyper.dir/flags.make
CMakeFiles/hyper.dir/src/cpp/Model.cpp.o: src/cpp/Model.cpp
CMakeFiles/hyper.dir/src/cpp/Model.cpp.o: CMakeFiles/hyper.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/balazs/Developer/Git/personal/opengl-engine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/hyper.dir/src/cpp/Model.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hyper.dir/src/cpp/Model.cpp.o -MF CMakeFiles/hyper.dir/src/cpp/Model.cpp.o.d -o CMakeFiles/hyper.dir/src/cpp/Model.cpp.o -c /Users/balazs/Developer/Git/personal/opengl-engine/src/cpp/Model.cpp

CMakeFiles/hyper.dir/src/cpp/Model.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hyper.dir/src/cpp/Model.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/balazs/Developer/Git/personal/opengl-engine/src/cpp/Model.cpp > CMakeFiles/hyper.dir/src/cpp/Model.cpp.i

CMakeFiles/hyper.dir/src/cpp/Model.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hyper.dir/src/cpp/Model.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/balazs/Developer/Git/personal/opengl-engine/src/cpp/Model.cpp -o CMakeFiles/hyper.dir/src/cpp/Model.cpp.s

CMakeFiles/hyper.dir/src/cpp/OBJLoader.cpp.o: CMakeFiles/hyper.dir/flags.make
CMakeFiles/hyper.dir/src/cpp/OBJLoader.cpp.o: src/cpp/OBJLoader.cpp
CMakeFiles/hyper.dir/src/cpp/OBJLoader.cpp.o: CMakeFiles/hyper.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/balazs/Developer/Git/personal/opengl-engine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/hyper.dir/src/cpp/OBJLoader.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hyper.dir/src/cpp/OBJLoader.cpp.o -MF CMakeFiles/hyper.dir/src/cpp/OBJLoader.cpp.o.d -o CMakeFiles/hyper.dir/src/cpp/OBJLoader.cpp.o -c /Users/balazs/Developer/Git/personal/opengl-engine/src/cpp/OBJLoader.cpp

CMakeFiles/hyper.dir/src/cpp/OBJLoader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hyper.dir/src/cpp/OBJLoader.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/balazs/Developer/Git/personal/opengl-engine/src/cpp/OBJLoader.cpp > CMakeFiles/hyper.dir/src/cpp/OBJLoader.cpp.i

CMakeFiles/hyper.dir/src/cpp/OBJLoader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hyper.dir/src/cpp/OBJLoader.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/balazs/Developer/Git/personal/opengl-engine/src/cpp/OBJLoader.cpp -o CMakeFiles/hyper.dir/src/cpp/OBJLoader.cpp.s

CMakeFiles/hyper.dir/src/cpp/Program.cpp.o: CMakeFiles/hyper.dir/flags.make
CMakeFiles/hyper.dir/src/cpp/Program.cpp.o: src/cpp/Program.cpp
CMakeFiles/hyper.dir/src/cpp/Program.cpp.o: CMakeFiles/hyper.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/balazs/Developer/Git/personal/opengl-engine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/hyper.dir/src/cpp/Program.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hyper.dir/src/cpp/Program.cpp.o -MF CMakeFiles/hyper.dir/src/cpp/Program.cpp.o.d -o CMakeFiles/hyper.dir/src/cpp/Program.cpp.o -c /Users/balazs/Developer/Git/personal/opengl-engine/src/cpp/Program.cpp

CMakeFiles/hyper.dir/src/cpp/Program.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hyper.dir/src/cpp/Program.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/balazs/Developer/Git/personal/opengl-engine/src/cpp/Program.cpp > CMakeFiles/hyper.dir/src/cpp/Program.cpp.i

CMakeFiles/hyper.dir/src/cpp/Program.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hyper.dir/src/cpp/Program.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/balazs/Developer/Git/personal/opengl-engine/src/cpp/Program.cpp -o CMakeFiles/hyper.dir/src/cpp/Program.cpp.s

CMakeFiles/hyper.dir/src/cpp/Scene.cpp.o: CMakeFiles/hyper.dir/flags.make
CMakeFiles/hyper.dir/src/cpp/Scene.cpp.o: src/cpp/Scene.cpp
CMakeFiles/hyper.dir/src/cpp/Scene.cpp.o: CMakeFiles/hyper.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/balazs/Developer/Git/personal/opengl-engine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/hyper.dir/src/cpp/Scene.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hyper.dir/src/cpp/Scene.cpp.o -MF CMakeFiles/hyper.dir/src/cpp/Scene.cpp.o.d -o CMakeFiles/hyper.dir/src/cpp/Scene.cpp.o -c /Users/balazs/Developer/Git/personal/opengl-engine/src/cpp/Scene.cpp

CMakeFiles/hyper.dir/src/cpp/Scene.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hyper.dir/src/cpp/Scene.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/balazs/Developer/Git/personal/opengl-engine/src/cpp/Scene.cpp > CMakeFiles/hyper.dir/src/cpp/Scene.cpp.i

CMakeFiles/hyper.dir/src/cpp/Scene.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hyper.dir/src/cpp/Scene.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/balazs/Developer/Git/personal/opengl-engine/src/cpp/Scene.cpp -o CMakeFiles/hyper.dir/src/cpp/Scene.cpp.s

CMakeFiles/hyper.dir/src/cpp/Texture.cpp.o: CMakeFiles/hyper.dir/flags.make
CMakeFiles/hyper.dir/src/cpp/Texture.cpp.o: src/cpp/Texture.cpp
CMakeFiles/hyper.dir/src/cpp/Texture.cpp.o: CMakeFiles/hyper.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/balazs/Developer/Git/personal/opengl-engine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/hyper.dir/src/cpp/Texture.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hyper.dir/src/cpp/Texture.cpp.o -MF CMakeFiles/hyper.dir/src/cpp/Texture.cpp.o.d -o CMakeFiles/hyper.dir/src/cpp/Texture.cpp.o -c /Users/balazs/Developer/Git/personal/opengl-engine/src/cpp/Texture.cpp

CMakeFiles/hyper.dir/src/cpp/Texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hyper.dir/src/cpp/Texture.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/balazs/Developer/Git/personal/opengl-engine/src/cpp/Texture.cpp > CMakeFiles/hyper.dir/src/cpp/Texture.cpp.i

CMakeFiles/hyper.dir/src/cpp/Texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hyper.dir/src/cpp/Texture.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/balazs/Developer/Git/personal/opengl-engine/src/cpp/Texture.cpp -o CMakeFiles/hyper.dir/src/cpp/Texture.cpp.s

CMakeFiles/hyper.dir/src/cpp/Window.cpp.o: CMakeFiles/hyper.dir/flags.make
CMakeFiles/hyper.dir/src/cpp/Window.cpp.o: src/cpp/Window.cpp
CMakeFiles/hyper.dir/src/cpp/Window.cpp.o: CMakeFiles/hyper.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/balazs/Developer/Git/personal/opengl-engine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/hyper.dir/src/cpp/Window.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hyper.dir/src/cpp/Window.cpp.o -MF CMakeFiles/hyper.dir/src/cpp/Window.cpp.o.d -o CMakeFiles/hyper.dir/src/cpp/Window.cpp.o -c /Users/balazs/Developer/Git/personal/opengl-engine/src/cpp/Window.cpp

CMakeFiles/hyper.dir/src/cpp/Window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hyper.dir/src/cpp/Window.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/balazs/Developer/Git/personal/opengl-engine/src/cpp/Window.cpp > CMakeFiles/hyper.dir/src/cpp/Window.cpp.i

CMakeFiles/hyper.dir/src/cpp/Window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hyper.dir/src/cpp/Window.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/balazs/Developer/Git/personal/opengl-engine/src/cpp/Window.cpp -o CMakeFiles/hyper.dir/src/cpp/Window.cpp.s

CMakeFiles/hyper.dir/src/cpp/App.cpp.o: CMakeFiles/hyper.dir/flags.make
CMakeFiles/hyper.dir/src/cpp/App.cpp.o: src/cpp/App.cpp
CMakeFiles/hyper.dir/src/cpp/App.cpp.o: CMakeFiles/hyper.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/balazs/Developer/Git/personal/opengl-engine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/hyper.dir/src/cpp/App.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hyper.dir/src/cpp/App.cpp.o -MF CMakeFiles/hyper.dir/src/cpp/App.cpp.o.d -o CMakeFiles/hyper.dir/src/cpp/App.cpp.o -c /Users/balazs/Developer/Git/personal/opengl-engine/src/cpp/App.cpp

CMakeFiles/hyper.dir/src/cpp/App.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hyper.dir/src/cpp/App.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/balazs/Developer/Git/personal/opengl-engine/src/cpp/App.cpp > CMakeFiles/hyper.dir/src/cpp/App.cpp.i

CMakeFiles/hyper.dir/src/cpp/App.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hyper.dir/src/cpp/App.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/balazs/Developer/Git/personal/opengl-engine/src/cpp/App.cpp -o CMakeFiles/hyper.dir/src/cpp/App.cpp.s

# Object files for target hyper
hyper_OBJECTS = \
"CMakeFiles/hyper.dir/src/cpp/Camera.cpp.o" \
"CMakeFiles/hyper.dir/src/cpp/Display.cpp.o" \
"CMakeFiles/hyper.dir/src/cpp/Framebuffer.cpp.o" \
"CMakeFiles/hyper.dir/src/cpp/GLSLProgram.cpp.o" \
"CMakeFiles/hyper.dir/src/cpp/Keyboard.cpp.o" \
"CMakeFiles/hyper.dir/src/cpp/Light.cpp.o" \
"CMakeFiles/hyper.dir/src/cpp/Mesh.cpp.o" \
"CMakeFiles/hyper.dir/src/cpp/Model.cpp.o" \
"CMakeFiles/hyper.dir/src/cpp/OBJLoader.cpp.o" \
"CMakeFiles/hyper.dir/src/cpp/Program.cpp.o" \
"CMakeFiles/hyper.dir/src/cpp/Scene.cpp.o" \
"CMakeFiles/hyper.dir/src/cpp/Texture.cpp.o" \
"CMakeFiles/hyper.dir/src/cpp/Window.cpp.o" \
"CMakeFiles/hyper.dir/src/cpp/App.cpp.o"

# External object files for target hyper
hyper_EXTERNAL_OBJECTS =

bin/hyper: CMakeFiles/hyper.dir/src/cpp/Camera.cpp.o
bin/hyper: CMakeFiles/hyper.dir/src/cpp/Display.cpp.o
bin/hyper: CMakeFiles/hyper.dir/src/cpp/Framebuffer.cpp.o
bin/hyper: CMakeFiles/hyper.dir/src/cpp/GLSLProgram.cpp.o
bin/hyper: CMakeFiles/hyper.dir/src/cpp/Keyboard.cpp.o
bin/hyper: CMakeFiles/hyper.dir/src/cpp/Light.cpp.o
bin/hyper: CMakeFiles/hyper.dir/src/cpp/Mesh.cpp.o
bin/hyper: CMakeFiles/hyper.dir/src/cpp/Model.cpp.o
bin/hyper: CMakeFiles/hyper.dir/src/cpp/OBJLoader.cpp.o
bin/hyper: CMakeFiles/hyper.dir/src/cpp/Program.cpp.o
bin/hyper: CMakeFiles/hyper.dir/src/cpp/Scene.cpp.o
bin/hyper: CMakeFiles/hyper.dir/src/cpp/Texture.cpp.o
bin/hyper: CMakeFiles/hyper.dir/src/cpp/Window.cpp.o
bin/hyper: CMakeFiles/hyper.dir/src/cpp/App.cpp.o
bin/hyper: CMakeFiles/hyper.dir/build.make
bin/hyper: /usr/local/lib/libglfw3.a
bin/hyper: /opt/homebrew/lib/libGLEW.dylib
bin/hyper: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX13.1.sdk/System/Library/Frameworks/OpenGL.framework/OpenGL.tbd
bin/hyper: CMakeFiles/hyper.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/balazs/Developer/Git/personal/opengl-engine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Linking CXX executable bin/hyper"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hyper.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hyper.dir/build: bin/hyper
.PHONY : CMakeFiles/hyper.dir/build

CMakeFiles/hyper.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hyper.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hyper.dir/clean

CMakeFiles/hyper.dir/depend:
	cd /Users/balazs/Developer/Git/personal/opengl-engine && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/balazs/Developer/Git/personal/opengl-engine /Users/balazs/Developer/Git/personal/opengl-engine /Users/balazs/Developer/Git/personal/opengl-engine /Users/balazs/Developer/Git/personal/opengl-engine /Users/balazs/Developer/Git/personal/opengl-engine/CMakeFiles/hyper.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hyper.dir/depend

