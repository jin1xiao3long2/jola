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
include tcode/CMakeFiles/implicit.dir/depend.make

# Include the progress variables for this target.
include tcode/CMakeFiles/implicit.dir/progress.make

# Include the compile flags for this target's objects.
include tcode/CMakeFiles/implicit.dir/flags.make

tcode/CMakeFiles/implicit.dir/implicit.cpp.obj: tcode/CMakeFiles/implicit.dir/flags.make
tcode/CMakeFiles/implicit.dir/implicit.cpp.obj: ../tcode/implicit.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\CPP\2020_5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tcode/CMakeFiles/implicit.dir/implicit.cpp.obj"
	cd /d C:\CPP\2020_5\cmake-build-debug\tcode && C:\BC\C\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\implicit.dir\implicit.cpp.obj -c C:\CPP\2020_5\tcode\implicit.cpp

tcode/CMakeFiles/implicit.dir/implicit.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/implicit.dir/implicit.cpp.i"
	cd /d C:\CPP\2020_5\cmake-build-debug\tcode && C:\BC\C\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\CPP\2020_5\tcode\implicit.cpp > CMakeFiles\implicit.dir\implicit.cpp.i

tcode/CMakeFiles/implicit.dir/implicit.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/implicit.dir/implicit.cpp.s"
	cd /d C:\CPP\2020_5\cmake-build-debug\tcode && C:\BC\C\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\CPP\2020_5\tcode\implicit.cpp -o CMakeFiles\implicit.dir\implicit.cpp.s

# Object files for target implicit
implicit_OBJECTS = \
"CMakeFiles/implicit.dir/implicit.cpp.obj"

# External object files for target implicit
implicit_EXTERNAL_OBJECTS =

tcode/implicit.exe: tcode/CMakeFiles/implicit.dir/implicit.cpp.obj
tcode/implicit.exe: tcode/CMakeFiles/implicit.dir/build.make
tcode/implicit.exe: tcode/CMakeFiles/implicit.dir/linklibs.rsp
tcode/implicit.exe: tcode/CMakeFiles/implicit.dir/objects1.rsp
tcode/implicit.exe: tcode/CMakeFiles/implicit.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\CPP\2020_5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable implicit.exe"
	cd /d C:\CPP\2020_5\cmake-build-debug\tcode && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\implicit.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tcode/CMakeFiles/implicit.dir/build: tcode/implicit.exe

.PHONY : tcode/CMakeFiles/implicit.dir/build

tcode/CMakeFiles/implicit.dir/clean:
	cd /d C:\CPP\2020_5\cmake-build-debug\tcode && $(CMAKE_COMMAND) -P CMakeFiles\implicit.dir\cmake_clean.cmake
.PHONY : tcode/CMakeFiles/implicit.dir/clean

tcode/CMakeFiles/implicit.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\CPP\2020_5 C:\CPP\2020_5\tcode C:\CPP\2020_5\cmake-build-debug C:\CPP\2020_5\cmake-build-debug\tcode C:\CPP\2020_5\cmake-build-debug\tcode\CMakeFiles\implicit.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : tcode/CMakeFiles/implicit.dir/depend

