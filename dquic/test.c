#include <stdio.h>
#include "main.h"

int main() {
    struct Header header;
    struct NEW_TOKEN_Frame newTokenFrame;

    setupInitialPacket(&header, &newTokenFrame);
    //setupHandshakePacket(&header);

    printf("====================================\n");
    printf("Identify Header Bit: %02x\n", header.identifyBit);
    printf("formHeader: %02x\n", header.formHeader);
    printf("fixedBit: %02x\n", header.fixedBit);
    printf("id:%08x\n", header.DConnID);
    printf("versionSpecific: %02x\n", header.versionSpecific);
    // ... continue exibindo os outros campos
    printf("====================================\n");

    return 0;
}

// gcc test.c packet.c -o saidaM