#ifndef ERROR
#define ERROR

#define INVALID_CLIENT_ARGC 901
#define INVALID_SERVER_ARGC 902

#define UDPSOCK_CREATE_ERROR 911
#define UDPSOCK_BIND_ERROR 912
#define MULTISOCK_BIND_ERROR 913
#define MULTI_SETSOCKOPT_ERROR 914
#define MULTI_RECEIVE_ERROR 915
#define TCPSOCK_CREATE_ERROR 916
#define TCPSOCK_BIND_ERROR 917
#define TCPSOCK_LISTEN_ERROR 918

#define INVALID_NET_MODE 920
#define CANNOT_GET_MYIP 921

#define SELECT_ERROR 931

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

void error_handling(int errorCode, ...);

#endif