#ifndef ROOMS
#define ROOMS

#define ROOM_ADDED 400
#define ROOM_UPDATED 401
#define ROOM_DELETED 402

#define SUCCESS 400
#define FULL_FAIL 401
#define UNKNOWN_FAIL 402

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "../data/model.h"
#include "error.h"
#include "../data/protocol.h"

int addRoom(ROOM *room, ROOM *roomList, int roomIndex[], int max_room);

char *createRoomRequestPacket(char hostName[], char roomName[], char hostIp[], char hostPort[]);

#endif