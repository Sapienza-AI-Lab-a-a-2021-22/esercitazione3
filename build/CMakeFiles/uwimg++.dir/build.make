# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sara/Scrivania/esercitazione3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sara/Scrivania/esercitazione3/build

# Include any dependencies generated for this target.
include CMakeFiles/uwimg++.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/uwimg++.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/uwimg++.dir/flags.make

CMakeFiles/uwimg++.dir/src/utils.cpp.o: CMakeFiles/uwimg++.dir/flags.make
CMakeFiles/uwimg++.dir/src/utils.cpp.o: ../src/utils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sara/Scrivania/esercitazione3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/uwimg++.dir/src/utils.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/uwimg++.dir/src/utils.cpp.o -c /home/sara/Scrivania/esercitazione3/src/utils.cpp

CMakeFiles/uwimg++.dir/src/utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/uwimg++.dir/src/utils.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sara/Scrivania/esercitazione3/src/utils.cpp > CMakeFiles/uwimg++.dir/src/utils.cpp.i

CMakeFiles/uwimg++.dir/src/utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/uwimg++.dir/src/utils.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sara/Scrivania/esercitazione3/src/utils.cpp -o CMakeFiles/uwimg++.dir/src/utils.cpp.s

CMakeFiles/uwimg++.dir/src/load_image.cpp.o: CMakeFiles/uwimg++.dir/flags.make
CMakeFiles/uwimg++.dir/src/load_image.cpp.o: ../src/load_image.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sara/Scrivania/esercitazione3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/uwimg++.dir/src/load_image.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/uwimg++.dir/src/load_image.cpp.o -c /home/sara/Scrivania/esercitazione3/src/load_image.cpp

CMakeFiles/uwimg++.dir/src/load_image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/uwimg++.dir/src/load_image.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sara/Scrivania/esercitazione3/src/load_image.cpp > CMakeFiles/uwimg++.dir/src/load_image.cpp.i

CMakeFiles/uwimg++.dir/src/load_image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/uwimg++.dir/src/load_image.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sara/Scrivania/esercitazione3/src/load_image.cpp -o CMakeFiles/uwimg++.dir/src/load_image.cpp.s

CMakeFiles/uwimg++.dir/src/process_image.cpp.o: CMakeFiles/uwimg++.dir/flags.make
CMakeFiles/uwimg++.dir/src/process_image.cpp.o: ../src/process_image.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sara/Scrivania/esercitazione3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/uwimg++.dir/src/process_image.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/uwimg++.dir/src/process_image.cpp.o -c /home/sara/Scrivania/esercitazione3/src/process_image.cpp

CMakeFiles/uwimg++.dir/src/process_image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/uwimg++.dir/src/process_image.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sara/Scrivania/esercitazione3/src/process_image.cpp > CMakeFiles/uwimg++.dir/src/process_image.cpp.i

CMakeFiles/uwimg++.dir/src/process_image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/uwimg++.dir/src/process_image.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sara/Scrivania/esercitazione3/src/process_image.cpp -o CMakeFiles/uwimg++.dir/src/process_image.cpp.s

CMakeFiles/uwimg++.dir/src/resize_image.cpp.o: CMakeFiles/uwimg++.dir/flags.make
CMakeFiles/uwimg++.dir/src/resize_image.cpp.o: ../src/resize_image.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sara/Scrivania/esercitazione3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/uwimg++.dir/src/resize_image.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/uwimg++.dir/src/resize_image.cpp.o -c /home/sara/Scrivania/esercitazione3/src/resize_image.cpp

CMakeFiles/uwimg++.dir/src/resize_image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/uwimg++.dir/src/resize_image.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sara/Scrivania/esercitazione3/src/resize_image.cpp > CMakeFiles/uwimg++.dir/src/resize_image.cpp.i

CMakeFiles/uwimg++.dir/src/resize_image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/uwimg++.dir/src/resize_image.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sara/Scrivania/esercitazione3/src/resize_image.cpp -o CMakeFiles/uwimg++.dir/src/resize_image.cpp.s

