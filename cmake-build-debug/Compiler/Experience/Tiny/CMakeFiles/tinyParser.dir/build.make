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
include Compiler/Experience/Tiny/CMakeFiles/tinyParser.dir/depend.make

# Include the progress variables for this target.
include Compiler/Experience/Tiny/CMakeFiles/tinyParser.dir/progress.make

# Include the compile flags for this target's objects.
include Compiler/Experience/Tiny/CMakeFiles/tinyParser.dir/flags.make

Compiler/Experience/Tiny/CMakeFiles/tinyParser.dir/Tiny_Nodes.cpp.obj: Compiler/Experience/Tiny/CMakeFiles/tinyParser.dir/flags.make
Compiler/Experience/Tiny/CMakeFiles/tinyParser.dir/Tiny_Nodes.cpp.obj: Compiler/Experience/Tiny/CMakeFiles/tinyParser.dir/includes_CXX.rsp
Compiler/Experience/Tiny/CMakeFiles/tinyParser.dir/Tiny_Nodes.cpp.obj: ../Compiler/Experience/Tiny/Tiny_Nodes.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\CPP\2020_5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Compiler/Experience/Tiny/CMakeFiles/tinyParser.dir/Tiny_Nodes.cpp.obj"
	cd /d C:\CPP\2020_5\cmake-build-debug\Compiler\Experience\Tiny && C:\BC\C\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\tinyParser.dir\Tiny_Nodes.cpp.obj -c C:\CPP\2020_5\Compiler\Experience\Tiny\Tiny_Nodes.cpp

Compiler/Experience/Tiny/CMakeFiles/tinyParser.dir/Tiny_Nodes.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tinyParser.dir/Tiny_Nodes.cpp.i"
	cd /d C:\CPP\2020_5\cmake-build-debug\Compiler\Experience\Tiny && C:\BC\C\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\CPP\2020_5\Compiler\Experience\Tiny\Tiny_Nodes.cpp > CMakeFiles\tinyParser.dir\Tiny_Nodes.cpp.i

Compiler/Experience/Tiny/CMakeFiles/tinyParser.dir/Tiny_Nodes.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tinyParser.dir/Tiny_Nodes.cpp.s"
	cd /d C:\CPP\2020_5\cmake-build-debug\Compiler\Experience\Tiny && C:\BC\C\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\CPP\2020_5\Compiler\Experience\Tiny\Tiny_Nodes.cpp -o CMakeFiles\tinyParser.dir\Tiny_Nodes.cpp.s

Compiler/Experience/Tiny/CMakeFiles/tinyParser.dir/Tiny_Parser.cpp.obj: Compiler/Experience/Tiny/CMakeFiles/tinyParser.dir/flags.make
Compiler/Experience/Tiny/CMakeFiles/tinyParser.dir/Tiny_Parser.cpp.obj: Compiler/Experience/Tiny/CMakeFiles/tinyParser.dir/includes_CXX.rsp
Compiler/Experience/Tiny/CMakeFiles/tinyParser.dir/Tiny_Parser.cpp.obj: ../Compiler/Experience/Tiny/Tiny_Parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\CPP\2020_5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object Compiler/Experience/Tiny/CMakeFiles/tinyParser.dir/Tiny_Parser.cpp.obj"
	cd /d C:\CPP\2020_5\cmake-build-debug\Compiler\Experience\Tiny && C:\BC\C\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\tinyParser.dir\Tiny_Parser.cpp.obj -c C:\CPP\2020_5\Compiler\Experience\Tiny\Tiny_Parser.cpp

Compiler/Experience/Tiny/CMakeFiles/tinyParser.dir/Tiny_Parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tinyParser.dir/Tiny_Parser.cpp.i"
	cd /d C:\CPP\2020_5\cmake-build-debug\Compiler\Experience\Tiny && C:\BC\C\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\CPP\2020_5\Compiler\Experience\Tiny\Tiny_Parser.cpp > CMakeFiles\tinyParser.dir\Tiny_Parser.cpp.i

Compiler/Experience/Tiny/CMakeFiles/tinyParser.dir/Tiny_Parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tinyParser.dir/Tiny_Parser.cpp.s"
	cd /d C:\CPP\2020_5\cmake-build-debug\Compiler\Experience\Tiny && C:\BC\C\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\CPP\2020_5\Compiler\Experience\Tiny\Tiny_Parser.cpp -o CMakeFiles\tinyParser.dir\Tiny_Parser.cpp.s

# Object files for target tinyParser
tinyParser_OBJECTS = \
"CMakeFiles/tinyParser.dir/Tiny_Nodes.cpp.obj" \
"CMakeFiles/tinyParser.dir/Tiny_Parser.cpp.obj"

# External object files for target tinyParser
tinyParser_EXTERNAL_OBJECTS =

Compiler/Experience/Tiny/libtinyParser.a: Compiler/Experience/Tiny/CMakeFiles/tinyParser.dir/Tiny_Nodes.cpp.obj
Compiler/Experience/Tiny/libtinyParser.a: Compiler/Experience/Tiny/CMakeFiles/tinyParser.dir/Tiny_Parser.cpp.obj
Compiler/Experience/Tiny/libtinyParser.a: Compiler/Experience/Tiny/CMakeFiles/tinyParser.dir/build.make
Compiler/Experience/Tiny/libtinyParser.a: Compiler/Experience/Tiny/CMakeFiles/tinyParser.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\CPP\2020_5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libtinyParser.a"
	cd /d C:\CPP\2020_5\cmake-build-debug\Compiler\Experience\Tiny && $(CMAKE_COMMAND) -P CMakeFiles\tinyParser.dir\cmake_clean_target.cmake
	cd /d C:\CPP\2020_5\cmake-build-debug\Compiler\Experience\Tiny && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\tinyParser.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Compiler/Experience/Tiny/CMakeFiles/tinyParser.dir/build: Compiler/Experience/Tiny/libtinyParser.a

.PHONY : Compiler/Experience/Tiny/CMakeFiles/tinyParser.dir/build

Compiler/Experience/Tiny/CMakeFiles/tinyParser.dir/clean:
	cd /d C:\CPP\2020_5\cmake-build-debug\Compiler\Experience\Tiny && $(CMAKE_COMMAND) -P CMakeFiles\tinyParser.dir\cmake_clean.cmake
.PHONY : Compiler/Experience/Tiny/CMakeFiles/tinyParser.dir/clean

Compiler/Experience/Tiny/CMakeFiles/tinyParser.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\CPP\2020_5 C:\CPP\2020_5\Compiler\Experience\Tiny C:\CPP\2020_5\cmake-build-debug C:\CPP\2020_5\cmake-build-debug\Compiler\Experience\Tiny C:\CPP\2020_5\cmake-build-debug\Compiler\Experience\Tiny\CMakeFiles\tinyParser.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : Compiler/Experience/Tiny/CMakeFiles/tinyParser.dir/depend

