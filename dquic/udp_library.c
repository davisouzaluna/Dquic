#include "udp_library.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024 // Define a maximum buffer size to 1024 bytes

bool UDP_Init(UDPContext *context, int port) {
    context->sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (context->sockfd < 0) {
        perror("Error creating the socket");
        return false;
    }

    // Configure server information
    memset(&context->server_addr, 0, sizeof(context->server_addr));
    context->server_addr.sin_family = AF_INET;
    context->server_addr.sin_addr.s_addr = INADDR_ANY;
    context->server_addr.sin_port = htons(port);

    // Bind the socket to the specified port
    if (bind(context->sockfd, (struct sockaddr *)&context->server_addr, sizeof(context->server_addr)) < 0) {
        perror("Error binding the socket");
        close(context->sockfd);
        return false;
    }

    context->port = port;

    return true;
}

bool UDP_Send(UDPContext *context, const char *destination_ip, int destination_port, const char *data, int data_length) {
    struct sockaddr_in dest_addr;

    // Configure destination information
    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_addr.s_addr = inet_addr(destination_ip);
    dest_addr.sin_port = htons(destination_port);

    // Send data to the destination
    int sent_bytes = sendto(context->sockfd, data, data_length, 0, (struct sockaddr *)&dest_addr, sizeof(dest_addr));
    if (sent_bytes < 0) {
        perror("Error sending data");
        return false;
    }

    return true;
}

int UDP_Receive(UDPContext *context, char *buffer, int buffer_length) {
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);

    // Receive data from the client
    int received_bytes = recvfrom(context->sockfd, buffer, buffer_length, 0, (struct sockaddr *)&client_addr, &client_len);
    if (received_bytes < 0) {
        perror("Error receiving data");
        return -1;
    }

    return received_bytes;
}

void UDP_Close(UDPContext *context) {
    close(context->sockfd);
}
