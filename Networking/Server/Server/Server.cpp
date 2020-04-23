// Server.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <stdio.h>
#include <winsock2.h>
#include <string.h>

#pragma comment(lib, "ws2_32.lib") // loads the winsock library

#define UDP 0 // Set this to 1 for UDP, 0 for TCP
#define MESSAGESIZE 1024 // Resued value for message size

int main()
{
    printf("Server Application\n");

    WSADATA wsa; // Winsock object, required for all applications using winsock
    SOCKET listenSock, replySock; // sockets
    struct sockaddr_in server, client; // address structures for the server to listen and client to send to

    // buffers for seding and receiving
    char sendBuffer[MESSAGESIZE];
    char replyBuffer[MESSAGESIZE];

    // amount of data received
    int recvSize;

    //Initialisze winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
    {
        int error = WSAGetLastError();
        printf("Initialize failed. Error code: %d\n", error);
        return error;
    }

    printf("Winsock Initialized!\n");

    if (UDP == 1)
    {
        //Setup UDP socket
        if ((listenSock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == INVALID_SOCKET)
        {
            int error = WSAGetLastError();
            printf("Creating a listening socket failed. Error code: %d\n", error);
            return error;
        }
    }
    else
    {
        //Setup TCP socket
        if ((listenSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET)
        {
            int error = WSAGetLastError();
            printf("Creating a listening socket failed. Error code: %d\n", error);
            return error;
        }
    }

    printf("Listen Socket Created!\n");

    // Set up structure for socket to listen on: listen on any IP address and port 10240
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

    if (UDP == 1)
    {
        // If we are UDP, just wait for a message to show up
        if ((recvSize = recv(listenSock, replyBuffer, MESSAGESIZE, 0)) == SOCKET_ERROR)
        {
            int error = WSAGetLastError();
            printf("Receiving failed. Error code: %d\n", error);
            return error;
        }
        replyBuffer[recvSize] = 0;

        printf("Received data! %s\n", replyBuffer);
    }
    else
    {
        Listen for TCP connection
        if (listen(listenSock, 3) == SOCKET_ERROR)
        {
            int error = WSAGetLastError();
            printf("Listening on socket failed. Error code: %d\n", error);
            return error;
        }

        int addr_inSize = sizeof(struct sockaddr_in);
        // Server waits to accept a connection
        while ((replySock = accept(listenSock, (struct sockaddr*) &client, &addr_inSize)) != INVALID_SOCKET)
        {
            printf("Accepted connection!\n");

            strcpy_s(sendBuffer, "Hello Client!");

            // Once we have a connection, say hi to the client
            if (send(replySock, sendBuffer, strlen(sendBuffer), 0) == 0)
            {
                int error = WSAGetLastError();
                printf("Sending failed. Error code: %d\n", error);
                return error;
            }

            // See if the client sends us anything
            if ((recvSize = recv(replySock, replyBuffer, MESSAGESIZE, 0)) == SOCKET_ERROR)
            {
                int error = WSAGetLastError();
                printf("Receiving failed. Error code: %d\n", error);
                return error;
            }

            // Set the end string character so it displays correctly
            replyBuffer[recvSize] = 0;

            printf("Received data! %s\n", replyBuffer);

            break; // After we have a connection, go ahead and exit loop
        }

        // If socket is bad, let us know
        if (replySock == INVALID_SOCKET)
        {
            int error = WSAGetLastError();
            printf("Failed to get a reply socket. Error code: %d\n", error);
            return error;
        }

        // Close reply socket
        closesocket(replySock);
    }


    // Close listen socket
    closesocket(listenSock);

    printf("Socket Closed!\n");

    // Shutdown Winsock
    WSACleanup();

    return 0;
}


