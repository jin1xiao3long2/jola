# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\XM\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\202.7660.37\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\XM\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\202.7660.37\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\CPP\2020_5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\CPP\2020_5\cmake-build-debug

# Include any dependencies generated for this target.
include tcode/CMakeFiles/expr.dir/depend.make

# Include the progress variables for this target.
include tcode/CMakeFiles/expr.dir/progress.make

# Include the compile flags for this target's objects.
include tcode/CMakeFiles/expr.dir/flags.make

tcode/CMakeFiles/expr.dir/expression.cpp.obj: tcode/CMakeFiles/expr.dir/flags.make
tcode/CMakeFiles/expr.dir/expression.cpp.obj: ../tcode/expression.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\CPP\2020_5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tcode/CMakeFiles/expr.dir/expression.cpp.obj"
	cd /d C:\CPP\2020_5\cmake-build-debug\tcode && C:\BC\C\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\expr.dir\expression.cpp.obj -c C:\CPP\2020_5\tcode\expression.cpp

tcode/CMakeFiles/expr.dir/expression.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/expr.dir/expression.cpp.i"
	cd /d C:\CPP\2020_5\cmake-build-debug\tcode && C:\BC\C\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\CPP\2020_5\tcode\expression.cpp > CMakeFiles\expr.dir\expression.cpp.i

tcode/CMakeFiles/expr.dir/expression.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/expr.dir/expression.cpp.s"
	cd /d C:\CPP\2020_5\cmake-build-debug\tcode && C:\BC\C\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\CPP\2020_5\tcode\expression.cpp -o CMakeFiles\expr.dir\expression.cpp.s

# Object files for target expr
expr_OBJECTS = \
"CMakeFiles/expr.dir/expression.cpp.obj"

# External object files for target expr
expr_EXTERNAL_OBJECTS =

tcode/expr.exe: tcode/CMakeFiles/expr.dir/expression.cpp.obj
tcode/expr.exe: tcode/CMakeFiles/expr.dir/build.make
tcode/expr.exe: tcode/CMakeFiles/expr.dir/linklibs.rsp
tcode/expr.exe: tcode/CMakeFiles/expr.dir/objects1.rsp
tcode/expr.exe: tcode/CMakeFiles/expr.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\CPP\2020_5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable expr.exe"
	cd /d C:\CPP\2020_5\cmake-build-debug\tcode && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\expr.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tcode/CMakeFiles/expr.dir/build: tcode/expr.exe

.PHONY : tcode/CMakeFiles/expr.dir/build

tcode/CMakeFiles/expr.dir/clean:
	cd /d C:\CPP\2020_5\cmake-build-debug\tcode && $(CMAKE_COMMAND) -P CMakeFiles\expr.dir\cmake_clean.cmake
.PHONY : tcode/CMakeFiles/expr.dir/clean

tcode/CMakeFiles/expr.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\CPP\2020_5 C:\CPP\2020_5\tcode C:\CPP\2020_5\cmake-build-debug C:\CPP\2020_5\cmake-build-debug\tcode C:\CPP\2020_5\cmake-build-debug\tcode\CMakeFiles\expr.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : tcode/CMakeFiles/expr.dir/depend

