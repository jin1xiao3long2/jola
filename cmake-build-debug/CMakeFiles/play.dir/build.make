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
include CMakeFiles/play.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/play.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/play.dir/flags.make

CMakeFiles/play.dir/play.cpp.obj: CMakeFiles/play.dir/flags.make
CMakeFiles/play.dir/play.cpp.obj: ../play.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\CPP\2020_5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/play.dir/play.cpp.obj"
	C:\BC\C\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\play.dir\play.cpp.obj -c C:\CPP\2020_5\play.cpp

CMakeFiles/play.dir/play.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/play.dir/play.cpp.i"
	C:\BC\C\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\CPP\2020_5\play.cpp > CMakeFiles\play.dir\play.cpp.i

CMakeFiles/play.dir/play.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/play.dir/play.cpp.s"
	C:\BC\C\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\CPP\2020_5\play.cpp -o CMakeFiles\play.dir\play.cpp.s

# Object files for target play
play_OBJECTS = \
"CMakeFiles/play.dir/play.cpp.obj"

# External object files for target play
play_EXTERNAL_OBJECTS =

play.exe: CMakeFiles/play.dir/play.cpp.obj
play.exe: CMakeFiles/play.dir/build.make
play.exe: CMakeFiles/play.dir/linklibs.rsp
play.exe: CMakeFiles/play.dir/objects1.rsp
play.exe: CMakeFiles/play.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\CPP\2020_5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable play.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\play.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/play.dir/build: play.exe

.PHONY : CMakeFiles/play.dir/build

CMakeFiles/play.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\play.dir\cmake_clean.cmake
.PHONY : CMakeFiles/play.dir/clean

CMakeFiles/play.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\CPP\2020_5 C:\CPP\2020_5 C:\CPP\2020_5\cmake-build-debug C:\CPP\2020_5\cmake-build-debug C:\CPP\2020_5\cmake-build-debug\CMakeFiles\play.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/play.dir/depend

