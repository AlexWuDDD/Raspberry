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
include CMakeFiles/slectBaseRot13Server.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/slectBaseRot13Server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/slectBaseRot13Server.dir/flags.make

CMakeFiles/slectBaseRot13Server.dir/libevent/select_base_rot13_server.cpp.o: CMakeFiles/slectBaseRot13Server.dir/flags.make
CMakeFiles/slectBaseRot13Server.dir/libevent/select_base_rot13_server.cpp.o: ../libevent/select_base_rot13_server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.t0bl1udGgi/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/slectBaseRot13Server.dir/libevent/select_base_rot13_server.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/slectBaseRot13Server.dir/libevent/select_base_rot13_server.cpp.o -c /tmp/tmp.t0bl1udGgi/libevent/select_base_rot13_server.cpp

CMakeFiles/slectBaseRot13Server.dir/libevent/select_base_rot13_server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/slectBaseRot13Server.dir/libevent/select_base_rot13_server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/tmp.t0bl1udGgi/libevent/select_base_rot13_server.cpp > CMakeFiles/slectBaseRot13Server.dir/libevent/select_base_rot13_server.cpp.i

CMakeFiles/slectBaseRot13Server.dir/libevent/select_base_rot13_server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/slectBaseRot13Server.dir/libevent/select_base_rot13_server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/tmp.t0bl1udGgi/libevent/select_base_rot13_server.cpp -o CMakeFiles/slectBaseRot13Server.dir/libevent/select_base_rot13_server.cpp.s

# Object files for target slectBaseRot13Server
slectBaseRot13Server_OBJECTS = \
"CMakeFiles/slectBaseRot13Server.dir/libevent/select_base_rot13_server.cpp.o"

# External object files for target slectBaseRot13Server
slectBaseRot13Server_EXTERNAL_OBJECTS =

slectBaseRot13Server: CMakeFiles/slectBaseRot13Server.dir/libevent/select_base_rot13_server.cpp.o
slectBaseRot13Server: CMakeFiles/slectBaseRot13Server.dir/build.make
slectBaseRot13Server: CMakeFiles/slectBaseRot13Server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/tmp/tmp.t0bl1udGgi/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable slectBaseRot13Server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/slectBaseRot13Server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/slectBaseRot13Server.dir/build: slectBaseRot13Server

.PHONY : CMakeFiles/slectBaseRot13Server.dir/build

CMakeFiles/slectBaseRot13Server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/slectBaseRot13Server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/slectBaseRot13Server.dir/clean

CMakeFiles/slectBaseRot13Server.dir/depend:
	cd /tmp/tmp.t0bl1udGgi/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /tmp/tmp.t0bl1udGgi /tmp/tmp.t0bl1udGgi /tmp/tmp.t0bl1udGgi/cmake-build-debug /tmp/tmp.t0bl1udGgi/cmake-build-debug /tmp/tmp.t0bl1udGgi/cmake-build-debug/CMakeFiles/slectBaseRot13Server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/slectBaseRot13Server.dir/depend

