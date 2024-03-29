



//In this code is necessary alter the packet.c file, because it's has a new token frame.

/*The frames not included are:


*/
#include "main.h"
#include <stdint.h>

/* The padding implementation have some problems, so it's not included in this version of the code.

bool encodePADDING_FRAME(PADDING_FRAME *paddingFrame, uint8_t *buffer, size_t *size, size_t paddingSize) {
    if (paddingFrame->type == PADDING) {
        if (paddingSize > 256) {
            return false;
        }

        buffer[0] = (uint8_t)paddingSize;
        memset(buffer + 1, 0, paddingSize);
        *size = paddingSize + 1;
    } else {
        *size = 0;
    }
    return true;
}

bool decodePADDING_FRAME(PADDING_FRAME *paddingFrame, const uint8_t *buffer, size_t *size) {
    if (*size < 1) {
        return false;
    }
    *size = 1;
    return true;
}

*/

void writeUint64(uint64_t value, uint8_t *buffer){

    if((uint8_t*)&testValue == 1){//Is little endian
        buffer[0] = (uint8_t)(value & 0xFF);
        buffer[1] = (uint8_t)((value >> 8) & 0xFF);
        buffer[2] = (uint8_t)((value >> 16) & 0xFF);
        buffer[3] = (uint8_t)((value >> 24) & 0xFF);
        buffer[4] = (uint8_t)((value >> 32) & 0xFF);
        buffer[5] = (uint8_t)((value >> 40) & 0xFF);
        buffer[6] = (uint8_t)((value >> 48) & 0xFF);
        buffer[7] = (uint8_t)((value >> 56) & 0xFF);
    }else{
        buffer[7] = (uint8_t)(value & 0xFF);
        buffer[6] = (uint8_t)((value >> 8) & 0xFF);
        buffer[5] = (uint8_t)((value >> 16) & 0xFF);
        buffer[4] = (uint8_t)((value >> 24) & 0xFF);
        buffer[3] = (uint8_t)((value >> 32) & 0xFF);
        buffer[2] = (uint8_t)((value >> 40) & 0xFF);
        buffer[1] = (uint8_t)((value >> 48) & 0xFF);
        buffer[0] = (uint8_t)((value >> 56) & 0xFF);
    }
}


bool encodePING_FRAME(PING_FRAME *pingFrame, uint8_t *buffer, size_t *size) {
    if (pingFrame->type == PING) {
        *size = 1;
        buffer[0] = (uint8_t)pingFrame->type;
    } else {
        *size = 0;
    }
    return true;
}

//create a function to answer the PING frame with a "Pong"(retrieval, the type is a same, the PING frame) 

bool decodePING_FRAME(PING_FRAME *pingFrame, const uint8_t *buffer, size_t *size) {
    if (*size < 1) {
        return false;
    }
    pingFrame->type = (FRAME_TYPE)buffer[0];
    *size = 1;
    return true;
}

bool encodeMAX_DATA_FRAME(MAX_DATA_FRAME *maxDataFrame, uint8_t *buffer, size_t *size) {
    if (maxDataFrame->type == MAX_DATA) {
        *size = 9;
        buffer[0] = (uint8_t)maxDataFrame->type;
        writeUint64(maxDataFrame->maximumData, buffer + 1);
        return true;
    } else {
        *size = 0;
        return false;
    }
}

bool decodeMAX_DATA_FRAME(MAX_DATA_FRAME *maxDataFrame, const uint8_t *buffer, size_t *size) {
    if (*size < 9) {
        return false;
    }
    maxDataFrame->type = (FRAME_TYPE)buffer[0];
    maxDataFrame->maximumData = (uint64_t)buffer[1] | (uint64_t)buffer[2] << 8 | (uint64_t)buffer[3] << 16 | (uint64_t)buffer[4] << 24 | (uint64_t)buffer[5] << 32 | (uint64_t)buffer[6] << 40 | (uint64_t)buffer[7] << 48 | (uint64_t)buffer[8] << 56;
    *size = 9;
    return true;
}






