# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.10

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.1.2\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.1.2\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Kurt\CLionProjects\C_Primer_Chapter14\exercise8

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Kurt\CLionProjects\C_Primer_Chapter14\exercise8\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/exercise8.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/exercise8.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/exercise8.dir/flags.make

CMakeFiles/exercise8.dir/main.c.obj: CMakeFiles/exercise8.dir/flags.make
CMakeFiles/exercise8.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Kurt\CLionProjects\C_Primer_Chapter14\exercise8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/exercise8.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\exercise8.dir\main.c.obj   -c C:\Users\Kurt\CLionProjects\C_Primer_Chapter14\exercise8\main.c

CMakeFiles/exercise8.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/exercise8.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Kurt\CLionProjects\C_Primer_Chapter14\exercise8\main.c > CMakeFiles\exercise8.dir\main.c.i

CMakeFiles/exercise8.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/exercise8.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Kurt\CLionProjects\C_Primer_Chapter14\exercise8\main.c -o CMakeFiles\exercise8.dir\main.c.s

CMakeFiles/exercise8.dir/main.c.obj.requires:

.PHONY : CMakeFiles/exercise8.dir/main.c.obj.requires

CMakeFiles/exercise8.dir/main.c.obj.provides: CMakeFiles/exercise8.dir/main.c.obj.requires
	$(MAKE) -f CMakeFiles\exercise8.dir\build.make CMakeFiles/exercise8.dir/main.c.obj.provides.build
.PHONY : CMakeFiles/exercise8.dir/main.c.obj.provides

CMakeFiles/exercise8.dir/main.c.obj.provides.build: CMakeFiles/exercise8.dir/main.c.obj


CMakeFiles/exercise8.dir/my_io.c.obj: CMakeFiles/exercise8.dir/flags.make
CMakeFiles/exercise8.dir/my_io.c.obj: ../my_io.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Kurt\CLionProjects\C_Primer_Chapter14\exercise8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/exercise8.dir/my_io.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\exercise8.dir\my_io.c.obj   -c C:\Users\Kurt\CLionProjects\C_Primer_Chapter14\exercise8\my_io.c

CMakeFiles/exercise8.dir/my_io.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/exercise8.dir/my_io.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Kurt\CLionProjects\C_Primer_Chapter14\exercise8\my_io.c > CMakeFiles\exercise8.dir\my_io.c.i

CMakeFiles/exercise8.dir/my_io.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/exercise8.dir/my_io.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Kurt\CLionProjects\C_Primer_Chapter14\exercise8\my_io.c -o CMakeFiles\exercise8.dir\my_io.c.s

CMakeFiles/exercise8.dir/my_io.c.obj.requires:

.PHONY : CMakeFiles/exercise8.dir/my_io.c.obj.requires

CMakeFiles/exercise8.dir/my_io.c.obj.provides: CMakeFiles/exercise8.dir/my_io.c.obj.requires
	$(MAKE) -f CMakeFiles\exercise8.dir\build.make CMakeFiles/exercise8.dir/my_io.c.obj.provides.build
.PHONY : CMakeFiles/exercise8.dir/my_io.c.obj.provides

CMakeFiles/exercise8.dir/my_io.c.obj.provides.build: CMakeFiles/exercise8.dir/my_io.c.obj


# Object files for target exercise8
exercise8_OBJECTS = \
"CMakeFiles/exercise8.dir/main.c.obj" \
"CMakeFiles/exercise8.dir/my_io.c.obj"

# External object files for target exercise8
exercise8_EXTERNAL_OBJECTS =

exercise8.exe: CMakeFiles/exercise8.dir/main.c.obj
exercise8.exe: CMakeFiles/exercise8.dir/my_io.c.obj
exercise8.exe: CMakeFiles/exercise8.dir/build.make
exercise8.exe: CMakeFiles/exercise8.dir/linklibs.rsp
exercise8.exe: CMakeFiles/exercise8.dir/objects1.rsp
exercise8.exe: CMakeFiles/exercise8.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Kurt\CLionProjects\C_Primer_Chapter14\exercise8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable exercise8.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\exercise8.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/exercise8.dir/build: exercise8.exe

.PHONY : CMakeFiles/exercise8.dir/build

CMakeFiles/exercise8.dir/requires: CMakeFiles/exercise8.dir/main.c.obj.requires
CMakeFiles/exercise8.dir/requires: CMakeFiles/exercise8.dir/my_io.c.obj.requires

.PHONY : CMakeFiles/exercise8.dir/requires

CMakeFiles/exercise8.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\exercise8.dir\cmake_clean.cmake
.PHONY : CMakeFiles/exercise8.dir/clean

CMakeFiles/exercise8.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Kurt\CLionProjects\C_Primer_Chapter14\exercise8 C:\Users\Kurt\CLionProjects\C_Primer_Chapter14\exercise8 C:\Users\Kurt\CLionProjects\C_Primer_Chapter14\exercise8\cmake-build-debug C:\Users\Kurt\CLionProjects\C_Primer_Chapter14\exercise8\cmake-build-debug C:\Users\Kurt\CLionProjects\C_Primer_Chapter14\exercise8\cmake-build-debug\CMakeFiles\exercise8.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/exercise8.dir/depend

