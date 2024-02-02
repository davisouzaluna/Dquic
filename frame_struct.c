



//In this code is necessary alter the packet.c file, because it's has a new token frame.

/*The frames not included are:


*/
#include "main.h"

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

bool encodePING_FRAME(PING_FRAME *pingFrame, uint8_t *buffer, size_t *size) {
    if (pingFrame->type == PING) {
        *size = 1;
        buffer[0] = (uint8_t)pingFrame->type;
    } else {
        *size = 0;
    }
    return true;
}

bool decodePING_FRAME(PING_FRAME *pingFrame, const uint8_t *buffer, size_t *size) {
    if (*size < 1) {
        return false;
    }
    pingFrame->type = (FRAME_TYPE)buffer[0];
    *size = 1;
    return true;
}

