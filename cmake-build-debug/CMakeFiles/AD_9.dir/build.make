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
CMAKE_COMMAND = C:\Users\XM\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\203.7717.62\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\XM\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\203.7717.62\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\CPP\2020_5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\CPP\2020_5\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/AD_9.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/AD_9.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AD_9.dir/flags.make

CMakeFiles/AD_9.dir/AD/t9.cpp.obj: CMakeFiles/AD_9.dir/flags.make
CMakeFiles/AD_9.dir/AD/t9.cpp.obj: ../AD/t9.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\CPP\2020_5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/AD_9.dir/AD/t9.cpp.obj"
	C:\BC\C\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\AD_9.dir\AD\t9.cpp.obj -c C:\CPP\2020_5\AD\t9.cpp

CMakeFiles/AD_9.dir/AD/t9.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AD_9.dir/AD/t9.cpp.i"
	C:\BC\C\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\CPP\2020_5\AD\t9.cpp > CMakeFiles\AD_9.dir\AD\t9.cpp.i

CMakeFiles/AD_9.dir/AD/t9.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AD_9.dir/AD/t9.cpp.s"
	C:\BC\C\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\CPP\2020_5\AD\t9.cpp -o CMakeFiles\AD_9.dir\AD\t9.cpp.s

# Object files for target AD_9
AD_9_OBJECTS = \
"CMakeFiles/AD_9.dir/AD/t9.cpp.obj"

# External object files for target AD_9
AD_9_EXTERNAL_OBJECTS =

AD_9.exe: CMakeFiles/AD_9.dir/AD/t9.cpp.obj
AD_9.exe: CMakeFiles/AD_9.dir/build.make
AD_9.exe: CMakeFiles/AD_9.dir/linklibs.rsp
AD_9.exe: CMakeFiles/AD_9.dir/objects1.rsp
AD_9.exe: CMakeFiles/AD_9.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\CPP\2020_5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable AD_9.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\AD_9.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AD_9.dir/build: AD_9.exe

.PHONY : CMakeFiles/AD_9.dir/build

CMakeFiles/AD_9.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\AD_9.dir\cmake_clean.cmake
.PHONY : CMakeFiles/AD_9.dir/clean

CMakeFiles/AD_9.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\CPP\2020_5 C:\CPP\2020_5 C:\CPP\2020_5\cmake-build-debug C:\CPP\2020_5\cmake-build-debug C:\CPP\2020_5\cmake-build-debug\CMakeFiles\AD_9.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/AD_9.dir/depend
