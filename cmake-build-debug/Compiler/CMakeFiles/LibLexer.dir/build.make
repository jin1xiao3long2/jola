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
include Compiler/CMakeFiles/LibLexer.dir/depend.make

# Include the progress variables for this target.
include Compiler/CMakeFiles/LibLexer.dir/progress.make

# Include the compile flags for this target's objects.
include Compiler/CMakeFiles/LibLexer.dir/flags.make

Compiler/CMakeFiles/LibLexer.dir/lexer.cpp.obj: Compiler/CMakeFiles/LibLexer.dir/flags.make
Compiler/CMakeFiles/LibLexer.dir/lexer.cpp.obj: Compiler/CMakeFiles/LibLexer.dir/includes_CXX.rsp
Compiler/CMakeFiles/LibLexer.dir/lexer.cpp.obj: ../Compiler/lexer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\CPP\2020_5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Compiler/CMakeFiles/LibLexer.dir/lexer.cpp.obj"
	cd /d C:\CPP\2020_5\cmake-build-debug\Compiler && C:\BC\C\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\LibLexer.dir\lexer.cpp.obj -c C:\CPP\2020_5\Compiler\lexer.cpp

Compiler/CMakeFiles/LibLexer.dir/lexer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LibLexer.dir/lexer.cpp.i"
	cd /d C:\CPP\2020_5\cmake-build-debug\Compiler && C:\BC\C\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\CPP\2020_5\Compiler\lexer.cpp > CMakeFiles\LibLexer.dir\lexer.cpp.i

Compiler/CMakeFiles/LibLexer.dir/lexer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LibLexer.dir/lexer.cpp.s"
	cd /d C:\CPP\2020_5\cmake-build-debug\Compiler && C:\BC\C\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\CPP\2020_5\Compiler\lexer.cpp -o CMakeFiles\LibLexer.dir\lexer.cpp.s

# Object files for target LibLexer
LibLexer_OBJECTS = \
"CMakeFiles/LibLexer.dir/lexer.cpp.obj"

# External object files for target LibLexer
LibLexer_EXTERNAL_OBJECTS =

Compiler/libLibLexer.a: Compiler/CMakeFiles/LibLexer.dir/lexer.cpp.obj
Compiler/libLibLexer.a: Compiler/CMakeFiles/LibLexer.dir/build.make
Compiler/libLibLexer.a: Compiler/CMakeFiles/LibLexer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\CPP\2020_5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libLibLexer.a"
	cd /d C:\CPP\2020_5\cmake-build-debug\Compiler && $(CMAKE_COMMAND) -P CMakeFiles\LibLexer.dir\cmake_clean_target.cmake
	cd /d C:\CPP\2020_5\cmake-build-debug\Compiler && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\LibLexer.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Compiler/CMakeFiles/LibLexer.dir/build: Compiler/libLibLexer.a

.PHONY : Compiler/CMakeFiles/LibLexer.dir/build

Compiler/CMakeFiles/LibLexer.dir/clean:
	cd /d C:\CPP\2020_5\cmake-build-debug\Compiler && $(CMAKE_COMMAND) -P CMakeFiles\LibLexer.dir\cmake_clean.cmake
.PHONY : Compiler/CMakeFiles/LibLexer.dir/clean

Compiler/CMakeFiles/LibLexer.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\CPP\2020_5 C:\CPP\2020_5\Compiler C:\CPP\2020_5\cmake-build-debug C:\CPP\2020_5\cmake-build-debug\Compiler C:\CPP\2020_5\cmake-build-debug\Compiler\CMakeFiles\LibLexer.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : Compiler/CMakeFiles/LibLexer.dir/depend

