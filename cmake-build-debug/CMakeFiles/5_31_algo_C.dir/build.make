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
include CMakeFiles/5_31_algo_C.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/5_31_algo_C.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/5_31_algo_C.dir/flags.make

CMakeFiles/5_31_algo_C.dir/5_31algo_C.cpp.obj: CMakeFiles/5_31_algo_C.dir/flags.make
CMakeFiles/5_31_algo_C.dir/5_31algo_C.cpp.obj: ../5_31algo_C.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\CPP\2020_5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/5_31_algo_C.dir/5_31algo_C.cpp.obj"
	C:\BC\C\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\5_31_algo_C.dir\5_31algo_C.cpp.obj -c C:\CPP\2020_5\5_31algo_C.cpp

CMakeFiles/5_31_algo_C.dir/5_31algo_C.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/5_31_algo_C.dir/5_31algo_C.cpp.i"
	C:\BC\C\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\CPP\2020_5\5_31algo_C.cpp > CMakeFiles\5_31_algo_C.dir\5_31algo_C.cpp.i

CMakeFiles/5_31_algo_C.dir/5_31algo_C.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/5_31_algo_C.dir/5_31algo_C.cpp.s"
	C:\BC\C\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\CPP\2020_5\5_31algo_C.cpp -o CMakeFiles\5_31_algo_C.dir\5_31algo_C.cpp.s

# Object files for target 5_31_algo_C
5_31_algo_C_OBJECTS = \
"CMakeFiles/5_31_algo_C.dir/5_31algo_C.cpp.obj"

# External object files for target 5_31_algo_C
5_31_algo_C_EXTERNAL_OBJECTS =

5_31_algo_C.exe: CMakeFiles/5_31_algo_C.dir/5_31algo_C.cpp.obj
5_31_algo_C.exe: CMakeFiles/5_31_algo_C.dir/build.make
5_31_algo_C.exe: CMakeFiles/5_31_algo_C.dir/linklibs.rsp
5_31_algo_C.exe: CMakeFiles/5_31_algo_C.dir/objects1.rsp
5_31_algo_C.exe: CMakeFiles/5_31_algo_C.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\CPP\2020_5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 5_31_algo_C.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\5_31_algo_C.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/5_31_algo_C.dir/build: 5_31_algo_C.exe

.PHONY : CMakeFiles/5_31_algo_C.dir/build

CMakeFiles/5_31_algo_C.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\5_31_algo_C.dir\cmake_clean.cmake
.PHONY : CMakeFiles/5_31_algo_C.dir/clean

CMakeFiles/5_31_algo_C.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\CPP\2020_5 C:\CPP\2020_5 C:\CPP\2020_5\cmake-build-debug C:\CPP\2020_5\cmake-build-debug C:\CPP\2020_5\cmake-build-debug\CMakeFiles\5_31_algo_C.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/5_31_algo_C.dir/depend

