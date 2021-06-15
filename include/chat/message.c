#include "message.h"

char *createJoinChatroomPacket(USER *profile)
{
    static char buf[MESSAGE_BUF_SIZE] = {
        0,
    };
    setHeader(buf, MESSAGE_BUF_SIZE, CODE_CHATROOM_JOIN);
    memcpy(buf + CODE_SIZE, profile, sizeof(USER));
    return buf;
}

char *createMessagePacket(char message[])
{
    static char buf[MESSAGE_BUF_SIZE] = {
        0,
    };
    setHeader(buf, MESSAGE_BUF_SIZE, CODE_MESSAGE);
    memcpy(buf + CODE_SIZE, message, MESSAGE_BUF_SIZE);
    return buf;
}

char *createLeftChatroomPacket()
{
    static char buf[MESSAGE_BUF_SIZE] = {
        0,
    };
    setHeader(buf, MESSAGE_BUF_SIZE, CODE_CHATROOM_LEFT);
    return buf;
}

char *createEchoUserMessage(char name[], char message[])
{
    static char buf[MESSAGE_BUF_SIZE] = {
        0,
    };
    setHeader(buf, MESSAGE_BUF_SIZE, CODE_ECHO_MESSAGE);
    strcpy(buf + CODE_SIZE, name);
    strcat(buf, "님: ");
    strcat(buf, message);
    printf("created echo message: %s\n", message);
    return buf;
}

void createSystemMessage(char sockbuf[], char name[], int messageType)
{
    memset(sockbuf, 0, MESSAGE_BUF_SIZE);
    setHeader(sockbuf, MESSAGE_BUF_SIZE, CODE_SYSTEM_MESSAGE);
    switch (messageType)
    {
    case SYSTEM_USER_JOIN:
        sprintf(sockbuf + CODE_SIZE, "%s님이 대화에 참가하였습니다", name);
        break;

    case SYSTEM_USER_LEFT:
        sprintf(sockbuf + CODE_SIZE, "%s님이 대화방을 나갔습니다.", name);

    default:
        break;
    }
}

void setEchoUserMessage(char sockbuf[], char name[], char message[])
{
    memset(sockbuf, 0, MESSAGE_BUF_SIZE);
    setHeader(sockbuf, MESSAGE_BUF_SIZE, CODE_ECHO_MESSAGE);
    sprintf(sockbuf + CODE_SIZE, "%s님: %s", name, message);
}