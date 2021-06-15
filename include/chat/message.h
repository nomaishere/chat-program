#ifndef MESSAGE
#define MESSAGE

#include "../data/protocol.h"

#define CHATMODE_SERVER 701
#define CHATMODE_CLIENT 702

#define SYSTEM_USER_JOIN 801
#define SYSTEM_USER_LEFT 802

char *createJoinChatroomPacket(USER *profile);

char *createMessagePacket(char message[]);

char *createLeftChatroomPacket();

char *createEchoUserMessage(char name[], char message[]);

void createSystemMessage(char sockbuf[], char name[], int messageType);

void setServerToClientMessagePacket(char sockbuf[], char name[], char message[]);

void setEchoUserMessage(char sockbuf[], char name[], char message[]);

#endif