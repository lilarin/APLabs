# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\User\Desktop\C\Laba12(C++)

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\User\Desktop\C\Laba12(C++)\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Laba12_C___.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Laba12_C___.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Laba12_C___.dir/flags.make

CMakeFiles/Laba12_C___.dir/main.cpp.obj: CMakeFiles/Laba12_C___.dir/flags.make
CMakeFiles/Laba12_C___.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\User\Desktop\C\Laba12(C++)\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Laba12_C___.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Laba12_C___.dir\main.cpp.obj -c C:\Users\User\Desktop\C\Laba12(C++)\main.cpp

CMakeFiles/Laba12_C___.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Laba12_C___.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\User\Desktop\C\Laba12(C++)\main.cpp > CMakeFiles\Laba12_C___.dir\main.cpp.i

CMakeFiles/Laba12_C___.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Laba12_C___.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\User\Desktop\C\Laba12(C++)\main.cpp -o CMakeFiles\Laba12_C___.dir\main.cpp.s

# Object files for target Laba12_C___
Laba12_C____OBJECTS = \
"CMakeFiles/Laba12_C___.dir/main.cpp.obj"

# External object files for target Laba12_C___
Laba12_C____EXTERNAL_OBJECTS =

Laba12_C___.exe: CMakeFiles/Laba12_C___.dir/main.cpp.obj
Laba12_C___.exe: CMakeFiles/Laba12_C___.dir/build.make
Laba12_C___.exe: CMakeFiles/Laba12_C___.dir/linklibs.rsp
Laba12_C___.exe: CMakeFiles/Laba12_C___.dir/objects1.rsp
Laba12_C___.exe: CMakeFiles/Laba12_C___.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\User\Desktop\C\Laba12(C++)\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Laba12_C___.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Laba12_C___.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Laba12_C___.dir/build: Laba12_C___.exe
.PHONY : CMakeFiles/Laba12_C___.dir/build

CMakeFiles/Laba12_C___.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Laba12_C___.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Laba12_C___.dir/clean

CMakeFiles/Laba12_C___.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\User\Desktop\C\Laba12(C++) C:\Users\User\Desktop\C\Laba12(C++) C:\Users\User\Desktop\C\Laba12(C++)\cmake-build-debug C:\Users\User\Desktop\C\Laba12(C++)\cmake-build-debug C:\Users\User\Desktop\C\Laba12(C++)\cmake-build-debug\CMakeFiles\Laba12_C___.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Laba12_C___.dir/depend

