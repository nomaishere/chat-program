#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <sys/types.h>

#include "../include/data/model.h"
#include "../include/library/nettools.h"
#include "../include/library/error.h"
#include "../include/library/utils.h"
#include "../include/library/io.h"
#include "../include/chat/ui.h"
#include "../include/data/protocol.h"

int main(int argc, char *argv[])
{
    int roominfo_sock;
    struct sockaddr_in multi_saddr;
    struct ip_mreq multi_join_addr;
    int str_len;
    char roominfo_buf[ROOMINFO_BUF_SIZE];

    char *chat_serv_ip;

    int heartbeat_sock;
    socklen_t heartbeat_adr_sz;
    struct sockaddr_in heartbeat_serv_adr, heartbeat_from_adr;
    char heartbeat_packet[HEARTBEAT_BUF_SIZE];

    int room_sock;
    socklen_t room_adr_sz;
    struct sockaddr_in room_serv_adr, room_from_adr;
    char room_packet[ROOM_BUF_SIZE];

    USER profile;
    strcpy(profile.name, argv[1]);              // TODO 이릅 입력받게 하기
    strcpy(profile.ip, getMyIp(WIRELESS_MODE)); // TODO LAN/WIRELESS 입력받게 하기
    profile.statusCode = 200;

    ROOM myroom;

    ROOM roomList[5] = {
        0,
    };

    char keyBuf[100] = {
        0,
    };
    char tempRoomName[100] = {
        0,
    };
    char tempRoomPort[100] = {
        0,
    };
    int keyIndex = 0;
    char soleInput;

    int state;
    int stdin_fd;
    stdin_fd = fileno(stdin);
    fd_set readfds, backup_readfds;
    struct timeval timeout;

    char full_udp_buf[1024] = {
        0,
    };

    int program_state = MAIN;

    int tcpmulti_serv_sock;
    struct sockaddr_in tcpmulti_serv_adr;
    char message[MESSAGE_BUF_SIZE];

    printf("SYSTEM: 배달의민조 채팅 클라이언트 시작중...\n");
    printf("SYSTEM: 내 IP - %s\n", getMyIp(WIRELESS_MODE));

    create_roominfo_receiver_sock(&roominfo_sock, &multi_saddr, &multi_join_addr, "239.0.130.1", 9001);
    printf("SYSTEM: Roominfo Receiver 소켓 생성 성공\n");

    printf("SYSTEM: Roominfo 서버를 기다리는 중...\n");
    str_len = recvfrom(roominfo_sock, roominfo_buf, ROOMINFO_BUF_SIZE, 0, NULL, 0);
    if (str_len < 0)
    {
        close(roominfo_sock);
        error_handling(MULTI_RECEIVE_ERROR);
    }
    chat_serv_ip = roominfo_buf;
    printf("SYSTEM: 채팅 서버 IP - %s\n", chat_serv_ip);

    create_heartbeat_sender_sock(&heartbeat_sock, &heartbeat_serv_adr, &heartbeat_from_adr, chat_serv_ip, 5001); // TODO Port도 직접 roominfo에서 받아오도록 하기
    memcpy(heartbeat_packet, &profile, sizeof(USER));
    printf("SYSTEM: 채팅 서버에 등록 성공\n");

    set_room_sender_sock(&room_sock, &room_serv_adr, &room_from_adr, chat_serv_ip, 5002); // 이 포트도 지정하게 하기

    int len;
    int code;
    int fd_selector;

    printf("PORT> ");
    scanf(" %[^\n]", tempRoomPort);

    tcpmulti_serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    memset(&tcpmulti_serv_adr, 0, sizeof(tcpmulti_serv_adr));
    tcpmulti_serv_adr.sin_family = AF_INET;
    tcpmulti_serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
    tcpmulti_serv_adr.sin_port = htons(atoi(tempRoomPort));

    if (bind(tcpmulti_serv_sock, (struct sockaddr *)&tcpmulti_serv_adr, sizeof(tcpmulti_serv_adr)) == -1)
        error_handling(TCPSOCK_BIND_ERROR);

    if (listen(tcpmulti_serv_sock, 5) == -1)
        error_handling(TCPSOCK_LISTEN_ERROR);

    print_client_ui(program_state);

    FD_ZERO(&readfds);
    FD_SET(room_sock, &readfds);
    FD_SET(stdin_fd, &readfds);
    FD_SET(tcpmulti_serv_sock, &readfds); // ANCHOR 서버용 소켓 감시대상 등록
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;
    backup_readfds = readfds;
    int fd_max = tcpmulti_serv_sock;
    printf("fdmax: %d\n", fd_max);

    while (1)
    {
        int tcpmulti_clnt_sock;
        struct sockaddr_in tcpmulti_clnt_addr;
        int tcpmulti_clnt_adr_size;
        int read_len;

        readfds = backup_readfds;
        //timeout.tv_sec = 1;
        //timeout.tv_usec = 0;
        state = select(fd_max + 1, &readfds, (fd_set *)0, (fd_set *)0, &timeout);
        switch (state)
        {
        case -1:
            /* code */
            break;

        case 0:
            printf("fdmax: %d\n", fd_max);
            fflush(stdout);
            memcpy(heartbeat_packet, &profile, sizeof(USER));
            sendto(heartbeat_sock, heartbeat_packet, sizeof(heartbeat_packet), 0, (struct sockaddr *)&heartbeat_serv_adr, sizeof(heartbeat_serv_adr));
            timeout.tv_sec = 1;
            timeout.tv_usec = 0;
            break;

        default:
            //puts("something is change!");
            if (FD_ISSET(stdin_fd, &readfds))
            {
                switch (program_state)
                {
                case MAIN:
                    scanf(" %[^\n]", keyBuf);
                    if (strcmp(keyBuf, "q") == 0 || strcmp(keyBuf, "Q") == 0)
                        exit(0);
                    else if (strcmp(keyBuf, "1") == 0)
                    {
                        program_state = UI_REQUEST_CREATE_CHATROOM_ROOMNAME;
                        print_client_ui(program_state);
                    }
                    else if (strcmp(keyBuf, "2") == 0)
                    {
                        program_state = UI_REQUEST_CHAT_LIST;
                        print_client_ui(program_state);

                        memset(room_packet, 0, ROOM_BUF_SIZE);
                        setHeader(room_packet, ROOM_BUF_SIZE, CODE_SEARCH_ROOM_REQUEST);
                        sendto(room_sock, room_packet, sizeof(room_packet) + sizeof(int), 0, (struct sockaddr *)&room_serv_adr, sizeof(room_serv_adr));
                        memset(room_packet, 0, ROOM_BUF_SIZE);
                        memset(full_udp_buf, 0, ROOM_BUF_SIZE);
                        recvfrom(room_sock, full_udp_buf, ROOM_BUF_SIZE, 0,
                                 0, 0);
                        code = getCode(full_udp_buf);
                        dropHeader(room_packet, full_udp_buf, ROOMINFO_BUF_SIZE);
                        memcpy(&roomList, room_packet, sizeof(ROOM) * 5);
                        print_roomlist_ui(roomList);
                    }
                    else
                    {
                        printf("올바르지 않은 입력입니다!\n");
                        print_client_ui(program_state);
                    }
                    break;

                case UI_REQUEST_CREATE_CHATROOM_ROOMNAME:
                    scanf(" %[^\n]", keyBuf);
                    memcpy(tempRoomName, keyBuf, sizeof(tempRoomName));

                    // SECTION
                    strcpy(myroom.hostName, profile.name);
                    strcpy(myroom.roomName, tempRoomName);
                    strcpy(myroom.hostIp, getMyIp(WIRELESS_MODE));
                    strcpy(myroom.hostPort, tempRoomPort);
                    setHeader(room_packet, ROOMINFO_BUF_SIZE, CODE_CREATE_ROOM_REQUEST);
                    memcpy(room_packet + CODE_SIZE, &myroom, sizeof(ROOM));
                    len = sendto(room_sock, room_packet, sizeof(room_packet) + sizeof(int), 0, (struct sockaddr *)&room_serv_adr, sizeof(room_serv_adr));
                    program_state = UI_WAIT_CREATE_CHATROOM;
                    memset(room_packet, 0, ROOM_BUF_SIZE);
                    recvfrom(room_sock, room_packet, ROOM_BUF_SIZE, 0,
                             0, 0);
                    code = getCode(room_packet);
                    if (code = CODE_CREATE_ROOM_SUCCESS)
                        puts("SYSTEM: create chatroom successfully");
                    // !SECTION

                    program_state = UI_IN_CHATTING;
                    memset(keyBuf, 0, sizeof(keyBuf));
                    continue;
                    break;
                    break;

                    /*
                case UI_REQUEST_CREATE_CHATROOM_PORT:
                    scanf(" %[^\n]", keyBuf);
                    memcpy(tempRoomPort, keyBuf, sizeof(tempRoomPort));

                    // SECTION
                    strcpy(myroom.hostName, profile.name);
                    strcpy(myroom.roomName, tempRoomName);
                    strcpy(myroom.hostIp, getMyIp(WIRELESS_MODE));
                    strcpy(myroom.hostPort, tempRoomPort);
                    setHeader(room_packet, ROOMINFO_BUF_SIZE, CODE_CREATE_ROOM_REQUEST);
                    memcpy(room_packet + CODE_SIZE, &myroom, sizeof(ROOM));
                    len = sendto(room_sock, room_packet, sizeof(room_packet) + sizeof(int), 0, (struct sockaddr *)&room_serv_adr, sizeof(room_serv_adr));
                    program_state = UI_WAIT_CREATE_CHATROOM;
                    memset(room_packet, 0, ROOM_BUF_SIZE);
                    recvfrom(room_sock, room_packet, ROOM_BUF_SIZE, 0,
                             0, 0);
                    code = getCode(room_packet);
                    if (code = CODE_CREATE_ROOM_SUCCESS)
                        puts("SYSTEM: create chatroom successfully");
                    // !SECTION

                    // NOTE TCP 멀티플렉싱 서버를 생성하기

                    FD_SET(tcpmulti_serv_sock, &readfds); // ANCHOR 서버용 소켓 감시대상 등록
                    printf("ADD HERE: %d\n", tcpmulti_serv_sock);
                    fflush(stdout);
                    fd_max = tcpmulti_serv_sock;
                    program_state = UI_IN_CHATTING;
                    memset(keyBuf, 0, sizeof(keyBuf));
                    continue;
                    break;
                    */

                case UI_IN_CHATTING:
                    scanf(" %[^\n]", keyBuf);
                    puts(keyBuf);
                    break;

                default:
                    break;
                }
            }
            for (fd_selector = 0; fd_selector < fd_max + 1; fd_selector++)
            {
                //printf("NowFD[%d]: %d\n", fd_selector, FD_ISSET(fd_selector, &readfds));

                if (FD_ISSET(fd_selector, &readfds) == 0) // FD_ISSET에서 0이면 건너뜀
                {
                    continue;
                }
                else
                {
                    if (fd_selector == stdin_fd) // stdin_fd인경우 건너뜀
                    {
                        continue;
                    }
                    if (fd_selector == roominfo_sock) // roominfo_sock인경우 건너뜀
                    {
                        continue;
                    }
                    if (fd_selector == room_sock) // roomsock인경우 건너뜀
                    {
                        continue;
                    }
                    if (fd_selector == heartbeat_sock) // heartbeat_sock인경우 건너뜀
                    {
                        continue;
                    }

                    if (fd_selector != tcpmulti_serv_sock)
                    {
                        // 클라이언트 소켓이라면
                        printf("client socket detected %d", fd_selector);
                        fflush(stdout);
                        read_len = read(fd_selector, message, MESSAGE_BUF_SIZE);
                        if (read_len > 0)
                        {
                            write(fd_selector, message, read_len);
                        }
                        else
                        {
                            printf("SYSTEM: Disconnect client : %d \n", fd_selector);
                            fflush(stdout);
                            close(fd_selector);
                            if (fd_max == fd_selector)
                                fd_max--;
                        }
                    }
                    else if (fd_selector == tcpmulti_serv_sock)
                    {
                        // 서버 소켓이면, 연결
                        puts("server socket detected");
                        tcpmulti_clnt_adr_size = sizeof(tcpmulti_clnt_addr);
                        tcpmulti_clnt_sock = accept(tcpmulti_serv_sock, (struct sockaddr *)&tcpmulti_clnt_addr, &tcpmulti_clnt_adr_size);
                        if (tcpmulti_clnt_sock == -1)
                            continue;
                        FD_SET(tcpmulti_clnt_sock, &readfds);
                        if (fd_max < tcpmulti_clnt_sock)
                            fd_max = tcpmulti_clnt_sock;
                        printf("SYSTEM: Connect New Client: %d \n", tcpmulti_clnt_sock);
                        fflush(stdout);
                        break;
                    }
                    else
                    {
                        continue;
                    }
                }
            }

            break;
        }
    }

    return 0;
}