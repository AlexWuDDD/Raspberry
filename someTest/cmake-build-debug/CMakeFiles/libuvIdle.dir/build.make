# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /tmp/tmp.t0bl1udGgi

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /tmp/tmp.t0bl1udGgi/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/libuvIdle.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/libuvIdle.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/libuvIdle.dir/flags.make

CMakeFiles/libuvIdle.dir/libuv/helloworld/main.cpp.o: CMakeFiles/libuvIdle.dir/flags.make
CMakeFiles/libuvIdle.dir/libuv/helloworld/main.cpp.o: ../libuv/helloworld/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.t0bl1udGgi/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/libuvIdle.dir/libuv/helloworld/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/libuvIdle.dir/libuv/helloworld/main.cpp.o -c /tmp/tmp.t0bl1udGgi/libuv/helloworld/main.cpp

CMakeFiles/libuvIdle.dir/libuv/helloworld/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libuvIdle.dir/libuv/helloworld/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/tmp.t0bl1udGgi/libuv/helloworld/main.cpp > CMakeFiles/libuvIdle.dir/libuv/helloworld/main.cpp.i

CMakeFiles/libuvIdle.dir/libuv/helloworld/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libuvIdle.dir/libuv/helloworld/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/tmp.t0bl1udGgi/libuv/helloworld/main.cpp -o CMakeFiles/libuvIdle.dir/libuv/helloworld/main.cpp.s

# Object files for target libuvIdle
libuvIdle_OBJECTS = \
"CMakeFiles/libuvIdle.dir/libuv/helloworld/main.cpp.o"

# External object files for target libuvIdle
libuvIdle_EXTERNAL_OBJECTS =

libuvIdle: CMakeFiles/libuvIdle.dir/libuv/helloworld/main.cpp.o
libuvIdle: CMakeFiles/libuvIdle.dir/build.make
libuvIdle: CMakeFiles/libuvIdle.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/tmp/tmp.t0bl1udGgi/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable libuvIdle"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/libuvIdle.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/libuvIdle.dir/build: libuvIdle

.PHONY : CMakeFiles/libuvIdle.dir/build

CMakeFiles/libuvIdle.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/libuvIdle.dir/cmake_clean.cmake
.PHONY : CMakeFiles/libuvIdle.dir/clean

CMakeFiles/libuvIdle.dir/depend:
	cd /tmp/tmp.t0bl1udGgi/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /tmp/tmp.t0bl1udGgi /tmp/tmp.t0bl1udGgi /tmp/tmp.t0bl1udGgi/cmake-build-debug /tmp/tmp.t0bl1udGgi/cmake-build-debug /tmp/tmp.t0bl1udGgi/cmake-build-debug/CMakeFiles/libuvIdle.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/libuvIdle.dir/depend
