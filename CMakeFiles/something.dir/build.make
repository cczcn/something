# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/ccz/gitSpace/someting

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ccz/gitSpace/someting

# Include any dependencies generated for this target.
include CMakeFiles/something.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/something.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/something.dir/flags.make

CMakeFiles/something.dir/src/hellotest.cpp.o: CMakeFiles/something.dir/flags.make
CMakeFiles/something.dir/src/hellotest.cpp.o: src/hellotest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ccz/gitSpace/someting/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/something.dir/src/hellotest.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/something.dir/src/hellotest.cpp.o -c /home/ccz/gitSpace/someting/src/hellotest.cpp

CMakeFiles/something.dir/src/hellotest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/something.dir/src/hellotest.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ccz/gitSpace/someting/src/hellotest.cpp > CMakeFiles/something.dir/src/hellotest.cpp.i

CMakeFiles/something.dir/src/hellotest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/something.dir/src/hellotest.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ccz/gitSpace/someting/src/hellotest.cpp -o CMakeFiles/something.dir/src/hellotest.cpp.s

CMakeFiles/something.dir/src/hellotest.cpp.o.requires:

.PHONY : CMakeFiles/something.dir/src/hellotest.cpp.o.requires

CMakeFiles/something.dir/src/hellotest.cpp.o.provides: CMakeFiles/something.dir/src/hellotest.cpp.o.requires
	$(MAKE) -f CMakeFiles/something.dir/build.make CMakeFiles/something.dir/src/hellotest.cpp.o.provides.build
.PHONY : CMakeFiles/something.dir/src/hellotest.cpp.o.provides

CMakeFiles/something.dir/src/hellotest.cpp.o.provides.build: CMakeFiles/something.dir/src/hellotest.cpp.o


# Object files for target something
something_OBJECTS = \
"CMakeFiles/something.dir/src/hellotest.cpp.o"

# External object files for target something
something_EXTERNAL_OBJECTS =

something: CMakeFiles/something.dir/src/hellotest.cpp.o
something: CMakeFiles/something.dir/build.make
something: CMakeFiles/something.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ccz/gitSpace/someting/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable something"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/something.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/something.dir/build: something

.PHONY : CMakeFiles/something.dir/build

CMakeFiles/something.dir/requires: CMakeFiles/something.dir/src/hellotest.cpp.o.requires

.PHONY : CMakeFiles/something.dir/requires

CMakeFiles/something.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/something.dir/cmake_clean.cmake
.PHONY : CMakeFiles/something.dir/clean

CMakeFiles/something.dir/depend:
	cd /home/ccz/gitSpace/someting && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ccz/gitSpace/someting /home/ccz/gitSpace/someting /home/ccz/gitSpace/someting /home/ccz/gitSpace/someting /home/ccz/gitSpace/someting/CMakeFiles/something.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/something.dir/depend

