#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <sys/types.h>

#include "../include/library/nettools.h"
#include "../include/library/users.h"
#include "../include/data/model.h"
#include "../include/data/protocol.h"
#include "../include/library/rooms.h"
#include "../include/chat/ui.h"

int main()
{
    int roominfo_sock;
    char roominfo_buf[ROOMINFO_BUF_SIZE];
    struct sockaddr_in multi_sadr;

    int heartbeat_sock;
    struct sockaddr_in udp_sadr, udp_cadr;
    char heartbeat_buf[HEARTBEAT_BUF_SIZE] = {
        0,
    };

    int room_sock;
    struct sockaddr_in room_sadr, room_cadr;
    int room_cadr_size;
    char roomsock_buf[ROOM_BUF_SIZE] = {
        0,
    };
    char read_room_buf[ROOM_BUF_SIZE] = {
        0,
    };

    int state;
    int stdin_fd;
    stdin_fd = fileno(stdin);
    fd_set readfds, backup_readfds;
    struct timeval timeout;

    USER_FULLDATA userList[5]; // TODO MAX_USER도 입력받게 하기
    int userIndex[5] = {
        0,
    };
    USER tempUser;

    ROOM roomList[5]; // TODO MAX_ROOM도 입력받게 하기
    int roomIndex[5] = {
        0,
    };
    ROOM tempRoom;

    int code;

    char message[ROOM_BUF_SIZE] = {
        0,
    };

    int len;

    int netmode = WIRELESS_MODE;

    print_user_input("NETMODE");
    scanf("%d", &netmode);

    // TODO Multicast Grout IP, PORT, UDP PORT, NETMODE 전부 입력받게 하기
    printf("SYSTEM: 배달의민조 채팅 서버 시작중...\n");
    printf("SYSTEM: 서버 IP - %s\n", getMyIp(netmode));

    create_roominfo_sender_sock(&roominfo_sock, &multi_sadr, "239.0.130.1", 9001);
    printf("SYSTEM: Roominfo Sender 소켓 생성 성공\n");
    strcpy(roominfo_buf, getMyIp(netmode));

    create_heartbeat_receiver_sock(&heartbeat_sock, &udp_sadr, &udp_cadr, 5001);
    printf("SYSTEM: Heartbeat Receiver 소켓 생성 성공\n");

    set_room_receiver_sock(&room_sock, &room_sadr, &room_cadr, 5002);
    printf("SYSTEM: Room 소켓 생성 성공\n");

    char keyBuf[50] = {
        0,
    };

    FD_ZERO(&readfds);
    FD_SET(heartbeat_sock, &readfds);
    FD_SET(room_sock, &readfds);
    FD_SET(stdin_fd, &readfds);
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;
    backup_readfds = readfds;

    print_server_ui(UI_SERVER_MAIN);
    while (1)
    {
        readfds = backup_readfds;
        state = select(room_sock + 1, &readfds, (fd_set *)0, (fd_set *)0, &timeout);
        switch (state)
        {
        case -1:
            /* code */
            break;
        case 0:
            checkDeactiveUser(userList, userIndex, 5);
            sendto(roominfo_sock, roominfo_buf, ROOMINFO_BUF_SIZE, 0, (struct sockaddr *)&multi_sadr, sizeof(multi_sadr));
            timeout.tv_sec = 1;
            timeout.tv_usec = 0;
            break;
        default:
            // NOTE 유저 소켓
            if (FD_ISSET(stdin_fd, &readfds))
            {
                scanf(" %[^\n]", keyBuf);
                switch (atoi(keyBuf))
                {
                case 1:
                    print_manager_userlist_ui(userList);
                    break;

                case 2:
                    puts("oh byby");
                    break;

                default:
                    break;
                }
            }
            if (FD_ISSET(heartbeat_sock, &readfds))
            {
                recvfrom(heartbeat_sock, heartbeat_buf, HEARTBEAT_BUF_SIZE, 0,
                         0, 0);
                memcpy(&tempUser, heartbeat_buf, sizeof(USER));
                updateUserList(&tempUser, userList, userIndex, 5);
            }
            // NOTE 룸 소켓
            if (FD_ISSET(room_sock, &readfds))
            {
                memset(roomsock_buf, 0, ROOM_BUF_SIZE);
                memset(read_room_buf, 0, ROOM_BUF_SIZE);
                room_cadr_size = sizeof(room_cadr);
                recvfrom(room_sock, read_room_buf, ROOM_BUF_SIZE + sizeof(int), 0,
                         (struct sockaddr *)&room_cadr, &room_cadr_size);
                code = getCode(read_room_buf);
                dropHeader(roomsock_buf, read_room_buf, ROOMINFO_BUF_SIZE);
                memcpy(&tempRoom, roomsock_buf, sizeof(ROOM));
                switch (code)
                {
                case CODE_CREATE_ROOM_REQUEST:
                    memset(roomsock_buf, 0, ROOM_BUF_SIZE);
                    setHeader(roomsock_buf, ROOM_BUF_SIZE, CODE_CREATE_ROOM_SUCCESS);
                    addRoom(&tempRoom, roomList, roomIndex, 5);
                    sendto(room_sock, roomsock_buf, ROOM_BUF_SIZE, 0, (struct sockaddr *)&room_cadr, sizeof(room_cadr));
                    break;

                case CODE_SEARCH_ROOM_REQUEST:
                    memset(roomsock_buf, 0, ROOM_BUF_SIZE);
                    setHeader(roomsock_buf, ROOM_BUF_SIZE, CODE_SEARCH_ROOM_RESPONSE);
                    memcpy(roomsock_buf + CODE_SIZE, &roomList, sizeof(ROOM) * 5);
                    sendto(room_sock, roomsock_buf, ROOM_BUF_SIZE, 0, (struct sockaddr *)&room_cadr, sizeof(room_cadr));
                    break;

                case CODE_DELETE_ROOM_REQUEST:
                    // TODO 룸 삭제하기
                    break;

                default:
                    break;
                }
            }
            break;
        }
    }

    return 0;
}