# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = "D:\CLion 2019.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion 2019.3.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\User\CLionProjects\projeto_final12

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\User\CLionProjects\projeto_final12\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/projeto_final.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/projeto_final.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/projeto_final.dir/flags.make

CMakeFiles/projeto_final.dir/main.c.obj: CMakeFiles/projeto_final.dir/flags.make
CMakeFiles/projeto_final.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\User\CLionProjects\projeto_final12\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/projeto_final.dir/main.c.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\projeto_final.dir\main.c.obj   -c C:\Users\User\CLionProjects\projeto_final12\main.c

CMakeFiles/projeto_final.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/projeto_final.dir/main.c.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\User\CLionProjects\projeto_final12\main.c > CMakeFiles\projeto_final.dir\main.c.i

CMakeFiles/projeto_final.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/projeto_final.dir/main.c.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\User\CLionProjects\projeto_final12\main.c -o CMakeFiles\projeto_final.dir\main.c.s

CMakeFiles/projeto_final.dir/funcs.c.obj: CMakeFiles/projeto_final.dir/flags.make
CMakeFiles/projeto_final.dir/funcs.c.obj: ../funcs.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\User\CLionProjects\projeto_final12\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/projeto_final.dir/funcs.c.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\projeto_final.dir\funcs.c.obj   -c C:\Users\User\CLionProjects\projeto_final12\funcs.c

CMakeFiles/projeto_final.dir/funcs.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/projeto_final.dir/funcs.c.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\User\CLionProjects\projeto_final12\funcs.c > CMakeFiles\projeto_final.dir\funcs.c.i

CMakeFiles/projeto_final.dir/funcs.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/projeto_final.dir/funcs.c.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\User\CLionProjects\projeto_final12\funcs.c -o CMakeFiles\projeto_final.dir\funcs.c.s

# Object files for target projeto_final
projeto_final_OBJECTS = \
"CMakeFiles/projeto_final.dir/main.c.obj" \
"CMakeFiles/projeto_final.dir/funcs.c.obj"

# External object files for target projeto_final
projeto_final_EXTERNAL_OBJECTS =

projeto_final.exe: CMakeFiles/projeto_final.dir/main.c.obj
projeto_final.exe: CMakeFiles/projeto_final.dir/funcs.c.obj
projeto_final.exe: CMakeFiles/projeto_final.dir/build.make
projeto_final.exe: CMakeFiles/projeto_final.dir/linklibs.rsp
projeto_final.exe: CMakeFiles/projeto_final.dir/objects1.rsp
projeto_final.exe: CMakeFiles/projeto_final.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\User\CLionProjects\projeto_final12\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable projeto_final.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\projeto_final.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/projeto_final.dir/build: projeto_final.exe

.PHONY : CMakeFiles/projeto_final.dir/build

CMakeFiles/projeto_final.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\projeto_final.dir\cmake_clean.cmake
.PHONY : CMakeFiles/projeto_final.dir/clean

CMakeFiles/projeto_final.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\User\CLionProjects\projeto_final12 C:\Users\User\CLionProjects\projeto_final12 C:\Users\User\CLionProjects\projeto_final12\cmake-build-debug C:\Users\User\CLionProjects\projeto_final12\cmake-build-debug C:\Users\User\CLionProjects\projeto_final12\cmake-build-debug\CMakeFiles\projeto_final.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/projeto_final.dir/depend
