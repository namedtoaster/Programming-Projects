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
CMAKE_SOURCE_DIR = /home/dave/Documents/git/programming-projects/programming/cpp/open-gl/learnopengldotcom/4-Textures/libraries/glfw

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dave/Documents/git/programming-projects/programming/cpp/open-gl/learnopengldotcom/4-Textures/libraries/glfw/build

# Include any dependencies generated for this target.
include tests/CMakeFiles/events.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/events.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/events.dir/flags.make

tests/CMakeFiles/events.dir/events.c.o: tests/CMakeFiles/events.dir/flags.make
tests/CMakeFiles/events.dir/events.c.o: ../tests/events.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dave/Documents/git/programming-projects/programming/cpp/open-gl/learnopengldotcom/4-Textures/libraries/glfw/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object tests/CMakeFiles/events.dir/events.c.o"
	cd /home/dave/Documents/git/programming-projects/programming/cpp/open-gl/learnopengldotcom/4-Textures/libraries/glfw/build/tests && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/events.dir/events.c.o   -c /home/dave/Documents/git/programming-projects/programming/cpp/open-gl/learnopengldotcom/4-Textures/libraries/glfw/tests/events.c

tests/CMakeFiles/events.dir/events.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/events.dir/events.c.i"
	cd /home/dave/Documents/git/programming-projects/programming/cpp/open-gl/learnopengldotcom/4-Textures/libraries/glfw/build/tests && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/dave/Documents/git/programming-projects/programming/cpp/open-gl/learnopengldotcom/4-Textures/libraries/glfw/tests/events.c > CMakeFiles/events.dir/events.c.i

tests/CMakeFiles/events.dir/events.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/events.dir/events.c.s"
	cd /home/dave/Documents/git/programming-projects/programming/cpp/open-gl/learnopengldotcom/4-Textures/libraries/glfw/build/tests && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/dave/Documents/git/programming-projects/programming/cpp/open-gl/learnopengldotcom/4-Textures/libraries/glfw/tests/events.c -o CMakeFiles/events.dir/events.c.s

tests/CMakeFiles/events.dir/events.c.o.requires:

.PHONY : tests/CMakeFiles/events.dir/events.c.o.requires

tests/CMakeFiles/events.dir/events.c.o.provides: tests/CMakeFiles/events.dir/events.c.o.requires
	$(MAKE) -f tests/CMakeFiles/events.dir/build.make tests/CMakeFiles/events.dir/events.c.o.provides.build
.PHONY : tests/CMakeFiles/events.dir/events.c.o.provides

tests/CMakeFiles/events.dir/events.c.o.provides.build: tests/CMakeFiles/events.dir/events.c.o


tests/CMakeFiles/events.dir/__/deps/getopt.c.o: tests/CMakeFiles/events.dir/flags.make
tests/CMakeFiles/events.dir/__/deps/getopt.c.o: ../deps/getopt.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dave/Documents/git/programming-projects/programming/cpp/open-gl/learnopengldotcom/4-Textures/libraries/glfw/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object tests/CMakeFiles/events.dir/__/deps/getopt.c.o"
	cd /home/dave/Documents/git/programming-projects/programming/cpp/open-gl/learnopengldotcom/4-Textures/libraries/glfw/build/tests && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/events.dir/__/deps/getopt.c.o   -c /home/dave/Documents/git/programming-projects/programming/cpp/open-gl/learnopengldotcom/4-Textures/libraries/glfw/deps/getopt.c

tests/CMakeFiles/events.dir/__/deps/getopt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/events.dir/__/deps/getopt.c.i"
	cd /home/dave/Documents/git/programming-projects/programming/cpp/open-gl/learnopengldotcom/4-Textures/libraries/glfw/build/tests && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/dave/Documents/git/programming-projects/programming/cpp/open-gl/learnopengldotcom/4-Textures/libraries/glfw/deps/getopt.c > CMakeFiles/events.dir/__/deps/getopt.c.i

tests/CMakeFiles/events.dir/__/deps/getopt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/events.dir/__/deps/getopt.c.s"
	cd /home/dave/Documents/git/programming-projects/programming/cpp/open-gl/learnopengldotcom/4-Textures/libraries/glfw/build/tests && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/dave/Documents/git/programming-projects/programming/cpp/open-gl/learnopengldotcom/4-Textures/libraries/glfw/deps/getopt.c -o CMakeFiles/events.dir/__/deps/getopt.c.s

tests/CMakeFiles/events.dir/__/deps/getopt.c.o.requires:

.PHONY : tests/CMakeFiles/events.dir/__/deps/getopt.c.o.requires

tests/CMakeFiles/events.dir/__/deps/getopt.c.o.provides: tests/CMakeFiles/events.dir/__/deps/getopt.c.o.requires
	$(MAKE) -f tests/CMakeFiles/events.dir/build.make tests/CMakeFiles/events.dir/__/deps/getopt.c.o.provides.build
.PHONY : tests/CMakeFiles/events.dir/__/deps/getopt.c.o.provides

tests/CMakeFiles/events.dir/__/deps/getopt.c.o.provides.build: tests/CMakeFiles/events.dir/__/deps/getopt.c.o


