# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/plantstoen/netprog/chat-program

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/plantstoen/netprog/chat-program/build

# Include any dependencies generated for this target.
include CMakeFiles/server.out.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/server.out.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/server.out.dir/flags.make

CMakeFiles/server.out.dir/server/chat_server.c.o: CMakeFiles/server.out.dir/flags.make
CMakeFiles/server.out.dir/server/chat_server.c.o: ../server/chat_server.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/plantstoen/netprog/chat-program/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/server.out.dir/server/chat_server.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/server.out.dir/server/chat_server.c.o   -c /home/plantstoen/netprog/chat-program/server/chat_server.c

CMakeFiles/server.out.dir/server/chat_server.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/server.out.dir/server/chat_server.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/plantstoen/netprog/chat-program/server/chat_server.c > CMakeFiles/server.out.dir/server/chat_server.c.i

CMakeFiles/server.out.dir/server/chat_server.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/server.out.dir/server/chat_server.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/plantstoen/netprog/chat-program/server/chat_server.c -o CMakeFiles/server.out.dir/server/chat_server.c.s

CMakeFiles/server.out.dir/server/chat_server.c.o.requires:

.PHONY : CMakeFiles/server.out.dir/server/chat_server.c.o.requires

CMakeFiles/server.out.dir/server/chat_server.c.o.provides: CMakeFiles/server.out.dir/server/chat_server.c.o.requires
	$(MAKE) -f CMakeFiles/server.out.dir/build.make CMakeFiles/server.out.dir/server/chat_server.c.o.provides.build
.PHONY : CMakeFiles/server.out.dir/server/chat_server.c.o.provides

CMakeFiles/server.out.dir/server/chat_server.c.o.provides.build: CMakeFiles/server.out.dir/server/chat_server.c.o


CMakeFiles/server.out.dir/include/data/model.c.o: CMakeFiles/server.out.dir/flags.make
CMakeFiles/server.out.dir/include/data/model.c.o: ../include/data/model.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/plantstoen/netprog/chat-program/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/server.out.dir/include/data/model.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/server.out.dir/include/data/model.c.o   -c /home/plantstoen/netprog/chat-program/include/data/model.c

CMakeFiles/server.out.dir/include/data/model.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/server.out.dir/include/data/model.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/plantstoen/netprog/chat-program/include/data/model.c > CMakeFiles/server.out.dir/include/data/model.c.i

CMakeFiles/server.out.dir/include/data/model.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/server.out.dir/include/data/model.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/plantstoen/netprog/chat-program/include/data/model.c -o CMakeFiles/server.out.dir/include/data/model.c.s

CMakeFiles/server.out.dir/include/data/model.c.o.requires:

.PHONY : CMakeFiles/server.out.dir/include/data/model.c.o.requires

CMakeFiles/server.out.dir/include/data/model.c.o.provides: CMakeFiles/server.out.dir/include/data/model.c.o.requires
	$(MAKE) -f CMakeFiles/server.out.dir/build.make CMakeFiles/server.out.dir/include/data/model.c.o.provides.build
.PHONY : CMakeFiles/server.out.dir/include/data/model.c.o.provides

CMakeFiles/server.out.dir/include/data/model.c.o.provides.build: CMakeFiles/server.out.dir/include/data/model.c.o


CMakeFiles/server.out.dir/include/data/protocol.c.o: CMakeFiles/server.out.dir/flags.make
CMakeFiles/server.out.dir/include/data/protocol.c.o: ../include/data/protocol.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/plantstoen/netprog/chat-program/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/server.out.dir/include/data/protocol.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/server.out.dir/include/data/protocol.c.o   -c /home/plantstoen/netprog/chat-program/include/data/protocol.c

CMakeFiles/server.out.dir/include/data/protocol.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/server.out.dir/include/data/protocol.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/plantstoen/netprog/chat-program/include/data/protocol.c > CMakeFiles/server.out.dir/include/data/protocol.c.i

