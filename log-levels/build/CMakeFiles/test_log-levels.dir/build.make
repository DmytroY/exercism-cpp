# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.31

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\YAKOVD\cmake\cmake-3.31.4\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\YAKOVD\cmake\cmake-3.31.4\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\YAKOVD\Exercism\cpp\log-levels

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\YAKOVD\Exercism\cpp\log-levels\build

# Utility rule file for test_log-levels.

# Include any custom commands dependencies for this target.
include CMakeFiles/test_log-levels.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/test_log-levels.dir/progress.make

CMakeFiles/test_log-levels: log-levels.exe
	.\log-levels.exe

CMakeFiles/test_log-levels.dir/codegen:
.PHONY : CMakeFiles/test_log-levels.dir/codegen

test_log-levels: CMakeFiles/test_log-levels
test_log-levels: CMakeFiles/test_log-levels.dir/build.make
.PHONY : test_log-levels

# Rule to build all files generated by this target.
CMakeFiles/test_log-levels.dir/build: test_log-levels
.PHONY : CMakeFiles/test_log-levels.dir/build

CMakeFiles/test_log-levels.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\test_log-levels.dir\cmake_clean.cmake
.PHONY : CMakeFiles/test_log-levels.dir/clean

CMakeFiles/test_log-levels.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\YAKOVD\Exercism\cpp\log-levels C:\Users\YAKOVD\Exercism\cpp\log-levels C:\Users\YAKOVD\Exercism\cpp\log-levels\build C:\Users\YAKOVD\Exercism\cpp\log-levels\build C:\Users\YAKOVD\Exercism\cpp\log-levels\build\CMakeFiles\test_log-levels.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/test_log-levels.dir/depend

