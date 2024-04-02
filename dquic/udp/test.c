#include <stdio.h>
#include <string.h>
#include "udp_library.h"

#define MAX_DATA_SIZE 1024

int main() {
    UDPContext context;
    int port = 8888; // Port for communication

    char data_to_send[MAX_DATA_SIZE];
    char received_data[MAX_DATA_SIZE];

    // Initialize UDP
    if (!UDP_Init(&context, port)) {
        fprintf(stderr, "Error initializing UDP\n");
        return 1;
    }

    printf("Enter the message to send: ");
    fgets(data_to_send, MAX_DATA_SIZE, stdin); // Reading the message from the user

    // Send data
    if (!UDP_Send(&context, "192.168.3.25", port, data_to_send, strlen(data_to_send))) {
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
