#include "UdpReceiver.hpp"

// Kernel Type Includes for Networking
#include <bits/stdc++.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#include <iostream>

UdpReceiver::UdpReceiver(unsigned int port)
{
    mPort = port;

    this->initReceiver();
}

void UdpReceiver::listenForTraffic()
{
    struct sockaddr_in cliaddr;

    std::memset(&cliaddr, 0, sizeof(cliaddr));

    socklen_t len;
    int n;

    len = sizeof(cliaddr);

    n = recvfrom(mSockFd, (char*)mBuffer, MAX_BUFF_SIZE,
                 MSG_WAITALL, (struct sockaddr*)&cliaddr, &len);

    std::cout << "Shouldn't see this" << std::endl;

}

void UdpReceiver::initReceiver()
{
    struct sockaddr_in servaddr;

    // Create a socket file descriptor
    mSockFd = socket(AF_INET, SOCK_DGRAM, 0);
    if (mSockFd < 0)
    {
        perror("Socket creation failed! \n");
        std::exit(EXIT_FAILURE);
    }

    std::memset(&servaddr, 0, sizeof(servaddr));

    // Fill in related server information
    servaddr.sin_family = AF_INET; // IPv4
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(mPort);

    int status = bind(mSockFd, (const struct sockaddr*)&servaddr, sizeof(servaddr));
    if (status < 0)
    {
        perror("Bind failed! \n");
        std::exit(EXIT_FAILURE);
    }

    mIsInitialized = true;
}