CMakeFiles/uwimg++.dir/src/filter_image.cpp.o: CMakeFiles/uwimg++.dir/flags.make
CMakeFiles/uwimg++.dir/src/filter_image.cpp.o: ../src/filter_image.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sara/Scrivania/esercitazione3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/uwimg++.dir/src/filter_image.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/uwimg++.dir/src/filter_image.cpp.o -c /home/sara/Scrivania/esercitazione3/src/filter_image.cpp

CMakeFiles/uwimg++.dir/src/filter_image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/uwimg++.dir/src/filter_image.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sara/Scrivania/esercitazione3/src/filter_image.cpp > CMakeFiles/uwimg++.dir/src/filter_image.cpp.i

CMakeFiles/uwimg++.dir/src/filter_image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/uwimg++.dir/src/filter_image.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sara/Scrivania/esercitazione3/src/filter_image.cpp -o CMakeFiles/uwimg++.dir/src/filter_image.cpp.s

CMakeFiles/uwimg++.dir/src/edge_detection.cpp.o: CMakeFiles/uwimg++.dir/flags.make
CMakeFiles/uwimg++.dir/src/edge_detection.cpp.o: ../src/edge_detection.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sara/Scrivania/esercitazione3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/uwimg++.dir/src/edge_detection.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/uwimg++.dir/src/edge_detection.cpp.o -c /home/sara/Scrivania/esercitazione3/src/edge_detection.cpp

CMakeFiles/uwimg++.dir/src/edge_detection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/uwimg++.dir/src/edge_detection.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sara/Scrivania/esercitazione3/src/edge_detection.cpp > CMakeFiles/uwimg++.dir/src/edge_detection.cpp.i

CMakeFiles/uwimg++.dir/src/edge_detection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/uwimg++.dir/src/edge_detection.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sara/Scrivania/esercitazione3/src/edge_detection.cpp -o CMakeFiles/uwimg++.dir/src/edge_detection.cpp.s

# Object files for target uwimg++
uwimg_______OBJECTS = \
"CMakeFiles/uwimg++.dir/src/utils.cpp.o" \
"CMakeFiles/uwimg++.dir/src/load_image.cpp.o" \
"CMakeFiles/uwimg++.dir/src/process_image.cpp.o" \
"CMakeFiles/uwimg++.dir/src/resize_image.cpp.o" \
"CMakeFiles/uwimg++.dir/src/filter_image.cpp.o" \
"CMakeFiles/uwimg++.dir/src/edge_detection.cpp.o"

# External object files for target uwimg++
uwimg_______EXTERNAL_OBJECTS =

libuwimg++.so: CMakeFiles/uwimg++.dir/src/utils.cpp.o
libuwimg++.so: CMakeFiles/uwimg++.dir/src/load_image.cpp.o
libuwimg++.so: CMakeFiles/uwimg++.dir/src/process_image.cpp.o
libuwimg++.so: CMakeFiles/uwimg++.dir/src/resize_image.cpp.o
libuwimg++.so: CMakeFiles/uwimg++.dir/src/filter_image.cpp.o
libuwimg++.so: CMakeFiles/uwimg++.dir/src/edge_detection.cpp.o
libuwimg++.so: CMakeFiles/uwimg++.dir/build.make
libuwimg++.so: CMakeFiles/uwimg++.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sara/Scrivania/esercitazione3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX shared library libuwimg++.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/uwimg++.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/uwimg++.dir/build: libuwimg++.so

.PHONY : CMakeFiles/uwimg++.dir/build

CMakeFiles/uwimg++.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/uwimg++.dir/cmake_clean.cmake
.PHONY : CMakeFiles/uwimg++.dir/clean

CMakeFiles/uwimg++.dir/depend:
	cd /home/sara/Scrivania/esercitazione3/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sara/Scrivania/esercitazione3 /home/sara/Scrivania/esercitazione3 /home/sara/Scrivania/esercitazione3/build /home/sara/Scrivania/esercitazione3/build /home/sara/Scrivania/esercitazione3/build/CMakeFiles/uwimg++.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/uwimg++.dir/depend

