// Client.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

#define MESSAGESIZE 1024

int main()
{
    printf("Client Application\n");

    WSADATA wsa;
    SOCKET sock;
    struct sockaddr_in server;
    char sendBuffer[MESSAGESIZE];
    char replyBuffer[MESSAGESIZE];
    int recvSize;

    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
    {
        int error = WSAGetLastError();
        printf("Initialize failed. Error code: %d\n", error);
        return error;
    }

    printf("Winsock Initialized!\n");

    if ((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET)
    {
        int error = WSAGetLastError();
        printf("Creating a socket failed. Error code: %d\n", error);
        return error;
    }

    printf("Socket Created!\n");

    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(10240);



    closesocket(sock);

    printf("Socket Closed!\n");

    return 0;
}


