#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include "../library/utils.h"

#define MESSAGE_BUF_SIZE 1024

#define CODE_SIZE 4

#define CODE_CREATE_ROOM_REQUEST 100
#define CODE_SEARCH_ROOM_REQUEST 101
#define CODE_DELETE_ROOM_REQUEST 102

#define CODE_CREATE_ROOM_SUCCESS 103
#define CODE_SEARCH_ROOM_RESPONSE 104

#define CODE_CHATROOM_JOIN 110
#define CODE_MESSAGE 111
#define CODE_CHATROOM_LEFT 112
#define CODE_SYSTEM_MESSAGE 113
#define CODE_ECHO_MESSAGE 114

int getCode(char buf[]);
void setHeader(char buf[], int size, int code);
void dropHeader(void *dest, char buf[], int size);
void sendRequest(int sock, int code);
void dropHeaderAuto(void *dest, char buf[]);