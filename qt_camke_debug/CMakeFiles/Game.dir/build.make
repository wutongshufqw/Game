# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = D:\IDEA\toolbox1111\apps\CLion\ch-0\221.5080.224\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = D:\IDEA\toolbox1111\apps\CLion\ch-0\221.5080.224\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\IDEA\toolbox1111\apps\CLion\Projects\Game

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\IDEA\toolbox1111\apps\CLion\Projects\Game\qt_camke_debug

# Include any dependencies generated for this target.
include CMakeFiles/Game.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Game.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Game.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Game.dir/flags.make

Game_autogen/JDUL3767SG/qrc_imagesrc.cpp: ../Source/assets/imagesrc.qrc
Game_autogen/JDUL3767SG/qrc_imagesrc.cpp: CMakeFiles/Game_autogen.dir/AutoRcc_imagesrc_JDUL3767SG_Info.json
Game_autogen/JDUL3767SG/qrc_imagesrc.cpp: ../Source/assets/background.jpg
Game_autogen/JDUL3767SG/qrc_imagesrc.cpp: D:/englishaddress/5.12.1/mingw73_64/bin/rcc.exe
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=D:\IDEA\toolbox1111\apps\CLion\Projects\Game\qt_camke_debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic RCC for Source/assets/imagesrc.qrc"
	D:\IDEA\toolbox1111\apps\CLion\ch-0\221.5080.224\bin\cmake\win\bin\cmake.exe -E cmake_autorcc D:/IDEA/toolbox1111/apps/CLion/Projects/Game/qt_camke_debug/CMakeFiles/Game_autogen.dir/AutoRcc_imagesrc_JDUL3767SG_Info.json 

CMakeFiles/Game.dir/Game_autogen/mocs_compilation.cpp.obj: CMakeFiles/Game.dir/flags.make
CMakeFiles/Game.dir/Game_autogen/mocs_compilation.cpp.obj: CMakeFiles/Game.dir/includes_CXX.rsp
CMakeFiles/Game.dir/Game_autogen/mocs_compilation.cpp.obj: Game_autogen/mocs_compilation.cpp
CMakeFiles/Game.dir/Game_autogen/mocs_compilation.cpp.obj: CMakeFiles/Game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\IDEA\toolbox1111\apps\CLion\Projects\Game\qt_camke_debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Game.dir/Game_autogen/mocs_compilation.cpp.obj"
	D:\englishaddress\Tools\mingw730_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Game.dir/Game_autogen/mocs_compilation.cpp.obj -MF CMakeFiles\Game.dir\Game_autogen\mocs_compilation.cpp.obj.d -o CMakeFiles\Game.dir\Game_autogen\mocs_compilation.cpp.obj -c D:\IDEA\toolbox1111\apps\CLion\Projects\Game\qt_camke_debug\Game_autogen\mocs_compilation.cpp

CMakeFiles/Game.dir/Game_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Game.dir/Game_autogen/mocs_compilation.cpp.i"
	D:\englishaddress\Tools\mingw730_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\IDEA\toolbox1111\apps\CLion\Projects\Game\qt_camke_debug\Game_autogen\mocs_compilation.cpp > CMakeFiles\Game.dir\Game_autogen\mocs_compilation.cpp.i

CMakeFiles/Game.dir/Game_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Game.dir/Game_autogen/mocs_compilation.cpp.s"
	D:\englishaddress\Tools\mingw730_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\IDEA\toolbox1111\apps\CLion\Projects\Game\qt_camke_debug\Game_autogen\mocs_compilation.cpp -o CMakeFiles\Game.dir\Game_autogen\mocs_compilation.cpp.s

CMakeFiles/Game.dir/Source/main.cpp.obj: CMakeFiles/Game.dir/flags.make
CMakeFiles/Game.dir/Source/main.cpp.obj: CMakeFiles/Game.dir/includes_CXX.rsp
CMakeFiles/Game.dir/Source/main.cpp.obj: ../Source/main.cpp
CMakeFiles/Game.dir/Source/main.cpp.obj: CMakeFiles/Game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\IDEA\toolbox1111\apps\CLion\Projects\Game\qt_camke_debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Game.dir/Source/main.cpp.obj"
	D:\englishaddress\Tools\mingw730_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Game.dir/Source/main.cpp.obj -MF CMakeFiles\Game.dir\Source\main.cpp.obj.d -o CMakeFiles\Game.dir\Source\main.cpp.obj -c D:\IDEA\toolbox1111\apps\CLion\Projects\Game\Source\main.cpp

