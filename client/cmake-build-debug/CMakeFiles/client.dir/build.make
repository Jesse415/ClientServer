# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_SOURCE_DIR = /home/one/Documents/Griffith/distributed_2803ICT/ClientServer/client

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/one/Documents/Griffith/distributed_2803ICT/ClientServer/client/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/client.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/client.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/client.dir/flags.make

CMakeFiles/client.dir/client.c.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/client.c.o: ../client.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/one/Documents/Griffith/distributed_2803ICT/ClientServer/client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/client.dir/client.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/client.dir/client.c.o   -c /home/one/Documents/Griffith/distributed_2803ICT/ClientServer/client/client.c

CMakeFiles/client.dir/client.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/client.dir/client.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/one/Documents/Griffith/distributed_2803ICT/ClientServer/client/client.c > CMakeFiles/client.dir/client.c.i

CMakeFiles/client.dir/client.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/client.dir/client.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/one/Documents/Griffith/distributed_2803ICT/ClientServer/client/client.c -o CMakeFiles/client.dir/client.c.s

<<<<<<< HEAD
# Object files for target client
client_OBJECTS = \
"CMakeFiles/client.dir/client.c.o"
=======
CMakeFiles/client.dir/receive.c.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/receive.c.o: ../receive.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/one/Documents/Griffith/distributed_2803ICT/ClientServer/client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/client.dir/receive.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/client.dir/receive.c.o   -c /home/one/Documents/Griffith/distributed_2803ICT/ClientServer/client/receive.c

CMakeFiles/client.dir/receive.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/client.dir/receive.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/one/Documents/Griffith/distributed_2803ICT/ClientServer/client/receive.c > CMakeFiles/client.dir/receive.c.i

CMakeFiles/client.dir/receive.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/client.dir/receive.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/one/Documents/Griffith/distributed_2803ICT/ClientServer/client/receive.c -o CMakeFiles/client.dir/receive.c.s

CMakeFiles/client.dir/sendFile.c.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/sendFile.c.o: ../sendFile.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/one/Documents/Griffith/distributed_2803ICT/ClientServer/client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/client.dir/sendFile.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/client.dir/sendFile.c.o   -c /home/one/Documents/Griffith/distributed_2803ICT/ClientServer/client/sendFile.c

CMakeFiles/client.dir/sendFile.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/client.dir/sendFile.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/one/Documents/Griffith/distributed_2803ICT/ClientServer/client/sendFile.c > CMakeFiles/client.dir/sendFile.c.i

CMakeFiles/client.dir/sendFile.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/client.dir/sendFile.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/one/Documents/Griffith/distributed_2803ICT/ClientServer/client/sendFile.c -o CMakeFiles/client.dir/sendFile.c.s

# Object files for target client
client_OBJECTS = \
"CMakeFiles/client.dir/client.c.o" \
"CMakeFiles/client.dir/receive.c.o" \
"CMakeFiles/client.dir/sendFile.c.o"
>>>>>>> develope

# External object files for target client
client_EXTERNAL_OBJECTS =

client: CMakeFiles/client.dir/client.c.o
<<<<<<< HEAD
client: CMakeFiles/client.dir/build.make
client: CMakeFiles/client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/one/Documents/Griffith/distributed_2803ICT/ClientServer/client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable client"
=======
client: CMakeFiles/client.dir/receive.c.o
client: CMakeFiles/client.dir/sendFile.c.o
client: CMakeFiles/client.dir/build.make
client: CMakeFiles/client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/one/Documents/Griffith/distributed_2803ICT/ClientServer/client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable client"
>>>>>>> develope
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/client.dir/build: client

.PHONY : CMakeFiles/client.dir/build

CMakeFiles/client.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/client.dir/cmake_clean.cmake
.PHONY : CMakeFiles/client.dir/clean

CMakeFiles/client.dir/depend:
	cd /home/one/Documents/Griffith/distributed_2803ICT/ClientServer/client/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/one/Documents/Griffith/distributed_2803ICT/ClientServer/client /home/one/Documents/Griffith/distributed_2803ICT/ClientServer/client /home/one/Documents/Griffith/distributed_2803ICT/ClientServer/client/cmake-build-debug /home/one/Documents/Griffith/distributed_2803ICT/ClientServer/client/cmake-build-debug /home/one/Documents/Griffith/distributed_2803ICT/ClientServer/client/cmake-build-debug/CMakeFiles/client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/client.dir/depend

