# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = C:\Users\XM\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\211.6693.114\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\XM\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\211.6693.114\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\CPP\2020_5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\CPP\2020_5\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/random.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/random.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/random.dir/flags.make

CMakeFiles/random.dir/random.cpp.obj: CMakeFiles/random.dir/flags.make
CMakeFiles/random.dir/random.cpp.obj: ../random.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\CPP\2020_5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/random.dir/random.cpp.obj"
	C:\BC\C\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\random.dir\random.cpp.obj -c C:\CPP\2020_5\random.cpp

CMakeFiles/random.dir/random.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/random.dir/random.cpp.i"
	C:\BC\C\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\CPP\2020_5\random.cpp > CMakeFiles\random.dir\random.cpp.i

CMakeFiles/random.dir/random.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/random.dir/random.cpp.s"
	C:\BC\C\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\CPP\2020_5\random.cpp -o CMakeFiles\random.dir\random.cpp.s

# Object files for target random
random_OBJECTS = \
"CMakeFiles/random.dir/random.cpp.obj"

# External object files for target random
random_EXTERNAL_OBJECTS =

random.exe: CMakeFiles/random.dir/random.cpp.obj
random.exe: CMakeFiles/random.dir/build.make
random.exe: CMakeFiles/random.dir/linklibs.rsp
random.exe: CMakeFiles/random.dir/objects1.rsp
random.exe: CMakeFiles/random.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\CPP\2020_5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable random.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\random.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/random.dir/build: random.exe

.PHONY : CMakeFiles/random.dir/build

CMakeFiles/random.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\random.dir\cmake_clean.cmake
.PHONY : CMakeFiles/random.dir/clean

CMakeFiles/random.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\CPP\2020_5 C:\CPP\2020_5 C:\CPP\2020_5\cmake-build-debug C:\CPP\2020_5\cmake-build-debug C:\CPP\2020_5\cmake-build-debug\CMakeFiles\random.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/random.dir/depend