tests/CMakeFiles/events.dir/__/deps/glad.c.o: tests/CMakeFiles/events.dir/flags.make
tests/CMakeFiles/events.dir/__/deps/glad.c.o: ../deps/glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dave/Documents/git/programming-projects/programming/cpp/open-gl/learnopengldotcom/4-Textures/libraries/glfw/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object tests/CMakeFiles/events.dir/__/deps/glad.c.o"
	cd /home/dave/Documents/git/programming-projects/programming/cpp/open-gl/learnopengldotcom/4-Textures/libraries/glfw/build/tests && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/events.dir/__/deps/glad.c.o   -c /home/dave/Documents/git/programming-projects/programming/cpp/open-gl/learnopengldotcom/4-Textures/libraries/glfw/deps/glad.c

tests/CMakeFiles/events.dir/__/deps/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/events.dir/__/deps/glad.c.i"
	cd /home/dave/Documents/git/programming-projects/programming/cpp/open-gl/learnopengldotcom/4-Textures/libraries/glfw/build/tests && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/dave/Documents/git/programming-projects/programming/cpp/open-gl/learnopengldotcom/4-Textures/libraries/glfw/deps/glad.c > CMakeFiles/events.dir/__/deps/glad.c.i

tests/CMakeFiles/events.dir/__/deps/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/events.dir/__/deps/glad.c.s"
	cd /home/dave/Documents/git/programming-projects/programming/cpp/open-gl/learnopengldotcom/4-Textures/libraries/glfw/build/tests && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/dave/Documents/git/programming-projects/programming/cpp/open-gl/learnopengldotcom/4-Textures/libraries/glfw/deps/glad.c -o CMakeFiles/events.dir/__/deps/glad.c.s

tests/CMakeFiles/events.dir/__/deps/glad.c.o.requires:

.PHONY : tests/CMakeFiles/events.dir/__/deps/glad.c.o.requires

tests/CMakeFiles/events.dir/__/deps/glad.c.o.provides: tests/CMakeFiles/events.dir/__/deps/glad.c.o.requires
	$(MAKE) -f tests/CMakeFiles/events.dir/build.make tests/CMakeFiles/events.dir/__/deps/glad.c.o.provides.build
.PHONY : tests/CMakeFiles/events.dir/__/deps/glad.c.o.provides

tests/CMakeFiles/events.dir/__/deps/glad.c.o.provides.build: tests/CMakeFiles/events.dir/__/deps/glad.c.o


# Object files for target events
events_OBJECTS = \
"CMakeFiles/events.dir/events.c.o" \
"CMakeFiles/events.dir/__/deps/getopt.c.o" \
"CMakeFiles/events.dir/__/deps/glad.c.o"

# External object files for target events
events_EXTERNAL_OBJECTS =

tests/events: tests/CMakeFiles/events.dir/events.c.o
tests/events: tests/CMakeFiles/events.dir/__/deps/getopt.c.o
tests/events: tests/CMakeFiles/events.dir/__/deps/glad.c.o
tests/events: tests/CMakeFiles/events.dir/build.make
tests/events: src/libglfw3.a
tests/events: /usr/lib/x86_64-linux-gnu/libm.so
tests/events: /usr/lib/x86_64-linux-gnu/librt.so
tests/events: /usr/lib/x86_64-linux-gnu/libm.so
tests/events: /usr/lib/x86_64-linux-gnu/libX11.so
tests/events: tests/CMakeFiles/events.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dave/Documents/git/programming-projects/programming/cpp/open-gl/learnopengldotcom/4-Textures/libraries/glfw/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable events"
	cd /home/dave/Documents/git/programming-projects/programming/cpp/open-gl/learnopengldotcom/4-Textures/libraries/glfw/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/events.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/events.dir/build: tests/events

.PHONY : tests/CMakeFiles/events.dir/build

tests/CMakeFiles/events.dir/requires: tests/CMakeFiles/events.dir/events.c.o.requires
tests/CMakeFiles/events.dir/requires: tests/CMakeFiles/events.dir/__/deps/getopt.c.o.requires
tests/CMakeFiles/events.dir/requires: tests/CMakeFiles/events.dir/__/deps/glad.c.o.requires

.PHONY : tests/CMakeFiles/events.dir/requires

tests/CMakeFiles/events.dir/clean:
	cd /home/dave/Documents/git/programming-projects/programming/cpp/open-gl/learnopengldotcom/4-Textures/libraries/glfw/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/events.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/events.dir/clean

tests/CMakeFiles/events.dir/depend:
	cd /home/dave/Documents/git/programming-projects/programming/cpp/open-gl/learnopengldotcom/4-Textures/libraries/glfw/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dave/Documents/git/programming-projects/programming/cpp/open-gl/learnopengldotcom/4-Textures/libraries/glfw /home/dave/Documents/git/programming-projects/programming/cpp/open-gl/learnopengldotcom/4-Textures/libraries/glfw/tests /home/dave/Documents/git/programming-projects/programming/cpp/open-gl/learnopengldotcom/4-Textures/libraries/glfw/build /home/dave/Documents/git/programming-projects/programming/cpp/open-gl/learnopengldotcom/4-Textures/libraries/glfw/build/tests /home/dave/Documents/git/programming-projects/programming/cpp/open-gl/learnopengldotcom/4-Textures/libraries/glfw/build/tests/CMakeFiles/events.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/events.dir/depend

