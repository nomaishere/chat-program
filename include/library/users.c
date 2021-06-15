#include "users.h"

int updateUserList(USER *user, USER_FULLDATA *userList, int userIndex[], int max_user)
{
    int userCount = 0;
    // 현재 유저수 구하기
    for (int i = 0; i < max_user; i++)
    {
        if (userIndex[i] == 1)
            userCount++;
    }

    // 유저리스트의 유저와 새로 들어온 하트비트의 이름 일치여부 확인
    for (int i = 0; i < max_user; i++)
    {
        if (strcmp((userList + i)->name, user->name) == 0)
        {
            switch (user->statusCode)
            {
            case STATUS_DISCONNECTED:
                userIndex[i] = 0;
                memset(userList + i, 0, sizeof(USER_FULLDATA));
                printf("DELETE USER: [ index: %d | name: %s | ip: %s ]\n", i, user->name, user->ip);
                fflush(stdout);
                return USER_DELETED;
                break;

            default:
                //printf("SYSTEM: 데이터 갱신[%s], 초: %ld\n", (userList + i)->name, time(NULL));
                fflush(stdout);
                (userList + i)->lastHeartBeat = time(NULL);
                (userList + i)->statusCode = user->statusCode;
                return USER_UPDATED;
                break;
            }
        }
    }
    if (userCount == max_user)
    {
        printf("NOTICE: 이미 유저가 최대 유저수(%d명)만큼 존재해 추가할 수 없습니다.\n", max_user);
        return 0;
    }
    if (user->statusCode == STATUS_CONNECTED)
    {
        for (int i = 0; i < max_user; i++)
        {
            if (userIndex[i] == 0)
            {
                userIndex[i] = 1;
                strcpy((userList + i)->name, user->name);
                strcpy((userList + i)->ip, user->ip);
                (userList + i)->statusCode = user->statusCode;
                time(&(userList + i)->lastHeartBeat);
                printf("ADD USER: [ in[%d], name: %s | ip: %s ]\n", i, (userList + i)->name, (userList + i)->ip);
                fflush(stdout);
                return USER_ADDED;
            }
        }
    }

    fflush(stdout);
    return 0;
}

void checkDeactiveUser(USER_FULLDATA *userList, int userIndex[], int max_user)
{
    for (int i = 0; i < max_user; i++)
        if (userIndex[i] == 1)
        {
            if (difftime(time(NULL), (userList + i)->lastHeartBeat) > 5) // TODO timeout도 설정 가능하게 하기
            {
                printf("SYSEM: 비활성화된 유저 [%s]를 삭제합니다.\n", (userList + i)->name);
                fflush(stdout);
                userIndex[i] = 0;
                memset(userList + i, 0, sizeof(USER_FULLDATA));
            }
        }
}