CMakeFiles/server.out.dir/include/data/protocol.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/server.out.dir/include/data/protocol.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/plantstoen/netprog/chat-program/include/data/protocol.c -o CMakeFiles/server.out.dir/include/data/protocol.c.s

CMakeFiles/server.out.dir/include/data/protocol.c.o.requires:

.PHONY : CMakeFiles/server.out.dir/include/data/protocol.c.o.requires

CMakeFiles/server.out.dir/include/data/protocol.c.o.provides: CMakeFiles/server.out.dir/include/data/protocol.c.o.requires
	$(MAKE) -f CMakeFiles/server.out.dir/build.make CMakeFiles/server.out.dir/include/data/protocol.c.o.provides.build
.PHONY : CMakeFiles/server.out.dir/include/data/protocol.c.o.provides

CMakeFiles/server.out.dir/include/data/protocol.c.o.provides.build: CMakeFiles/server.out.dir/include/data/protocol.c.o


CMakeFiles/server.out.dir/include/library/error.c.o: CMakeFiles/server.out.dir/flags.make
CMakeFiles/server.out.dir/include/library/error.c.o: ../include/library/error.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/plantstoen/netprog/chat-program/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/server.out.dir/include/library/error.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/server.out.dir/include/library/error.c.o   -c /home/plantstoen/netprog/chat-program/include/library/error.c

CMakeFiles/server.out.dir/include/library/error.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/server.out.dir/include/library/error.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/plantstoen/netprog/chat-program/include/library/error.c > CMakeFiles/server.out.dir/include/library/error.c.i

CMakeFiles/server.out.dir/include/library/error.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/server.out.dir/include/library/error.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/plantstoen/netprog/chat-program/include/library/error.c -o CMakeFiles/server.out.dir/include/library/error.c.s

CMakeFiles/server.out.dir/include/library/error.c.o.requires:

.PHONY : CMakeFiles/server.out.dir/include/library/error.c.o.requires

CMakeFiles/server.out.dir/include/library/error.c.o.provides: CMakeFiles/server.out.dir/include/library/error.c.o.requires
	$(MAKE) -f CMakeFiles/server.out.dir/build.make CMakeFiles/server.out.dir/include/library/error.c.o.provides.build
.PHONY : CMakeFiles/server.out.dir/include/library/error.c.o.provides

CMakeFiles/server.out.dir/include/library/error.c.o.provides.build: CMakeFiles/server.out.dir/include/library/error.c.o


CMakeFiles/server.out.dir/include/library/nettools.c.o: CMakeFiles/server.out.dir/flags.make
CMakeFiles/server.out.dir/include/library/nettools.c.o: ../include/library/nettools.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/plantstoen/netprog/chat-program/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/server.out.dir/include/library/nettools.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/server.out.dir/include/library/nettools.c.o   -c /home/plantstoen/netprog/chat-program/include/library/nettools.c

CMakeFiles/server.out.dir/include/library/nettools.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/server.out.dir/include/library/nettools.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/plantstoen/netprog/chat-program/include/library/nettools.c > CMakeFiles/server.out.dir/include/library/nettools.c.i

CMakeFiles/server.out.dir/include/library/nettools.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/server.out.dir/include/library/nettools.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/plantstoen/netprog/chat-program/include/library/nettools.c -o CMakeFiles/server.out.dir/include/library/nettools.c.s

CMakeFiles/server.out.dir/include/library/nettools.c.o.requires:

.PHONY : CMakeFiles/server.out.dir/include/library/nettools.c.o.requires

CMakeFiles/server.out.dir/include/library/nettools.c.o.provides: CMakeFiles/server.out.dir/include/library/nettools.c.o.requires
	$(MAKE) -f CMakeFiles/server.out.dir/build.make CMakeFiles/server.out.dir/include/library/nettools.c.o.provides.build
