/*
    Davi Souza de Luna

    Licensed under the MIT License.

    Abstract:
        This file contains the implementation of the packet header.

*/
#include <stdint.h>
#include <stddef.h> //for NULL

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

void longHeader(struct Header Header){
    Header.formHeader = 0x01;
    Header.versionSpecific = 0x00;
    Header.version = NULL;//after creation of package, must be changed to other version(I need to create supported versions list in array)
    Header.DConnIDLen = 0x00;
    Header.DConnID = 0x00;
    Header.OConnIDLen = 0x00;
    Header.OConnID = 0x00;
};

void shortHeader(struct Header Header){//function to create a initial long header
    Header.formHeader = 0x00;
    Header.versionSpecific = 0x00;
    Header.DConnIDLen = 0x00;
    Header.DConnID = 0x00;
};

void versionNegotiation(struct Header Header){
}