#include "nettools.h"

char *getMyIp(int mode)
{
    struct ifreq ifr;
    static char ipstr[40];
    int s;
    s = socket(AF_INET, SOCK_DGRAM, 0);
    switch (mode)
    {
    case LAN_MODE:
        strncpy(ifr.ifr_name, "enp3s0", IFNAMSIZ);
        break;

    case WIRELESS_MODE:
        strncpy(ifr.ifr_name, "wlo1", IFNAMSIZ);
        break;

    default:
        error_handling(INVALID_NET_MODE);
        break;
    }
    if (ioctl(s, SIOCGIFADDR, &ifr) < 0)
        error_handling(CANNOT_GET_MYIP);
    else
        inet_ntop(AF_INET, ifr.ifr_addr.sa_data + 2, ipstr, sizeof(struct sockaddr));
    close(s);
    return ipstr;
}

// TODO create, set 이름 하나로 통일하기

int create_roominfo_sender_sock(int *sock, struct sockaddr_in *serv_adr, char *group_ip, int port)
{
    int time_live = TTL;
    *sock = socket(PF_INET, SOCK_DGRAM, 0);
    serv_adr->sin_family = AF_INET;
    serv_adr->sin_addr.s_addr = inet_addr(group_ip);
    serv_adr->sin_port = htons(port);
    setsockopt(*sock, IPPROTO_IP,
               IP_MULTICAST_TTL, (void *)&time_live, sizeof(time_live));
    return 0;
}

int create_roominfo_receiver_sock(int *sock, struct sockaddr_in *serv_adr, struct ip_mreq *join_adr, char *group_ip, int port)
{
    int on = 1;
    *sock = socket(PF_INET, SOCK_DGRAM, 0);
    memset(serv_adr, 0, sizeof(*serv_adr));
    serv_adr->sin_family = AF_INET;
    serv_adr->sin_addr.s_addr = htonl(INADDR_ANY);
    serv_adr->sin_port = htons(port);

    setsockopt(*sock, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
    if (bind(*sock, (struct sockaddr *)serv_adr, sizeof(*serv_adr)) == -1)
    {
        close(*sock);
        error_handling(MULTISOCK_BIND_ERROR);
    }

    join_adr->imr_multiaddr.s_addr = inet_addr(group_ip);
    join_adr->imr_interface.s_addr = htonl(INADDR_ANY);

    if ((setsockopt(*sock, IPPROTO_IP,
                    IP_ADD_MEMBERSHIP, (void *)join_adr, sizeof(*join_adr))) < 0)
    {
        close(*sock);
        error_handling(MULTI_SETSOCKOPT_ERROR);
    }

    return 0;
}

// TODO 안쓰는 from_adr 제거하기
int create_heartbeat_sender_sock(int *sock, struct sockaddr_in *target_adr, struct sockaddr_in *from_adr, char *target_ip, int target_port)
{
    *sock = socket(PF_INET, SOCK_DGRAM, 0);
    memset(target_adr, 0, sizeof(*target_adr));
    target_adr->sin_family = AF_INET;
    target_adr->sin_addr.s_addr = inet_addr(target_ip);
    target_adr->sin_port = htons(target_port);

    return 0;
}

int create_heartbeat_receiver_sock(int *sock, struct sockaddr_in *serv_adr, struct sockaddr_in *clnt_adr, int port)
{
    *sock = socket(PF_INET, SOCK_DGRAM, 0);
    if (*sock == -1)
        error_handling(UDPSOCK_CREATE_ERROR);
    memset(serv_adr, 0, sizeof(*serv_adr));
    serv_adr->sin_family = AF_INET;
    serv_adr->sin_addr.s_addr = htonl(INADDR_ANY);
    serv_adr->sin_port = htons(port);
    if (bind(*sock, (struct sockaddr *)serv_adr, sizeof(*serv_adr)) == -1)
    {
        close(*sock);
        error_handling(UDPSOCK_BIND_ERROR);
    }
    return 0;
}

int set_server_sock(int *sock, struct sockaddr_in *serv_adr, int port)
{
    int on = 1;
    *sock = socket(AF_INET, SOCK_STREAM, 0);
    if (*sock == -1)
        error_handling(TCPSOCK_CREATE_ERROR);
    memset(serv_adr, 0x00, sizeof(*serv_adr));
    serv_adr->sin_family = AF_INET;
    serv_adr->sin_addr.s_addr = htonl(INADDR_ANY);
    serv_adr->sin_port = htons(port);

    setsockopt(*sock, SOL_SOCKET, SO_REUSEADDR, (const char *)&on, sizeof(on));
    if (bind(*sock, (struct sockaddr *)serv_adr, sizeof(*serv_adr)) == -1)
        error_handling(TCPSOCK_BIND_ERROR);
    if (listen(*sock, 5) == -1)
        error_handling(TCPSOCK_LISTEN_ERROR);
    return 0;
}

int set_room_sender_sock(int *sock, struct sockaddr_in *target_adr, struct sockaddr_in *from_adr, char *target_ip, int target_port)
{
    *sock = socket(PF_INET, SOCK_DGRAM, 0);
    memset(target_adr, 0, sizeof(*target_adr));
    target_adr->sin_family = AF_INET;
    target_adr->sin_addr.s_addr = inet_addr(target_ip);
    target_adr->sin_port = htons(target_port);

    return 0;
}

int set_room_receiver_sock(int *sock, struct sockaddr_in *serv_adr, struct sockaddr_in *clnt_adr, int port)
{
    *sock = socket(PF_INET, SOCK_DGRAM, 0);

    if (*sock == -1)
        error_handling(UDPSOCK_CREATE_ERROR);
    memset(serv_adr, 0, sizeof(*serv_adr));
    serv_adr->sin_family = AF_INET;
    serv_adr->sin_addr.s_addr = htonl(INADDR_ANY);
    serv_adr->sin_port = htons(port);
    if (bind(*sock, (struct sockaddr *)serv_adr, sizeof(*serv_adr)) == -1)
    {
        close(*sock);
        error_handling(UDPSOCK_BIND_ERROR);
    }
    return 0;
}
