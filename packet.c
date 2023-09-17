/*
    Davi Souza de Luna

    Licensed under the MIT License.

    Abstract:
        This file contains the implementation of the packet header. Actually, my reference is the rfc

*/
#include <stdint.h>
#include <stddef.h> //for NULL
#include "packet.h"

struct Header{
   uint8_t formHeader; //The form header must have 1 bit
   uint8_t versionSpecific; //The form specific must have 7 bits
   uint32_t *version;//The version must have 32 bits and initially(before connection it's null)
   uint8_t DConnIDLen;//The Destination connection length must have 8 bits
   uint16_t DConnID;//arbitrary value
    uint16_t OConnIDLen;//The origin connection length must have 16 bits
    uint8_t OConnID;//The  origin connection ID must have 8 bits
   uint32_t Sversion;//Supported version
   //there is also the version specific data but i didn't put it here for now
};

enum QUICFrameType {
    QUIC_STREAM_FRAME,
    QUIC_ACK_FRAME,
    QUIC_PADDING_FRAME,
    QUIC_CRYPTO_FRAME,
    QUIC_NEW_TOKEN_FRAME,
    QUIC_MAX_DATA_FRAME,
    QUIC_RESET_STREAM_FRAME,
    QUIC_STOP_SENDING_FRAME,
    QUIC_MAX_STREAM_DATA_FRAME,
    QUIC_MAX_STREAMS_FRAME,
    QUIC_DATA_BLOCKED_FRAME,
    QUIC_STREAM_DATA_BLOCKED_FRAME,
    QUIC_STREAM_BLOCKED_FRAME,
    QUIC_NEW_CONNECTION_ID_FRAME,
    QUIC_RETIRE_CONNECTION_ID_FRAME,
    QUIC_PATH_CHALLENGE_FRAME,
    QUIC_PATH_RESPONSE_FRAME,
    QUIC_CONNECTION_CLOSE_FRAME,
    QUIC_HANDSHAKE_DONE_FRAME,
    
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

void shortHeader(struct Header *header){//function to create a initial long header
    header->formHeader = 0x00;
    header->versionSpecific = 0x00;
    header->DConnIDLen = 0x00;
    header->DConnID = 0x00;
}





void versionNegotiation(struct Header *header) {
   
}