// Client.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _WINSOCK_DEPRECATED_NO_WARNINGS // This turns off the warnings on moving to inet_pton
#include <stdio.h>
#include <string.h>
#include <winsock2.h>
#include <ws2tcpip.h> // needed for inet_pton

#pragma comment(lib, "ws2_32.lib") // loads the winsock library

#define UDP 0 // Set this to 1 for UDP, 0 for TCP

#define MESSAGESIZE 1024 // Resued value for message size

int main()
{
    printf("Client Application\n");

    WSADATA wsa; // Winsock object, required for all applications using winsock
    SOCKET sock; // socket
    struct sockaddr_in server; // address object for the server

    // buffers for seding and receiving
    char sendBuffer[MESSAGESIZE];
    char replyBuffer[MESSAGESIZE];

    // Amount of data received
    int recvSize;

    // Starts up winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
    {
        int error = WSAGetLastError();
        printf("Initialize failed. Error code: %d\n", error);
        return error;
    }

    printf("Winsock Initialized!\n");

    // This socket setup is differenct, depending on UDP or TCP
    if (UDP == 1)
    {
        if ((sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == INVALID_SOCKET) // Setup UDP socket
        {
            int error = WSAGetLastError();
            printf("Creating a socket failed. Error code: %d\n", error);
            return error;
        }
    }
    else
    {
        if ((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET) // Setup TCP socket
        {
            int error = WSAGetLastError();
            printf("Creating a socket failed. Error code: %d\n", error);
            return error;
        }
    }

    printf("Socket Created!\n");
    
    // Setup server address and port
    //InetPton(AF_INET, (PCWSTR)("127.0.0.1"), &server.sin_addr.s_addr);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(10240);

    // No need to connect in UDP
    if (UDP == 0)
    {
        if (connect(sock, (struct sockaddr*) &server, sizeof(server)) != 0) // Connects to TCP server, initial handshake
        {
            int error = WSAGetLastError();
            printf("Connecting failed. Error code: %d\n", error);
            return error;
        }

        printf("Connected to server!\n");
    }

    // Set string in send buffer
    strcpy_s(sendBuffer, "Hello Sever!");

    // Send data to server
    if (UDP == 1)
    {
        // sento sends a message to a specific IP address, needed for UDP
        if (sendto(sock, sendBuffer, strlen(sendBuffer), 0, (struct sockaddr*) &server, sizeof(server)) == 0)
        {
            int error = WSAGetLastError();
            printf("Sending failed. Error code: %d\n", error);
            return error;
        }
    }
    else
    {
        // Send will send data on the opened TCP connection
        if (send(sock, sendBuffer, strlen(sendBuffer), 0) == 0)
        {
            int error = WSAGetLastError();
            printf("Sending failed. Error code: %d\n", error);
            return error;
        }
    }

    printf("Sent data to server!\n");

    // Only listen for a reply from the server if we are TCP
    if (UDP == 0)
    {
        // wait for a reply on the same socket for TCP connections
        if ((recvSize = recv(sock, replyBuffer, MESSAGESIZE, 0)) == SOCKET_ERROR)
        {
            int error = WSAGetLastError();
            printf("Receiving failed. Error code: %d\n", error);
            return error;
        }

        // Set the null character in the buffer to limit string
        replyBuffer[recvSize] = 0;

        printf("Received data! %s\n", replyBuffer);
    }

    // Close socket
    closesocket(sock);

    printf("Socket Closed!\n");

    // Shutdown Winsock
    WSACleanup();

    return 0;
}


