/*
    Davi Souza de Luna

    Licensed under the MIT License.

    Abstract:
        This file contains the header for packet functions.

*/

#ifndef packet_h_included
#define packet_h_included

typedef struct Header{
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

void longHeader(struct Header Header){
};

void shortHeader(struct Header Header){//function to create a initial long header
};

void handshakeHeader(struct Header Header){
};

void zeroRTTHeader(struct Header Header){
};

void initialHandshakeHeader(struct Header Header){
};

void 

#endif
