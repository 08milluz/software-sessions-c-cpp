// Server.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <stdio.h>
#include <winsock2.h>
#include <string.h>

#pragma comment(lib, "ws2_32.lib")

#define MESSAGESIZE 1024

int main()
{
    printf("Server Application\n");

    WSADATA wsa;
    SOCKET listenSock, replySock;
    struct sockaddr_in server, client;
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

    if ((listenSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET)
    {
        int error = WSAGetLastError();
        printf("Creating a listening socket failed. Error code: %d\n", error);
        return error;
    }

    printf("Listen Socket Created!\n");

    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_family = AF_INET;
    server.sin_port = htons(10240);

    // Bind data to listen socket
    if (bind(listenSock, (struct sockaddr*) &server, sizeof(server)) == SOCKET_ERROR)
    {
        int error = WSAGetLastError();
        printf("Binding listening socket failed. Error code: %d\n", error);
        return error;
    }

    printf("Binding Complete!\nListening for data!\n");

    listen(listenSock, 3);

    int addr_inSize = sizeof(struct sockaddr_in);

    while ((replySock = accept(listenSock, (struct sockaddr*) &client, &addr_inSize)) != INVALID_SOCKET)
    {
        printf("Accepted connection!\n");
        strcpy_s(sendBuffer, "Hello Client!");

        if(send(replySock, sendBuffer, strlen(sendBuffer), 0) == 0)
        {
            int error = WSAGetLastError();
            printf("Sending failed. Error code: %d\n", error);
            return error;
        }

        if ((recvSize = recv(replySock, replyBuffer, MESSAGESIZE, 0)) == SOCKET_ERROR)
        {
            int error = WSAGetLastError();
            printf("Receiving failed. Error code: %d\n", error);
            return error;
        }

        replyBuffer[recvSize] = 0;

        printf("Received data! %s\n", replyBuffer);

        break; // After we have a connection, go ahead and exit loop
    }

    if (replySock == INVALID_SOCKET)
    {
        int error = WSAGetLastError();
        printf("Failed to get a reply socket. Error code: %d\n", error);
        return error;
    }

    closesocket(listenSock);

    printf("Socket Closed!\n");

    WSACleanup();

    return 0;
}


