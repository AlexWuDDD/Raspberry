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
CMAKE_SOURCE_DIR = /tmp/tmp.FrVZqkHuv3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /tmp/tmp.FrVZqkHuv3/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/FileIOTest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/FileIOTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/FileIOTest.dir/flags.make

CMakeFiles/FileIOTest.dir/FileIO/test.cpp.o: CMakeFiles/FileIOTest.dir/flags.make
CMakeFiles/FileIOTest.dir/FileIO/test.cpp.o: ../FileIO/test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.FrVZqkHuv3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/FileIOTest.dir/FileIO/test.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FileIOTest.dir/FileIO/test.cpp.o -c /tmp/tmp.FrVZqkHuv3/FileIO/test.cpp

CMakeFiles/FileIOTest.dir/FileIO/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FileIOTest.dir/FileIO/test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/tmp.FrVZqkHuv3/FileIO/test.cpp > CMakeFiles/FileIOTest.dir/FileIO/test.cpp.i

CMakeFiles/FileIOTest.dir/FileIO/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FileIOTest.dir/FileIO/test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/tmp.FrVZqkHuv3/FileIO/test.cpp -o CMakeFiles/FileIOTest.dir/FileIO/test.cpp.s

# Object files for target FileIOTest
FileIOTest_OBJECTS = \
"CMakeFiles/FileIOTest.dir/FileIO/test.cpp.o"

# External object files for target FileIOTest
FileIOTest_EXTERNAL_OBJECTS =

FileIOTest: CMakeFiles/FileIOTest.dir/FileIO/test.cpp.o
FileIOTest: CMakeFiles/FileIOTest.dir/build.make
FileIOTest: CMakeFiles/FileIOTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/tmp/tmp.FrVZqkHuv3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable FileIOTest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FileIOTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/FileIOTest.dir/build: FileIOTest

.PHONY : CMakeFiles/FileIOTest.dir/build

CMakeFiles/FileIOTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/FileIOTest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/FileIOTest.dir/clean

CMakeFiles/FileIOTest.dir/depend:
	cd /tmp/tmp.FrVZqkHuv3/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /tmp/tmp.FrVZqkHuv3 /tmp/tmp.FrVZqkHuv3 /tmp/tmp.FrVZqkHuv3/cmake-build-debug /tmp/tmp.FrVZqkHuv3/cmake-build-debug /tmp/tmp.FrVZqkHuv3/cmake-build-debug/CMakeFiles/FileIOTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/FileIOTest.dir/depend

