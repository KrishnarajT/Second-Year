# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/run/media/krishnaraj/Classes/University/Second Year/First Semister/Computer Networks/Programs"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/run/media/krishnaraj/Classes/University/Second Year/First Semister/Computer Networks/Programs/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Programs.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Programs.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Programs.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Programs.dir/flags.make

CMakeFiles/Programs.dir/Hamming_Code.cpp.o: CMakeFiles/Programs.dir/flags.make
CMakeFiles/Programs.dir/Hamming_Code.cpp.o: /run/media/krishnaraj/Classes/University/Second\ Year/First\ Semister/Computer\ Networks/Programs/Hamming_Code.cpp
CMakeFiles/Programs.dir/Hamming_Code.cpp.o: CMakeFiles/Programs.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/run/media/krishnaraj/Classes/University/Second Year/First Semister/Computer Networks/Programs/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Programs.dir/Hamming_Code.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Programs.dir/Hamming_Code.cpp.o -MF CMakeFiles/Programs.dir/Hamming_Code.cpp.o.d -o CMakeFiles/Programs.dir/Hamming_Code.cpp.o -c "/run/media/krishnaraj/Classes/University/Second Year/First Semister/Computer Networks/Programs/Hamming_Code.cpp"

CMakeFiles/Programs.dir/Hamming_Code.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Programs.dir/Hamming_Code.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/run/media/krishnaraj/Classes/University/Second Year/First Semister/Computer Networks/Programs/Hamming_Code.cpp" > CMakeFiles/Programs.dir/Hamming_Code.cpp.i

CMakeFiles/Programs.dir/Hamming_Code.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Programs.dir/Hamming_Code.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/run/media/krishnaraj/Classes/University/Second Year/First Semister/Computer Networks/Programs/Hamming_Code.cpp" -o CMakeFiles/Programs.dir/Hamming_Code.cpp.s

# Object files for target Programs
Programs_OBJECTS = \
"CMakeFiles/Programs.dir/Hamming_Code.cpp.o"

# External object files for target Programs
Programs_EXTERNAL_OBJECTS =

Programs: CMakeFiles/Programs.dir/Hamming_Code.cpp.o
Programs: CMakeFiles/Programs.dir/build.make
Programs: CMakeFiles/Programs.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/run/media/krishnaraj/Classes/University/Second Year/First Semister/Computer Networks/Programs/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Programs"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Programs.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Programs.dir/build: Programs
.PHONY : CMakeFiles/Programs.dir/build

CMakeFiles/Programs.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Programs.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Programs.dir/clean

CMakeFiles/Programs.dir/depend:
	cd "/run/media/krishnaraj/Classes/University/Second Year/First Semister/Computer Networks/Programs/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/run/media/krishnaraj/Classes/University/Second Year/First Semister/Computer Networks/Programs" "/run/media/krishnaraj/Classes/University/Second Year/First Semister/Computer Networks/Programs" "/run/media/krishnaraj/Classes/University/Second Year/First Semister/Computer Networks/Programs/cmake-build-debug" "/run/media/krishnaraj/Classes/University/Second Year/First Semister/Computer Networks/Programs/cmake-build-debug" "/run/media/krishnaraj/Classes/University/Second Year/First Semister/Computer Networks/Programs/cmake-build-debug/CMakeFiles/Programs.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Programs.dir/depend

