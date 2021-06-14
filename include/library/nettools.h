#ifndef NETTOOLS
#define NETTOOLS

#define TTL 2

#define LAN_MODE 1
#define WIRELESS_MODE 2

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <net/if.h>
#include "error.h"

char *getMyIp(int mode);

int create_roominfo_sender_sock(int *sock, struct sockaddr_in *serv_adr, char *group_ip, int port);

int create_roominfo_receiver_sock(int *sock, struct sockaddr_in *serv_adr, struct ip_mreq *join_adr, char *group_ip, int port);

int create_heartbeat_sender_sock(int *sock, struct sockaddr_in *target_adr, struct sockaddr_in *from_adr, char *target_ip, int target_port);

int create_heartbeat_receiver_sock(int *sock, struct sockaddr_in *serv_adr, struct sockaddr_in *clnt_adr, int port);

int set_server_sock(int *sock, struct sockaddr_in *serv_adr, int port);

int set_room_sender_sock(int *sock, struct sockaddr_in *target_adr, struct sockaddr_in *from_adr, char *target_ip, int target_port);

int set_room_receiver_sock(int *sock, struct sockaddr_in *serv_adr, struct sockaddr_in *clnt_adr, int port);

#endif