.PHONY : CMakeFiles/server.out.dir/include/library/nettools.c.o.provides

CMakeFiles/server.out.dir/include/library/nettools.c.o.provides.build: CMakeFiles/server.out.dir/include/library/nettools.c.o


CMakeFiles/server.out.dir/include/library/utils.c.o: CMakeFiles/server.out.dir/flags.make
CMakeFiles/server.out.dir/include/library/utils.c.o: ../include/library/utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/plantstoen/netprog/chat-program/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/server.out.dir/include/library/utils.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/server.out.dir/include/library/utils.c.o   -c /home/plantstoen/netprog/chat-program/include/library/utils.c

CMakeFiles/server.out.dir/include/library/utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/server.out.dir/include/library/utils.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/plantstoen/netprog/chat-program/include/library/utils.c > CMakeFiles/server.out.dir/include/library/utils.c.i

CMakeFiles/server.out.dir/include/library/utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/server.out.dir/include/library/utils.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/plantstoen/netprog/chat-program/include/library/utils.c -o CMakeFiles/server.out.dir/include/library/utils.c.s

CMakeFiles/server.out.dir/include/library/utils.c.o.requires:

.PHONY : CMakeFiles/server.out.dir/include/library/utils.c.o.requires

CMakeFiles/server.out.dir/include/library/utils.c.o.provides: CMakeFiles/server.out.dir/include/library/utils.c.o.requires
	$(MAKE) -f CMakeFiles/server.out.dir/build.make CMakeFiles/server.out.dir/include/library/utils.c.o.provides.build
.PHONY : CMakeFiles/server.out.dir/include/library/utils.c.o.provides

CMakeFiles/server.out.dir/include/library/utils.c.o.provides.build: CMakeFiles/server.out.dir/include/library/utils.c.o


CMakeFiles/server.out.dir/include/library/users.c.o: CMakeFiles/server.out.dir/flags.make
CMakeFiles/server.out.dir/include/library/users.c.o: ../include/library/users.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/plantstoen/netprog/chat-program/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/server.out.dir/include/library/users.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/server.out.dir/include/library/users.c.o   -c /home/plantstoen/netprog/chat-program/include/library/users.c

CMakeFiles/server.out.dir/include/library/users.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/server.out.dir/include/library/users.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/plantstoen/netprog/chat-program/include/library/users.c > CMakeFiles/server.out.dir/include/library/users.c.i

CMakeFiles/server.out.dir/include/library/users.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/server.out.dir/include/library/users.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/plantstoen/netprog/chat-program/include/library/users.c -o CMakeFiles/server.out.dir/include/library/users.c.s

CMakeFiles/server.out.dir/include/library/users.c.o.requires:

.PHONY : CMakeFiles/server.out.dir/include/library/users.c.o.requires

CMakeFiles/server.out.dir/include/library/users.c.o.provides: CMakeFiles/server.out.dir/include/library/users.c.o.requires
	$(MAKE) -f CMakeFiles/server.out.dir/build.make CMakeFiles/server.out.dir/include/library/users.c.o.provides.build
.PHONY : CMakeFiles/server.out.dir/include/library/users.c.o.provides

CMakeFiles/server.out.dir/include/library/users.c.o.provides.build: CMakeFiles/server.out.dir/include/library/users.c.o


CMakeFiles/server.out.dir/include/library/rooms.c.o: CMakeFiles/server.out.dir/flags.make
CMakeFiles/server.out.dir/include/library/rooms.c.o: ../include/library/rooms.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/plantstoen/netprog/chat-program/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/server.out.dir/include/library/rooms.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/server.out.dir/include/library/rooms.c.o   -c /home/plantstoen/netprog/chat-program/include/library/rooms.c

CMakeFiles/server.out.dir/include/library/rooms.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/server.out.dir/include/library/rooms.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/plantstoen/netprog/chat-program/include/library/rooms.c > CMakeFiles/server.out.dir/include/library/rooms.c.i

