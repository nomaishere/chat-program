#ifndef MODEL
#define MODEL

#define ROOMINFO_BUF_SIZE 1024
#define HEARTBEAT_BUF_SIZE 1024
#define ROOM_BUF_SIZE 1024

#define STATUS_CONNECTED 200
#define STATUS_CHATTING 201
#define STATUS_DISCONNECTED 202

#include <time.h>

#pragma pack(push, 1)
typedef struct
{
    char name[30];
    char ip[20];
    int statusCode;
} USER, HEARTBEAT;
#pragma pack(pop)

typedef struct
{
    char name[30];
    char ip[20];
    int statusCode;
    time_t lastHeartBeat;
} USER_FULLDATA;

#pragma pack(push, 1)
typedef struct
{
    char roomName[10];
    char hostName[30];
    char hostIp[20];
    char hostPort[20];
} ROOM;
#pragma pack(pop)

#endif