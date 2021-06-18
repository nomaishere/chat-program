#include "ui.h"

void printMiddleLine(const char *ap_string, int a_space_count)
{
    printf("│%-*s│\n", a_space_count, ap_string);
}

void printTitleBar(const char *ap_string, int a_space_count)
{
    printMiddleLine("", a_space_count);
    printMiddleLine(ap_string, a_space_count);
    printMiddleLine("", a_space_count);
}

void printBoxTop(int a_space_count)
{
    printf("┌");
    for (int i = 0; i < a_space_count; i++)
        printf("―");
    printf("┐\n");
}

void printBoxBottom(int a_space_count)
{
    printf("└");
    for (int i = 0; i < a_space_count; i++)
        printf("―");
    printf("┘\n");
}

void print_client_ui(int step)
{
    switch (step)
    {
    case UI_MAIN:
        printBoxTop(50);
        printMiddleLine("", 50);
        printMiddleLine("  Create Chatting Room: 1", 50);
        printMiddleLine("  Connect Chatting Room: 2", 50);
        printMiddleLine("  Quit Program: Q or q", 50);
        printMiddleLine("", 50);
        printBoxBottom(50);
        print_user_input("INPUT");
        break;

    case UI_REQUEST_CREATE_CHATROOM_ROOMNAME:
        print_user_input("CHATROOM NAME");

        break;

    case UI_REQUEST_CHAT_LIST:
        // TODO
        break;

    default:
        break;
    }
}

void print_server_ui(int step)
{
    switch (step)
    {
    case UI_SERVER_MAIN:
        printBoxTop(70);
        printMiddleLine("", 70);
        printMiddleLine("  View User List: 1", 70);
        printMiddleLine("  Stop Chatting Manager: 2", 70);
        printMiddleLine("", 70);
        printBoxBottom(70);
        print_user_input("INPUT");
        break;

    default:
        break;
    }
}

void print_roomlist_ui(ROOM roomlist[])
{
    printBoxTop(50);
    printMiddleLine("", 50);
    char roomdata[50] = {
        0,
    };
    char roomCode[4] = {
        0,
    };

    for (int i = 0; i < 5; i++)
    {
        if (strlen(roomlist[i].roomName) != 0)
        {
            itoa(i, roomCode);
            strcpy(roomdata, "  RoomCode: ");
            strcat(roomdata, roomCode);
            strcat(roomdata, "  RoomName: ");
            strcat(roomdata, roomlist[i].roomName);
            strcat(roomdata, " Host: ");
            strcat(roomdata, roomlist[i].hostName);
            printMiddleLine(roomdata, 50);
        }
    }
    printMiddleLine("", 50);
    printBoxBottom(50);
}

void print_manager_userlist_ui(USER_FULLDATA userList[])
{
    char userData[100] = {
        0,
    };
    printBoxTop(70);
    printMiddleLine("", 70);
    for (int i = 0; i < 5; i++)
    {
        memset(userData, 0, sizeof(userData));
        //if (strlen(userList[i].name) != 0)
        // {
        sprintf(userData, "  Code: %d  Name: %s  Ip: %s ", i, userList[i].name, userList[i].ip);
        printMiddleLine(userData, 70);
        //  }
    }
    printMiddleLine("", 70);
    printBoxBottom(70);
}

void print_oneline_box(char *string)
{
    printBoxTop(50);
    printMiddleLine(string, 50);
    printBoxBottom(50);
}

void print_user_input(char *string)
{
    printf("%s> ", string);
    fflush(stdout);
}
