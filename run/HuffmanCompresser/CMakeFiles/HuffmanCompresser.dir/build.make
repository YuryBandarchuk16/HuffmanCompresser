# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.7.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.7.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/YuryBandarchuk/Documents/C++/Compresser

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/YuryBandarchuk/Documents/C++/Compresser/run

# Include any dependencies generated for this target.
include HuffmanCompresser/CMakeFiles/HuffmanCompresser.dir/depend.make

# Include the progress variables for this target.
include HuffmanCompresser/CMakeFiles/HuffmanCompresser.dir/progress.make

# Include the compile flags for this target's objects.
include HuffmanCompresser/CMakeFiles/HuffmanCompresser.dir/flags.make

HuffmanCompresser/CMakeFiles/HuffmanCompresser.dir/HuffmanCompresser.cpp.o: HuffmanCompresser/CMakeFiles/HuffmanCompresser.dir/flags.make
HuffmanCompresser/CMakeFiles/HuffmanCompresser.dir/HuffmanCompresser.cpp.o: ../HuffmanCompresser/HuffmanCompresser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/YuryBandarchuk/Documents/C++/Compresser/run/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object HuffmanCompresser/CMakeFiles/HuffmanCompresser.dir/HuffmanCompresser.cpp.o"
	cd /Users/YuryBandarchuk/Documents/C++/Compresser/run/HuffmanCompresser && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/HuffmanCompresser.dir/HuffmanCompresser.cpp.o -c /Users/YuryBandarchuk/Documents/C++/Compresser/HuffmanCompresser/HuffmanCompresser.cpp

HuffmanCompresser/CMakeFiles/HuffmanCompresser.dir/HuffmanCompresser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HuffmanCompresser.dir/HuffmanCompresser.cpp.i"
	cd /Users/YuryBandarchuk/Documents/C++/Compresser/run/HuffmanCompresser && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/YuryBandarchuk/Documents/C++/Compresser/HuffmanCompresser/HuffmanCompresser.cpp > CMakeFiles/HuffmanCompresser.dir/HuffmanCompresser.cpp.i

HuffmanCompresser/CMakeFiles/HuffmanCompresser.dir/HuffmanCompresser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HuffmanCompresser.dir/HuffmanCompresser.cpp.s"
	cd /Users/YuryBandarchuk/Documents/C++/Compresser/run/HuffmanCompresser && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/YuryBandarchuk/Documents/C++/Compresser/HuffmanCompresser/HuffmanCompresser.cpp -o CMakeFiles/HuffmanCompresser.dir/HuffmanCompresser.cpp.s

HuffmanCompresser/CMakeFiles/HuffmanCompresser.dir/HuffmanCompresser.cpp.o.requires:

.PHONY : HuffmanCompresser/CMakeFiles/HuffmanCompresser.dir/HuffmanCompresser.cpp.o.requires

HuffmanCompresser/CMakeFiles/HuffmanCompresser.dir/HuffmanCompresser.cpp.o.provides: HuffmanCompresser/CMakeFiles/HuffmanCompresser.dir/HuffmanCompresser.cpp.o.requires
	$(MAKE) -f HuffmanCompresser/CMakeFiles/HuffmanCompresser.dir/build.make HuffmanCompresser/CMakeFiles/HuffmanCompresser.dir/HuffmanCompresser.cpp.o.provides.build
.PHONY : HuffmanCompresser/CMakeFiles/HuffmanCompresser.dir/HuffmanCompresser.cpp.o.provides

HuffmanCompresser/CMakeFiles/HuffmanCompresser.dir/HuffmanCompresser.cpp.o.provides.build: HuffmanCompresser/CMakeFiles/HuffmanCompresser.dir/HuffmanCompresser.cpp.o


# Object files for target HuffmanCompresser
HuffmanCompresser_OBJECTS = \
"CMakeFiles/HuffmanCompresser.dir/HuffmanCompresser.cpp.o"

# External object files for target HuffmanCompresser
HuffmanCompresser_EXTERNAL_OBJECTS =

HuffmanCompresser/libHuffmanCompresser.a: HuffmanCompresser/CMakeFiles/HuffmanCompresser.dir/HuffmanCompresser.cpp.o
HuffmanCompresser/libHuffmanCompresser.a: HuffmanCompresser/CMakeFiles/HuffmanCompresser.dir/build.make
HuffmanCompresser/libHuffmanCompresser.a: HuffmanCompresser/CMakeFiles/HuffmanCompresser.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/YuryBandarchuk/Documents/C++/Compresser/run/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libHuffmanCompresser.a"
	cd /Users/YuryBandarchuk/Documents/C++/Compresser/run/HuffmanCompresser && $(CMAKE_COMMAND) -P CMakeFiles/HuffmanCompresser.dir/cmake_clean_target.cmake
	cd /Users/YuryBandarchuk/Documents/C++/Compresser/run/HuffmanCompresser && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/HuffmanCompresser.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
HuffmanCompresser/CMakeFiles/HuffmanCompresser.dir/build: HuffmanCompresser/libHuffmanCompresser.a

.PHONY : HuffmanCompresser/CMakeFiles/HuffmanCompresser.dir/build

HuffmanCompresser/CMakeFiles/HuffmanCompresser.dir/requires: HuffmanCompresser/CMakeFiles/HuffmanCompresser.dir/HuffmanCompresser.cpp.o.requires

.PHONY : HuffmanCompresser/CMakeFiles/HuffmanCompresser.dir/requires

HuffmanCompresser/CMakeFiles/HuffmanCompresser.dir/clean:
	cd /Users/YuryBandarchuk/Documents/C++/Compresser/run/HuffmanCompresser && $(CMAKE_COMMAND) -P CMakeFiles/HuffmanCompresser.dir/cmake_clean.cmake
.PHONY : HuffmanCompresser/CMakeFiles/HuffmanCompresser.dir/clean

HuffmanCompresser/CMakeFiles/HuffmanCompresser.dir/depend:
	cd /Users/YuryBandarchuk/Documents/C++/Compresser/run && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/YuryBandarchuk/Documents/C++/Compresser /Users/YuryBandarchuk/Documents/C++/Compresser/HuffmanCompresser /Users/YuryBandarchuk/Documents/C++/Compresser/run /Users/YuryBandarchuk/Documents/C++/Compresser/run/HuffmanCompresser /Users/YuryBandarchuk/Documents/C++/Compresser/run/HuffmanCompresser/CMakeFiles/HuffmanCompresser.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : HuffmanCompresser/CMakeFiles/HuffmanCompresser.dir/depend