CMakeFiles/server.out.dir/include/library/rooms.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/server.out.dir/include/library/rooms.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/plantstoen/netprog/chat-program/include/library/rooms.c -o CMakeFiles/server.out.dir/include/library/rooms.c.s

CMakeFiles/server.out.dir/include/library/rooms.c.o.requires:

.PHONY : CMakeFiles/server.out.dir/include/library/rooms.c.o.requires

CMakeFiles/server.out.dir/include/library/rooms.c.o.provides: CMakeFiles/server.out.dir/include/library/rooms.c.o.requires
	$(MAKE) -f CMakeFiles/server.out.dir/build.make CMakeFiles/server.out.dir/include/library/rooms.c.o.provides.build
.PHONY : CMakeFiles/server.out.dir/include/library/rooms.c.o.provides

CMakeFiles/server.out.dir/include/library/rooms.c.o.provides.build: CMakeFiles/server.out.dir/include/library/rooms.c.o


CMakeFiles/server.out.dir/include/library/io.c.o: CMakeFiles/server.out.dir/flags.make
CMakeFiles/server.out.dir/include/library/io.c.o: ../include/library/io.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/plantstoen/netprog/chat-program/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/server.out.dir/include/library/io.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/server.out.dir/include/library/io.c.o   -c /home/plantstoen/netprog/chat-program/include/library/io.c

CMakeFiles/server.out.dir/include/library/io.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/server.out.dir/include/library/io.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/plantstoen/netprog/chat-program/include/library/io.c > CMakeFiles/server.out.dir/include/library/io.c.i

CMakeFiles/server.out.dir/include/library/io.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/server.out.dir/include/library/io.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/plantstoen/netprog/chat-program/include/library/io.c -o CMakeFiles/server.out.dir/include/library/io.c.s

CMakeFiles/server.out.dir/include/library/io.c.o.requires:

.PHONY : CMakeFiles/server.out.dir/include/library/io.c.o.requires

CMakeFiles/server.out.dir/include/library/io.c.o.provides: CMakeFiles/server.out.dir/include/library/io.c.o.requires
	$(MAKE) -f CMakeFiles/server.out.dir/build.make CMakeFiles/server.out.dir/include/library/io.c.o.provides.build
.PHONY : CMakeFiles/server.out.dir/include/library/io.c.o.provides

CMakeFiles/server.out.dir/include/library/io.c.o.provides.build: CMakeFiles/server.out.dir/include/library/io.c.o


CMakeFiles/server.out.dir/include/chat/ui.c.o: CMakeFiles/server.out.dir/flags.make
CMakeFiles/server.out.dir/include/chat/ui.c.o: ../include/chat/ui.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/plantstoen/netprog/chat-program/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/server.out.dir/include/chat/ui.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/server.out.dir/include/chat/ui.c.o   -c /home/plantstoen/netprog/chat-program/include/chat/ui.c

CMakeFiles/server.out.dir/include/chat/ui.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/server.out.dir/include/chat/ui.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/plantstoen/netprog/chat-program/include/chat/ui.c > CMakeFiles/server.out.dir/include/chat/ui.c.i

CMakeFiles/server.out.dir/include/chat/ui.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/server.out.dir/include/chat/ui.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/plantstoen/netprog/chat-program/include/chat/ui.c -o CMakeFiles/server.out.dir/include/chat/ui.c.s

CMakeFiles/server.out.dir/include/chat/ui.c.o.requires:

.PHONY : CMakeFiles/server.out.dir/include/chat/ui.c.o.requires

CMakeFiles/server.out.dir/include/chat/ui.c.o.provides: CMakeFiles/server.out.dir/include/chat/ui.c.o.requires
	$(MAKE) -f CMakeFiles/server.out.dir/build.make CMakeFiles/server.out.dir/include/chat/ui.c.o.provides.build
