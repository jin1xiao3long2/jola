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
include tcode/CMakeFiles/switch.dir/depend.make

# Include the progress variables for this target.
include tcode/CMakeFiles/switch.dir/progress.make

# Include the compile flags for this target's objects.
include tcode/CMakeFiles/switch.dir/flags.make

tcode/CMakeFiles/switch.dir/grade.cpp.obj: tcode/CMakeFiles/switch.dir/flags.make
tcode/CMakeFiles/switch.dir/grade.cpp.obj: ../tcode/grade.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\CPP\2020_5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tcode/CMakeFiles/switch.dir/grade.cpp.obj"
	cd /d C:\CPP\2020_5\cmake-build-debug\tcode && C:\BC\C\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\switch.dir\grade.cpp.obj -c C:\CPP\2020_5\tcode\grade.cpp

tcode/CMakeFiles/switch.dir/grade.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/switch.dir/grade.cpp.i"
	cd /d C:\CPP\2020_5\cmake-build-debug\tcode && C:\BC\C\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\CPP\2020_5\tcode\grade.cpp > CMakeFiles\switch.dir\grade.cpp.i

tcode/CMakeFiles/switch.dir/grade.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/switch.dir/grade.cpp.s"
	cd /d C:\CPP\2020_5\cmake-build-debug\tcode && C:\BC\C\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\CPP\2020_5\tcode\grade.cpp -o CMakeFiles\switch.dir\grade.cpp.s

# Object files for target switch
switch_OBJECTS = \
"CMakeFiles/switch.dir/grade.cpp.obj"

# External object files for target switch
switch_EXTERNAL_OBJECTS =

tcode/switch.exe: tcode/CMakeFiles/switch.dir/grade.cpp.obj
tcode/switch.exe: tcode/CMakeFiles/switch.dir/build.make
tcode/switch.exe: tcode/CMakeFiles/switch.dir/linklibs.rsp
tcode/switch.exe: tcode/CMakeFiles/switch.dir/objects1.rsp
tcode/switch.exe: tcode/CMakeFiles/switch.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\CPP\2020_5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable switch.exe"
	cd /d C:\CPP\2020_5\cmake-build-debug\tcode && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\switch.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tcode/CMakeFiles/switch.dir/build: tcode/switch.exe

.PHONY : tcode/CMakeFiles/switch.dir/build

tcode/CMakeFiles/switch.dir/clean:
	cd /d C:\CPP\2020_5\cmake-build-debug\tcode && $(CMAKE_COMMAND) -P CMakeFiles\switch.dir\cmake_clean.cmake
.PHONY : tcode/CMakeFiles/switch.dir/clean

tcode/CMakeFiles/switch.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\CPP\2020_5 C:\CPP\2020_5\tcode C:\CPP\2020_5\cmake-build-debug C:\CPP\2020_5\cmake-build-debug\tcode C:\CPP\2020_5\cmake-build-debug\tcode\CMakeFiles\switch.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : tcode/CMakeFiles/switch.dir/depend

