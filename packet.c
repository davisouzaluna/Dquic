/*
    Davi Souza de Luna

    Licensed under the MIT License.

    Abstract:
        This file contains the implementation of the packet header. Actually, my reference is the rfc

*/
#include <stdint.h>
#include <stddef.h> //for NULL
#include "packet.h"




int handlePacket(enum HeaderHandshakeType type) {
    struct Header header;
    struct NEW_TOKEN_Frame newTokenFrame;
    switch (type) {
        case INITIAL:
                setupInitialPacket(&header ,&newTokenFrame);
            break;
        case ZERO_RTT:
            break;
        case HANDSHAKE:
            break;
        case RETRY:
            break;
        default:
            return -1;//error signal
    }
    return 0; // Return 0 if everything is ok
};

void setupInitialPacket(struct Header *header, struct NEW_TOKEN_Frame *newTokenFrame){
    header->formHeader = 0x01;
    header->fixedBit = 1;//fixed bit is 1
    header->versionSpecific = 0x00;
    header->version = 0x00;
    header->DConnIDLen = 0x00;
    header->DConnID = 0x00;
    header->OConnIDLen = 0x00;
    header->OConnID = 0x00;
    header->Sversion = 0x00;
    header->initialFields.tokenLength = 0x00;//initially the token length is 0
    header->initialFields.token = NULL;//remenber the flag

    newTokenFrame->type = QUIC_NEW_TOKEN_FRAME;
    newTokenFrame->length = header->initialFields.tokenLength;//same as header struct
    newTokenFrame->token = header->initialFields.token;
};





void longHeader(struct Header *header){
    header->formHeader = 0x01;
    header->versionSpecific = 0x00;
    header->version = 0x00;  
    header->DConnIDLen = 0x00;
    header->DConnID = 0x00;
    header->OConnIDLen = 0x00;
    header->OConnID = 0x00;
}

void shortHeader(struct Header *header){//function to create a initial short header
    header->formHeader = 0x00;
    header->versionSpecific = 0x00;
    header->DConnIDLen = 0x00;
    header->DConnID = 0x00;
}





void versionNegotiation(struct Header *header) {
   
}