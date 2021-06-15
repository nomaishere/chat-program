#include "rooms.h"

int addRoom(ROOM *room, ROOM *roomList, int roomIndex[], int max_room)
{
    int roomCount = 0;
    for (int i = 0; i < max_room; i++)
    {
        if (roomIndex[i] == 1)
            roomCount++;
    }
    if (roomCount == max_room)
    {
        printf("SYSTEM[ROOM]: Can't add room(full)\n");
        return FULL_FAIL;
    }

    for (int i = 0; i < max_room; i++)
    {
        if (roomIndex[i] == 0)
        {
            roomIndex[i] = 1;
            strcpy((roomList + i)->roomName, room->roomName);
            strcpy((roomList + i)->hostName, room->hostName);
            strcpy((roomList + i)->hostIp, room->hostIp);
            strcpy((roomList + i)->hostPort, room->hostPort);
            printf("SYSTEM: [%s]님의 새로운 채팅방 [%s]생성\n", room->hostName, room->roomName);
            fflush(stdout);
            return SUCCESS;
        }
    }
    return UNKNOWN_FAIL;
}

char *createRoomRequestPacket(char hostName[], char roomName[], char hostIp[], char hostPort[])
{
    static char room_packet[1024] = {
        0,
    };
    ROOM myroom;
    strcpy(myroom.hostName, hostName);
    strcpy(myroom.roomName, roomName);
    strcpy(myroom.hostIp, hostIp);
    strcpy(myroom.hostPort, hostPort);
    setHeader(room_packet, ROOM_BUF_SIZE, CODE_CREATE_ROOM_REQUEST);
    memcpy(room_packet + CODE_SIZE, &myroom, sizeof(ROOM));
    return room_packet;
}