CMakeFiles/Game.dir/Source/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Game.dir/Source/main.cpp.i"
	D:\englishaddress\Tools\mingw730_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\IDEA\toolbox1111\apps\CLion\Projects\Game\Source\main.cpp > CMakeFiles\Game.dir\Source\main.cpp.i

CMakeFiles/Game.dir/Source/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Game.dir/Source/main.cpp.s"
	D:\englishaddress\Tools\mingw730_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\IDEA\toolbox1111\apps\CLion\Projects\Game\Source\main.cpp -o CMakeFiles\Game.dir\Source\main.cpp.s

CMakeFiles/Game.dir/Source/mainwindow.cpp.obj: CMakeFiles/Game.dir/flags.make
CMakeFiles/Game.dir/Source/mainwindow.cpp.obj: CMakeFiles/Game.dir/includes_CXX.rsp
CMakeFiles/Game.dir/Source/mainwindow.cpp.obj: ../Source/mainwindow.cpp
CMakeFiles/Game.dir/Source/mainwindow.cpp.obj: CMakeFiles/Game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\IDEA\toolbox1111\apps\CLion\Projects\Game\qt_camke_debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Game.dir/Source/mainwindow.cpp.obj"
	D:\englishaddress\Tools\mingw730_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Game.dir/Source/mainwindow.cpp.obj -MF CMakeFiles\Game.dir\Source\mainwindow.cpp.obj.d -o CMakeFiles\Game.dir\Source\mainwindow.cpp.obj -c D:\IDEA\toolbox1111\apps\CLion\Projects\Game\Source\mainwindow.cpp

CMakeFiles/Game.dir/Source/mainwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Game.dir/Source/mainwindow.cpp.i"
	D:\englishaddress\Tools\mingw730_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\IDEA\toolbox1111\apps\CLion\Projects\Game\Source\mainwindow.cpp > CMakeFiles\Game.dir\Source\mainwindow.cpp.i

CMakeFiles/Game.dir/Source/mainwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Game.dir/Source/mainwindow.cpp.s"
	D:\englishaddress\Tools\mingw730_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\IDEA\toolbox1111\apps\CLion\Projects\Game\Source\mainwindow.cpp -o CMakeFiles\Game.dir\Source\mainwindow.cpp.s

CMakeFiles/Game.dir/Game_autogen/JDUL3767SG/qrc_imagesrc.cpp.obj: CMakeFiles/Game.dir/flags.make
CMakeFiles/Game.dir/Game_autogen/JDUL3767SG/qrc_imagesrc.cpp.obj: CMakeFiles/Game.dir/includes_CXX.rsp
CMakeFiles/Game.dir/Game_autogen/JDUL3767SG/qrc_imagesrc.cpp.obj: Game_autogen/JDUL3767SG/qrc_imagesrc.cpp
CMakeFiles/Game.dir/Game_autogen/JDUL3767SG/qrc_imagesrc.cpp.obj: CMakeFiles/Game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\IDEA\toolbox1111\apps\CLion\Projects\Game\qt_camke_debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Game.dir/Game_autogen/JDUL3767SG/qrc_imagesrc.cpp.obj"
	D:\englishaddress\Tools\mingw730_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Game.dir/Game_autogen/JDUL3767SG/qrc_imagesrc.cpp.obj -MF CMakeFiles\Game.dir\Game_autogen\JDUL3767SG\qrc_imagesrc.cpp.obj.d -o CMakeFiles\Game.dir\Game_autogen\JDUL3767SG\qrc_imagesrc.cpp.obj -c D:\IDEA\toolbox1111\apps\CLion\Projects\Game\qt_camke_debug\Game_autogen\JDUL3767SG\qrc_imagesrc.cpp

CMakeFiles/Game.dir/Game_autogen/JDUL3767SG/qrc_imagesrc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Game.dir/Game_autogen/JDUL3767SG/qrc_imagesrc.cpp.i"
	D:\englishaddress\Tools\mingw730_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\IDEA\toolbox1111\apps\CLion\Projects\Game\qt_camke_debug\Game_autogen\JDUL3767SG\qrc_imagesrc.cpp > CMakeFiles\Game.dir\Game_autogen\JDUL3767SG\qrc_imagesrc.cpp.i

