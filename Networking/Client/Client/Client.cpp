// Client.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <winsock2.h>
#include <ws2tcpip.h>

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
    
    //InetPton(AF_INET, (PCWSTR)("127.0.0.1"), &server.sin_addr.s_addr);
    server.sin_addr.s_addr = inet_addr("192.168.1.32");
    server.sin_family = AF_INET;
    server.sin_port = htons(10240);

    if (connect(sock, (struct sockaddr*) &server, sizeof(server)) != 0)
    {
        int error = WSAGetLastError();
        printf("Connecting failed. Error code: %d\n", error);
        return error;
    }

    printf("Connected to server!\n");

    strcpy_s(sendBuffer, "Hello Sever!");
    if (send(sock, sendBuffer, strlen(sendBuffer), 0) == 0)
    {
        int error = WSAGetLastError();
        printf("Sending failed. Error code: %d\n", error);
        return error;
    }

    printf("Sent data to server!\n");

    if ((recvSize = recv(sock, replyBuffer, MESSAGESIZE, 0)) == SOCKET_ERROR)
    {
        int error = WSAGetLastError();
        printf("Receiving failed. Error code: %d\n", error);
        return error;
    }

    replyBuffer[recvSize] = 0;

    printf("Received data! %s\n", replyBuffer);

    closesocket(sock);

    printf("Socket Closed!\n");

    WSACleanup();

    return 0;
}


