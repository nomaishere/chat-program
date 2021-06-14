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
            printf("SYSTEM[ROOM]: [ in[%d], roomName: %s | hostName: %s | hostIp: %s | HostPort: %s ]\n", i, room->roomName, room->hostName, room->hostIp, room->hostPort);
            fflush(stdout);
            return SUCCESS;
        }
    }
    return UNKNOWN_FAIL;
}
