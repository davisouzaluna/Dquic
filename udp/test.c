#include <stdio.h>
#include "udp_library.h"

#define MAX_DATA_SIZE 1024

int main() {
    UDPContext context;
    int port = 8080; // Port for communication

    char data_to_send[] = "Oi catatau!";
    char received_data[MAX_DATA_SIZE];

    // Initialize UDP
    if (!UDP_Init(&context, port)) {
        fprintf(stderr, "Error initializing UDP\n");
        return 1;
    }

    // Send data
    if (!UDP_Send(&context, "127.0.0.1", port, data_to_send, sizeof(data_to_send))) {
        fprintf(stderr, "Error sending data\n");
        UDP_Close(&context);
        return 1;
    }
    printf("Data sent successfully: %s\n", data_to_send);

    // Receive data
    int received_bytes = UDP_Receive(&context, received_data, MAX_DATA_SIZE);
    if (received_bytes < 0) {
        fprintf(stderr, "Error receiving data\n");
        UDP_Close(&context);
        return 1;
    }
    received_data[received_bytes] = '\0'; // Null-terminate the received data

    printf("Received data: %s\n", received_data);

    // Close the UDP connection
    UDP_Close(&context);

    return 0;
}
