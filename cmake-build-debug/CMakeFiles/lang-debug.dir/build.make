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
include CMakeFiles/lang-debug.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lang-debug.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lang-debug.dir/flags.make

CMakeFiles/lang-debug.dir/calc-lang-debug.cpp.obj: CMakeFiles/lang-debug.dir/flags.make
CMakeFiles/lang-debug.dir/calc-lang-debug.cpp.obj: ../calc-lang-debug.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\CPP\2020_5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lang-debug.dir/calc-lang-debug.cpp.obj"
	C:\BC\C\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\lang-debug.dir\calc-lang-debug.cpp.obj -c C:\CPP\2020_5\calc-lang-debug.cpp

CMakeFiles/lang-debug.dir/calc-lang-debug.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lang-debug.dir/calc-lang-debug.cpp.i"
	C:\BC\C\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\CPP\2020_5\calc-lang-debug.cpp > CMakeFiles\lang-debug.dir\calc-lang-debug.cpp.i

CMakeFiles/lang-debug.dir/calc-lang-debug.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lang-debug.dir/calc-lang-debug.cpp.s"
	C:\BC\C\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\CPP\2020_5\calc-lang-debug.cpp -o CMakeFiles\lang-debug.dir\calc-lang-debug.cpp.s

# Object files for target lang-debug
lang__debug_OBJECTS = \
"CMakeFiles/lang-debug.dir/calc-lang-debug.cpp.obj"

# External object files for target lang-debug
lang__debug_EXTERNAL_OBJECTS =

lang-debug.exe: CMakeFiles/lang-debug.dir/calc-lang-debug.cpp.obj
lang-debug.exe: CMakeFiles/lang-debug.dir/build.make
lang-debug.exe: CMakeFiles/lang-debug.dir/linklibs.rsp
lang-debug.exe: CMakeFiles/lang-debug.dir/objects1.rsp
lang-debug.exe: CMakeFiles/lang-debug.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\CPP\2020_5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lang-debug.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\lang-debug.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lang-debug.dir/build: lang-debug.exe

.PHONY : CMakeFiles/lang-debug.dir/build

CMakeFiles/lang-debug.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\lang-debug.dir\cmake_clean.cmake
.PHONY : CMakeFiles/lang-debug.dir/clean

CMakeFiles/lang-debug.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\CPP\2020_5 C:\CPP\2020_5 C:\CPP\2020_5\cmake-build-debug C:\CPP\2020_5\cmake-build-debug C:\CPP\2020_5\cmake-build-debug\CMakeFiles\lang-debug.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lang-debug.dir/depend