.PHONY : CMakeFiles/server.out.dir/include/chat/ui.c.o.provides

CMakeFiles/server.out.dir/include/chat/ui.c.o.provides.build: CMakeFiles/server.out.dir/include/chat/ui.c.o


# Object files for target server.out
server_out_OBJECTS = \
"CMakeFiles/server.out.dir/server/chat_server.c.o" \
"CMakeFiles/server.out.dir/include/data/model.c.o" \
"CMakeFiles/server.out.dir/include/data/protocol.c.o" \
"CMakeFiles/server.out.dir/include/library/error.c.o" \
"CMakeFiles/server.out.dir/include/library/nettools.c.o" \
"CMakeFiles/server.out.dir/include/library/utils.c.o" \
"CMakeFiles/server.out.dir/include/library/users.c.o" \
"CMakeFiles/server.out.dir/include/library/rooms.c.o" \
"CMakeFiles/server.out.dir/include/library/io.c.o" \
"CMakeFiles/server.out.dir/include/chat/ui.c.o"

# External object files for target server.out
server_out_EXTERNAL_OBJECTS =

server.out: CMakeFiles/server.out.dir/server/chat_server.c.o
server.out: CMakeFiles/server.out.dir/include/data/model.c.o
server.out: CMakeFiles/server.out.dir/include/data/protocol.c.o
server.out: CMakeFiles/server.out.dir/include/library/error.c.o
server.out: CMakeFiles/server.out.dir/include/library/nettools.c.o
server.out: CMakeFiles/server.out.dir/include/library/utils.c.o
server.out: CMakeFiles/server.out.dir/include/library/users.c.o
server.out: CMakeFiles/server.out.dir/include/library/rooms.c.o
server.out: CMakeFiles/server.out.dir/include/library/io.c.o
server.out: CMakeFiles/server.out.dir/include/chat/ui.c.o
server.out: CMakeFiles/server.out.dir/build.make
server.out: CMakeFiles/server.out.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/plantstoen/netprog/chat-program/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking C executable server.out"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/server.out.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/server.out.dir/build: server.out

.PHONY : CMakeFiles/server.out.dir/build

CMakeFiles/server.out.dir/requires: CMakeFiles/server.out.dir/server/chat_server.c.o.requires
CMakeFiles/server.out.dir/requires: CMakeFiles/server.out.dir/include/data/model.c.o.requires
CMakeFiles/server.out.dir/requires: CMakeFiles/server.out.dir/include/data/protocol.c.o.requires
CMakeFiles/server.out.dir/requires: CMakeFiles/server.out.dir/include/library/error.c.o.requires
CMakeFiles/server.out.dir/requires: CMakeFiles/server.out.dir/include/library/nettools.c.o.requires
CMakeFiles/server.out.dir/requires: CMakeFiles/server.out.dir/include/library/utils.c.o.requires
CMakeFiles/server.out.dir/requires: CMakeFiles/server.out.dir/include/library/users.c.o.requires
CMakeFiles/server.out.dir/requires: CMakeFiles/server.out.dir/include/library/rooms.c.o.requires
CMakeFiles/server.out.dir/requires: CMakeFiles/server.out.dir/include/library/io.c.o.requires
CMakeFiles/server.out.dir/requires: CMakeFiles/server.out.dir/include/chat/ui.c.o.requires

.PHONY : CMakeFiles/server.out.dir/requires

CMakeFiles/server.out.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/server.out.dir/cmake_clean.cmake
.PHONY : CMakeFiles/server.out.dir/clean

CMakeFiles/server.out.dir/depend:
	cd /home/plantstoen/netprog/chat-program/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/plantstoen/netprog/chat-program /home/plantstoen/netprog/chat-program /home/plantstoen/netprog/chat-program/build /home/plantstoen/netprog/chat-program/build /home/plantstoen/netprog/chat-program/build/CMakeFiles/server.out.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/server.out.dir/depend
