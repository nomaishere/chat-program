#ifndef CHAT
#define CHAT

#define UI_MAIN 100
#define UI_REQUEST_CREATE_CHATROOM_ROOMNAME 101
#define UI_REQUEST_CREATE_CHATROOM_PORT 105
#define UI_WAIT_CREATE_CHATROOM 102
#define UI_REQUEST_CHAT_LIST 103
#define UI_IN_CHATTING 104

#include <stdio.h>
#include <string.h>
#include "../library/utils.h"
#include "../data/model.h"

void printMiddleLine(const char *ap_string, int a_space_count);

void printTitleBar(const char *ap_string, int a_space_count);

void printBoxTop(int a_space_count);

void printBoxBottom(int a_space_count);

void print_client_ui(int step);

void print_roomlist_ui(ROOM roomlist[]);

void print_user_input(char *string);

#endif