# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Produce verbose output by default.
VERBOSE = 1

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/okuznets/Programming/wolf3d

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/okuznets/Programming/wolf3d/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/wolf3d.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/wolf3d.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/wolf3d.dir/flags.make

CMakeFiles/wolf3d.dir/Srcs/checker.c.o: CMakeFiles/wolf3d.dir/flags.make
CMakeFiles/wolf3d.dir/Srcs/checker.c.o: ../Srcs/checker.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/okuznets/Programming/wolf3d/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/wolf3d.dir/Srcs/checker.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/wolf3d.dir/Srcs/checker.c.o   -c /Users/okuznets/Programming/wolf3d/Srcs/checker.c

CMakeFiles/wolf3d.dir/Srcs/checker.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/wolf3d.dir/Srcs/checker.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/okuznets/Programming/wolf3d/Srcs/checker.c > CMakeFiles/wolf3d.dir/Srcs/checker.c.i

CMakeFiles/wolf3d.dir/Srcs/checker.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/wolf3d.dir/Srcs/checker.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/okuznets/Programming/wolf3d/Srcs/checker.c -o CMakeFiles/wolf3d.dir/Srcs/checker.c.s

CMakeFiles/wolf3d.dir/Srcs/main.c.o: CMakeFiles/wolf3d.dir/flags.make
CMakeFiles/wolf3d.dir/Srcs/main.c.o: ../Srcs/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/okuznets/Programming/wolf3d/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/wolf3d.dir/Srcs/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/wolf3d.dir/Srcs/main.c.o   -c /Users/okuznets/Programming/wolf3d/Srcs/main.c

CMakeFiles/wolf3d.dir/Srcs/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/wolf3d.dir/Srcs/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/okuznets/Programming/wolf3d/Srcs/main.c > CMakeFiles/wolf3d.dir/Srcs/main.c.i

CMakeFiles/wolf3d.dir/Srcs/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/wolf3d.dir/Srcs/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/okuznets/Programming/wolf3d/Srcs/main.c -o CMakeFiles/wolf3d.dir/Srcs/main.c.s

# Object files for target wolf3d
wolf3d_OBJECTS = \
"CMakeFiles/wolf3d.dir/Srcs/checker.c.o" \
"CMakeFiles/wolf3d.dir/Srcs/main.c.o"

# External object files for target wolf3d
wolf3d_EXTERNAL_OBJECTS =

../wolf3d: CMakeFiles/wolf3d.dir/Srcs/checker.c.o
../wolf3d: CMakeFiles/wolf3d.dir/Srcs/main.c.o
../wolf3d: CMakeFiles/wolf3d.dir/build.make
../wolf3d: ../libft/CMakeFiles/liblibft.a.a
../wolf3d: CMakeFiles/wolf3d.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/okuznets/Programming/wolf3d/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable ../wolf3d"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/wolf3d.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/wolf3d.dir/build: ../wolf3d

.PHONY : CMakeFiles/wolf3d.dir/build

CMakeFiles/wolf3d.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/wolf3d.dir/cmake_clean.cmake
.PHONY : CMakeFiles/wolf3d.dir/clean

CMakeFiles/wolf3d.dir/depend:
	cd /Users/okuznets/Programming/wolf3d/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/okuznets/Programming/wolf3d /Users/okuznets/Programming/wolf3d /Users/okuznets/Programming/wolf3d/cmake-build-debug /Users/okuznets/Programming/wolf3d/cmake-build-debug /Users/okuznets/Programming/wolf3d/cmake-build-debug/CMakeFiles/wolf3d.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/wolf3d.dir/depend

