cmake_minimum_required(VERSION 3.5)

project(chat-program)

set( LIB_FILES
    include/data/model.c
    include/data/protocol.c
    include/library/error.c
    include/library/nettools.c
    include/library/utils.c
    include/library/users.c
    include/library/rooms.c
    include/library/io.c
    include/chat/ui.c
    include/chat/message.c
)

add_executable( server.out server/chat_server.c ${LIB_FILES})
add_executable( client.out client/chat_client.c ${LIB_FILES})