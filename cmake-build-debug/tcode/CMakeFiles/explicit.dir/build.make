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
include tcode/CMakeFiles/explicit.dir/depend.make

# Include the progress variables for this target.
include tcode/CMakeFiles/explicit.dir/progress.make

# Include the compile flags for this target's objects.
include tcode/CMakeFiles/explicit.dir/flags.make

tcode/CMakeFiles/explicit.dir/explicit.cpp.obj: tcode/CMakeFiles/explicit.dir/flags.make
tcode/CMakeFiles/explicit.dir/explicit.cpp.obj: ../tcode/explicit.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\CPP\2020_5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tcode/CMakeFiles/explicit.dir/explicit.cpp.obj"
	cd /d C:\CPP\2020_5\cmake-build-debug\tcode && C:\BC\C\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\explicit.dir\explicit.cpp.obj -c C:\CPP\2020_5\tcode\explicit.cpp

tcode/CMakeFiles/explicit.dir/explicit.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/explicit.dir/explicit.cpp.i"
	cd /d C:\CPP\2020_5\cmake-build-debug\tcode && C:\BC\C\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\CPP\2020_5\tcode\explicit.cpp > CMakeFiles\explicit.dir\explicit.cpp.i

tcode/CMakeFiles/explicit.dir/explicit.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/explicit.dir/explicit.cpp.s"
	cd /d C:\CPP\2020_5\cmake-build-debug\tcode && C:\BC\C\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\CPP\2020_5\tcode\explicit.cpp -o CMakeFiles\explicit.dir\explicit.cpp.s

# Object files for target explicit
explicit_OBJECTS = \
"CMakeFiles/explicit.dir/explicit.cpp.obj"

# External object files for target explicit
explicit_EXTERNAL_OBJECTS =

tcode/explicit.exe: tcode/CMakeFiles/explicit.dir/explicit.cpp.obj
tcode/explicit.exe: tcode/CMakeFiles/explicit.dir/build.make
tcode/explicit.exe: tcode/CMakeFiles/explicit.dir/linklibs.rsp
tcode/explicit.exe: tcode/CMakeFiles/explicit.dir/objects1.rsp
tcode/explicit.exe: tcode/CMakeFiles/explicit.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\CPP\2020_5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable explicit.exe"
	cd /d C:\CPP\2020_5\cmake-build-debug\tcode && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\explicit.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tcode/CMakeFiles/explicit.dir/build: tcode/explicit.exe

.PHONY : tcode/CMakeFiles/explicit.dir/build

tcode/CMakeFiles/explicit.dir/clean:
	cd /d C:\CPP\2020_5\cmake-build-debug\tcode && $(CMAKE_COMMAND) -P CMakeFiles\explicit.dir\cmake_clean.cmake
.PHONY : tcode/CMakeFiles/explicit.dir/clean

tcode/CMakeFiles/explicit.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\CPP\2020_5 C:\CPP\2020_5\tcode C:\CPP\2020_5\cmake-build-debug C:\CPP\2020_5\cmake-build-debug\tcode C:\CPP\2020_5\cmake-build-debug\tcode\CMakeFiles\explicit.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : tcode/CMakeFiles/explicit.dir/depend

