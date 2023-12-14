#include <stdio.h>
#include <string.h>
#include <string.h> 
#include "main.h"


int main() {
    // Create structures
    struct Header header;
    struct NEW_TOKEN_Frame newTokenFrame;

    // Setup initial packet
    setupInitialPacket(&header, &newTokenFrame);

    // Display the content of the structures
    printf("====================================\n");
    printf("Identify Header Bit: %02x\n", header.identifyBit);
    printf("formHeader: %02x\n", header.formHeader);
    printf("fixedBit: %02x\n", header.fixedBit);
    printf("id:%08x\n", header.DConnID);
    printf("versionSpecific: %02x\n", header.versionSpecific);
    // ... continue displaying other fields
    printf("====================================\n");

    // Send data over UDP
    UDPContext udpContext;
    int udpPort = 44444;  // Change this to your desired port
    const char *destinationIP = "127.0.0.1";  // Change this to your server's IP address

    // Initialize UDP context
    if (!UDP_Init(&udpContext, udpPort)) {
        fprintf(stderr, "Error initializing UDP\n");
        return 1;
    }

    int MAX_BUFFER_SIZE = 2048;
    // Convert the data structures to a string representation (you may need to implement this)
    char dataBuffer[MAX_BUFFER_SIZE];
    // Example: snprintf(dataBuffer, MAX_BUFFER_SIZE, "Identify Header Bit: %02x, formHeader: %02x, ...", header.identifyBit, header.formHeader, ...);

    // Send data over UDP
    if (!UDP_Send(&udpContext, destinationIP, udpPort, dataBuffer, strlen(dataBuffer))) {
        fprintf(stderr, "Error sending data over UDP\n");
        UDP_Close(&udpContext);
        return 1;
    }
    printf("Data sent over UDP\n");

    // Close the UDP connection
    UDP_Close(&udpContext);

    return 0;
}


//gcc test_encapsulate.c udp_library.c packet.c -o tst