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
CMAKE_COMMAND = C:\Users\XM\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\202.6397.106\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\XM\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\202.6397.106\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\CPP\2020_5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\CPP\2020_5\cmake-build-debug

# Include any dependencies generated for this target.
include mozart/mpp_string/CMakeFiles/mpp_string.dir/depend.make

# Include the progress variables for this target.
include mozart/mpp_string/CMakeFiles/mpp_string.dir/progress.make

# Include the compile flags for this target's objects.
include mozart/mpp_string/CMakeFiles/mpp_string.dir/flags.make

mozart/mpp_string/CMakeFiles/mpp_string.dir/src/dummy.cpp.obj: mozart/mpp_string/CMakeFiles/mpp_string.dir/flags.make
mozart/mpp_string/CMakeFiles/mpp_string.dir/src/dummy.cpp.obj: mozart/mpp_string/CMakeFiles/mpp_string.dir/includes_CXX.rsp
mozart/mpp_string/CMakeFiles/mpp_string.dir/src/dummy.cpp.obj: ../mozart/mpp_string/src/dummy.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\CPP\2020_5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object mozart/mpp_string/CMakeFiles/mpp_string.dir/src/dummy.cpp.obj"
	cd /d C:\CPP\2020_5\cmake-build-debug\mozart\mpp_string && C:\BC\C\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\mpp_string.dir\src\dummy.cpp.obj -c C:\CPP\2020_5\mozart\mpp_string\src\dummy.cpp

mozart/mpp_string/CMakeFiles/mpp_string.dir/src/dummy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mpp_string.dir/src/dummy.cpp.i"
	cd /d C:\CPP\2020_5\cmake-build-debug\mozart\mpp_string && C:\BC\C\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\CPP\2020_5\mozart\mpp_string\src\dummy.cpp > CMakeFiles\mpp_string.dir\src\dummy.cpp.i

mozart/mpp_string/CMakeFiles/mpp_string.dir/src/dummy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mpp_string.dir/src/dummy.cpp.s"
	cd /d C:\CPP\2020_5\cmake-build-debug\mozart\mpp_string && C:\BC\C\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\CPP\2020_5\mozart\mpp_string\src\dummy.cpp -o CMakeFiles\mpp_string.dir\src\dummy.cpp.s

# Object files for target mpp_string
mpp_string_OBJECTS = \
"CMakeFiles/mpp_string.dir/src/dummy.cpp.obj"

# External object files for target mpp_string
mpp_string_EXTERNAL_OBJECTS =

mozart/mpp_string/libmpp_string.a: mozart/mpp_string/CMakeFiles/mpp_string.dir/src/dummy.cpp.obj
mozart/mpp_string/libmpp_string.a: mozart/mpp_string/CMakeFiles/mpp_string.dir/build.make
mozart/mpp_string/libmpp_string.a: mozart/mpp_string/CMakeFiles/mpp_string.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\CPP\2020_5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libmpp_string.a"
	cd /d C:\CPP\2020_5\cmake-build-debug\mozart\mpp_string && $(CMAKE_COMMAND) -P CMakeFiles\mpp_string.dir\cmake_clean_target.cmake
	cd /d C:\CPP\2020_5\cmake-build-debug\mozart\mpp_string && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\mpp_string.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
mozart/mpp_string/CMakeFiles/mpp_string.dir/build: mozart/mpp_string/libmpp_string.a

.PHONY : mozart/mpp_string/CMakeFiles/mpp_string.dir/build

mozart/mpp_string/CMakeFiles/mpp_string.dir/clean:
	cd /d C:\CPP\2020_5\cmake-build-debug\mozart\mpp_string && $(CMAKE_COMMAND) -P CMakeFiles\mpp_string.dir\cmake_clean.cmake
.PHONY : mozart/mpp_string/CMakeFiles/mpp_string.dir/clean

mozart/mpp_string/CMakeFiles/mpp_string.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\CPP\2020_5 C:\CPP\2020_5\mozart\mpp_string C:\CPP\2020_5\cmake-build-debug C:\CPP\2020_5\cmake-build-debug\mozart\mpp_string C:\CPP\2020_5\cmake-build-debug\mozart\mpp_string\CMakeFiles\mpp_string.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : mozart/mpp_string/CMakeFiles/mpp_string.dir/depend

