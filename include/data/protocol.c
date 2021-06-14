#include "protocol.h"

int getCode(char buf[])
{
    int code = 0;
    char code_buf[4] = {
        0,
    };
    memcpy(code_buf, buf, CODE_SIZE);
    code = atoi(code_buf);
    return code;
}

void setHeader(char buf[], int size, int code)
{
    char code_buf[CODE_SIZE] = {
        0,
    };
    itoa(code, code_buf);
    memcpy(buf, code_buf, CODE_SIZE);
}

void sendRequest(int sock, int code)
{
    char buf[sizeof(int)];
    memcpy(buf, &code, sizeof(int));
    write(sock, buf, sizeof(int));
}

void dropHeader(void *dest, char buf[], int size)
{
    memcpy(dest, buf + sizeof(int), size);
}

void dropHeaderAuto(void *dest, char buf[])
{
    memcpy(dest, buf + sizeof(int), strlen(buf) - sizeof(int));
}