CMakeFiles/Game.dir/Game_autogen/JDUL3767SG/qrc_imagesrc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Game.dir/Game_autogen/JDUL3767SG/qrc_imagesrc.cpp.s"
	D:\englishaddress\Tools\mingw730_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\IDEA\toolbox1111\apps\CLion\Projects\Game\qt_camke_debug\Game_autogen\JDUL3767SG\qrc_imagesrc.cpp -o CMakeFiles\Game.dir\Game_autogen\JDUL3767SG\qrc_imagesrc.cpp.s

# Object files for target Game
Game_OBJECTS = \
"CMakeFiles/Game.dir/Game_autogen/mocs_compilation.cpp.obj" \
"CMakeFiles/Game.dir/Source/main.cpp.obj" \
"CMakeFiles/Game.dir/Source/mainwindow.cpp.obj" \
"CMakeFiles/Game.dir/Game_autogen/JDUL3767SG/qrc_imagesrc.cpp.obj"

# External object files for target Game
Game_EXTERNAL_OBJECTS =

Game.exe: CMakeFiles/Game.dir/Game_autogen/mocs_compilation.cpp.obj
Game.exe: CMakeFiles/Game.dir/Source/main.cpp.obj
Game.exe: CMakeFiles/Game.dir/Source/mainwindow.cpp.obj
Game.exe: CMakeFiles/Game.dir/Game_autogen/JDUL3767SG/qrc_imagesrc.cpp.obj
Game.exe: CMakeFiles/Game.dir/build.make
Game.exe: D:/englishaddress/5.12.1/mingw73_64/lib/libQt5Widgets.a
Game.exe: D:/englishaddress/5.12.1/mingw73_64/lib/libQt5Gui.a
Game.exe: D:/englishaddress/5.12.1/mingw73_64/lib/libQt5Core.a
Game.exe: CMakeFiles/Game.dir/linklibs.rsp
Game.exe: CMakeFiles/Game.dir/objects1.rsp
Game.exe: CMakeFiles/Game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\IDEA\toolbox1111\apps\CLion\Projects\Game\qt_camke_debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable Game.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Game.dir\link.txt --verbose=$(VERBOSE)
	D:\IDEA\toolbox1111\apps\CLion\ch-0\221.5080.224\bin\cmake\win\bin\cmake.exe -E make_directory D:/IDEA/toolbox1111/apps/CLion/Projects/Game/qt_camke_debug/plugins/platforms/
	D:\IDEA\toolbox1111\apps\CLion\ch-0\221.5080.224\bin\cmake\win\bin\cmake.exe -E copy D:/englishaddress/5.12.1/mingw73_64/plugins/platforms/qwindows.dll D:/IDEA/toolbox1111/apps/CLion/Projects/Game/qt_camke_debug/plugins/platforms/
	D:\IDEA\toolbox1111\apps\CLion\ch-0\221.5080.224\bin\cmake\win\bin\cmake.exe -E copy D:/englishaddress/5.12.1/mingw73_64/bin/Qt5Core.dll D:/IDEA/toolbox1111/apps/CLion/Projects/Game/qt_camke_debug
	D:\IDEA\toolbox1111\apps\CLion\ch-0\221.5080.224\bin\cmake\win\bin\cmake.exe -E copy D:/englishaddress/5.12.1/mingw73_64/bin/Qt5Gui.dll D:/IDEA/toolbox1111/apps/CLion/Projects/Game/qt_camke_debug
	D:\IDEA\toolbox1111\apps\CLion\ch-0\221.5080.224\bin\cmake\win\bin\cmake.exe -E copy D:/englishaddress/5.12.1/mingw73_64/bin/Qt5Widgets.dll D:/IDEA/toolbox1111/apps/CLion/Projects/Game/qt_camke_debug

# Rule to build all files generated by this target.
CMakeFiles/Game.dir/build: Game.exe
.PHONY : CMakeFiles/Game.dir/build

CMakeFiles/Game.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Game.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Game.dir/clean

CMakeFiles/Game.dir/depend: Game_autogen/JDUL3767SG/qrc_imagesrc.cpp
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\IDEA\toolbox1111\apps\CLion\Projects\Game D:\IDEA\toolbox1111\apps\CLion\Projects\Game D:\IDEA\toolbox1111\apps\CLion\Projects\Game\qt_camke_debug D:\IDEA\toolbox1111\apps\CLion\Projects\Game\qt_camke_debug D:\IDEA\toolbox1111\apps\CLion\Projects\Game\qt_camke_debug\CMakeFiles\Game.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Game.dir/depend
