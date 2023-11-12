#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define QUIC_DATA_SIZE 100
#define UDP_PACKET_SIZE 1200

typedef struct {

    uint8_t data[QUIC_DATA_SIZE];
    uint16_t length;
} QUICData;


typedef struct {
    char address[20];//IPV4
    uint16_t port;
} Destination;

bool encapsulatedQUICData(QUICData *quicData, Destination *destination, uint8_t *buffer, uint16_t *bufferLength){
    if(!quicData || !destination || !buffer || !bufferLength){
        return false;
        printf("Error: Invalid parameters\n");
    }
    if(quicData->length > QUIC_DATA_SIZE){
        return false;
        printf("Error: Invalid QUIC data size\n");
    }

    if(quicData->length > *bufferLength){
        printf("Error: Buffer is too small\n");
        return false;
    }

    memcpy(buffer, quicData->data, quicData->length);
    *bufferLength = quicData->length;
    return true;
};

bool SendUDPEncapsulatedQUICData(QUICData *quicData, Destination *destination){
    uint8_t buffer[UDP_PACKET_SIZE];
    uint16_t bufferLength = UDP_PACKET_SIZE;
    if(!encapsulatedQUICData(quicData, destination, buffer, &bufferLength)){
        printf("Error: Invalid parameters\n");
        return false;
    }
    
    
    int sockfd;
    if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0){
        printf("Error: Socket creation failed\n");
        return false;
    }

    struct sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(destination->port);
    serverAddr.sin_addr.s_addr = inet_addr(destination->address);

    if(sendto(sockfd, (const char *)buffer, bufferLength, 0, (const struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0){
        printf("Error: Sendto failed\n");
        return false;
    }

    close(sockfd);
    return true;


    


};
