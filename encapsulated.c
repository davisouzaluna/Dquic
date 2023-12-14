// encapsulated.c

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include "main.h"

#define UDP_PACKET_SIZE 1200

bool encapsulatedQUICData(QUICData *quicData, Destination *destination, uint32_t connectionID) {
    if (!quicData || !destination) {
        printf("Error: Invalid parameters\n");
        return false;
    }

    // Here you can format and encapsulate your QUIC data
    // For demonstration purposes, let's assume the data is a string "Hello, QUIC!"
    snprintf((char *)quicData->data, QUIC_DATA_SIZE, "Hello, QUIC!");
    quicData->length = strlen((char *)quicData->data);

    // You might include the connection ID in your QUICData
    // For demonstration purposes, I'm assuming connection ID is a 32-bit integer
    memcpy(quicData->data + quicData->length, &connectionID, sizeof(uint32_t));
    quicData->length += sizeof(uint32_t);

    // Assuming the destination address is already set
    // Copy destination information to QUICData if needed
    // memcpy(quicData->destination, destination, sizeof(Destination));

    return true;
}

bool SendUDPEncapsulatedQUICData(QUICData *quicData, Destination *destination) {
    if (!quicData || !destination) {
        printf("Error: Invalid parameters\n");
        return false;
    }

    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        printf("Error: Socket creation failed\n");
        return false;
    }

    struct sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(destination->port);
    serverAddr.sin_addr.s_addr = inet_addr(destination->address);

    if (sendto(sockfd, (const char *)quicData->data, quicData->length, 0, (const struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        printf("Error: Sendto failed\n");
        close(sockfd);
        return false;
    }

    close(sockfd);
    return true;
}
