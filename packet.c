/*
    Davi Souza de Luna

    Licensed under the MIT License.

    Abstract:
        This file contains the implementation of the packet header. Actually, my reference is the rfc

*/
#include <stdint.h>
#include <stddef.h> //for NULL
#include "main.h"




int handlePacket(enum HeaderHandshakeType type) {
    struct Header header;
    struct NEW_TOKEN_Frame newTokenFrame;
    switch (type) {
        case INITIAL:
                setupInitialPacket(&header ,&newTokenFrame);
            break;
        case ZERO_RTT:
                setupZeroRTTHeader(&header);
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
    header->long_Packet_Type = 0x00;
    header->initialFields.tokenLength = 0x00;//initially the token length is 0
    header->initialFields.token = NULL;//remenber the flag

    newTokenFrame->type = QUIC_NEW_TOKEN_FRAME;
    newTokenFrame->length = header->initialFields.tokenLength;//same as header struct
    newTokenFrame->token = header->initialFields.token;

    //Is necessary implements the payload field to store the data. Other frames will be implemented later.
};





void longHeader(struct Header *header){
    header->formHeader = 0x01;
    header->versionSpecific = 0x00;
    header->version = 0x00;  
    header->DConnIDLen = 0x00;
    header->DConnID = 0x00;
    header->OConnIDLen = 0x00;
    header->OConnID = 0x00;
    header->fixedBit = 0x01;
}

void shortHeader(struct Header *header){//function to create a initial short header
    header->formHeader = 0x00;
    header->versionSpecific = 0x00;
    header->DConnIDLen = 0x00;
    header->DConnID = 0x00;
}

void setupZeroRTTHeader(struct Header *header){
    longHeader(header);//common parameters to ZeroRTT and Initial headers
    header->long_Packet_Type = 0x01;

}

/*
uint8_t* encodePacketSize(uint64_t size, uint8_t *encodedSize) {
    if (size < 64) {
        // Codifica em 1 byte (bits 00)
        encodedSize[0] = (uint8_t)size;
        return encodedSize + 1;
    } else if (size < 16384) {
        // Codifica em 2 bytes (bits 01)
        encodedSize[0] = (uint8_t)((size >> 8) | 0x40);
        encodedSize[1] = (uint8_t)size;
        return encodedSize + 2;
    } else if (size < 1073741824) {
        // Codifica em 4 bytes (bits 10)
        encodedSize[0] = (uint8_t)((size >> 24) | 0x80);
        encodedSize[1] = (uint8_t)(size >> 16);
        encodedSize[2] = (uint8_t)(size >> 8);
        encodedSize[3] = (uint8_t)size;
        return encodedSize + 4;
    } else {
        // Codifica em 8 bytes (bits 11)
        encodedSize[0] = 0xC0;
        encodedSize[1] = (uint8_t)(size >> 56);
        encodedSize[2] = (uint8_t)(size >> 48);
        encodedSize[3] = (uint8_t)(size >> 40);
        encodedSize[4] = (uint8_t)(size >> 32);
        encodedSize[5] = (uint8_t)(size >> 24);
        encodedSize[6] = (uint8_t)(size >> 16);
        encodedSize[7] = (uint8_t)(size >> 8);
        encodedSize[8] = (uint8_t)size;
        return encodedSize + 9;
    }
}


uint64_t decodePacketSize(const uint8_t *encodedSize, size_t *bytesRead) {
    uint8_t firstByte = encodedSize[0];
    uint8_t lengthBits = (firstByte & 0xC0) >> 6;

    if (lengthBits == 0) {
        *bytesRead = 1;
        return firstByte;
    } else if (lengthBits == 1) {
        *bytesRead = 2;
        return ((uint64_t)(firstByte & 0x3F) << 8) | encodedSize[1];
    } else if (lengthBits == 2) {
        *bytesRead = 4;
        return ((uint64_t)(firstByte & 0x3F) << 24) | ((uint64_t)encodedSize[1] << 16) | ((uint64_t)encodedSize[2] << 8) | encodedSize[3];
    } else {
        *bytesRead = 9;
        return ((uint64_t)(encodedSize[1]) << 56) | ((uint64_t)(encodedSize[2]) << 48) |
               ((uint64_t)(encodedSize[3]) << 40) | ((uint64_t)(encodedSize[4]) << 32) |
               ((uint64_t)(encodedSize[5]) << 24) | ((uint64_t)(encodedSize[6]) << 16) |
               ((uint64_t)(encodedSize[7]) << 8) | encodedSize[8];
    }
}
*/
void ConnnID(ConnIDLength){
uint16_t ConnID[ConnIDLength];
srand((unsigned int)time(NULL));
 for(int i=0;i<ConnIDLength;i++){
     ConnID[i] = (uint16_t)(rand() % 256);//generate random numbers to Connection ID. This is a simple example.
    }
};

void versionNegotiationPacket(struct Header *header, QUIC_VERSION_INFO *versionInfo){
    if(header->DConnID == 0x00){//connect ID is Null
        ConnnID(header->DConnIDLen);
    }
    header->formHeader = 0x01;
    header->unused = 0x00;//arbitrary bits for server;
    header->version= 0x00;
    header->DConnID;
    //Actually is imcomplete this package. I need to implement the version negotiation packet logic

};
 


