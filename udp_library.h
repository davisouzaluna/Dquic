// udp_library.h
#ifndef UDP_LIBRARY_H
#define UDP_LIBRARY_H

#include <stdbool.h>
#include <netinet/in.h>

// Structure to represent the UDP context
typedef struct {
    int sockfd; // UDP Socket
    int port;   // Local port to receive packets
    struct sockaddr_in server_addr; // Server address
} UDPContext;

// Function to initialize the UDP context
bool UDP_Init(UDPContext *context, int port);

// Function to send UDP data
bool UDP_Send(UDPContext *context, const char *destination_ip, int destination_port, const char *data, int data_length);

// Function to receive UDP data
int UDP_Receive(UDPContext *context, char *buffer, int buffer_length);

// Function to close the UDP context
void UDP_Close(UDPContext *context);

#endif
