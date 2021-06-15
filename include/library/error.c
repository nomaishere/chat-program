#include "error.h"

void error_handling(int errorCode, ...)
{

    switch (errorCode)
    {
    case INVALID_CLIENT_ARGC:
        printf("ERROR[%d]: 실행 방법 오류(사용법 : ./chat_client <유저명>)", INVALID_CLIENT_ARGC);
        exit(0);
        break;

    case INVALID_SERVER_ARGC:
        // TODO
        printf("ERROR[%d]: 실행 방법 오류(사용법 : ./chat_server <멀티캐스트>)", INVALID_CLIENT_ARGC);
        exit(0);
        break;

    case UDPSOCK_CREATE_ERROR:
        printf("ERROR[%d]: UDP소켓 생성에 실패하였습니다.", UDPSOCK_CREATE_ERROR);
        exit(0);
        break;

    case UDPSOCK_BIND_ERROR:
        printf("ERROR[%d]: UDP소켓 바인딩에 실패하였습니다.", UDPSOCK_BIND_ERROR);
        exit(0);
        break;

    case MULTISOCK_BIND_ERROR:
        printf("ERROR[%d]: 멀티캐스트 소켓 바인딩에 실패하였습니다.", MULTISOCK_BIND_ERROR);
        exit(0);
        break;

    case MULTI_SETSOCKOPT_ERROR:
        printf("ERROR[%d]: 멀티캐스트 소켓 생성 중 SetsockOpt에 실패하였습니다.", MULTI_SETSOCKOPT_ERROR);
        exit(0);
        break;

    case MULTI_RECEIVE_ERROR:
        printf("ERROR[%d]: RoomInfo 서버로부터 데이터를 받는데 실패하였습니다.", MULTI_RECEIVE_ERROR);
        exit(0);
        break;

    case TCPSOCK_CREATE_ERROR:
        printf("ERROR[%d]: TCP소켓 생성에 실패햐였습니다.", TCPSOCK_CREATE_ERROR);
        exit(0);
        break;

    case TCPSOCK_BIND_ERROR:
        printf("ERROR[%d]: TCP소켓 바인딩에 실패햐였습니다.", TCPSOCK_CREATE_ERROR);
        exit(0);
        break;

    case TCPSOCK_LISTEN_ERROR:
        printf("ERROR[%d]: TCP소켓 listen()에 실패햐였습니다.", TCPSOCK_CREATE_ERROR);
        exit(0);
        break;

    case INVALID_NET_MODE:
        printf("ERROR[%d]: 존재하지 않는 네트워크 모드입니다. (LAN_MODE와 WIRELESS_모드를 지원합니다.)", INVALID_NET_MODE);
        exit(0);
        break;

    case CANNOT_GET_MYIP:
        printf("ERROR[%d]: 자신의 IP를 가져오는데 실패하였습니다.", CANNOT_GET_MYIP);
        exit(0);
        break;

    case SELECT_ERROR:
        printf("ERROR[%d]: select() 함수가 -1을 반환합니다.", SELECT_ERROR);
        exit(0);
        break;

    default:
        puts("ERROR: 원인을 모르는 에러인데 이게 생기면 안됩니다");
        exit(0);
        break;
    }
}