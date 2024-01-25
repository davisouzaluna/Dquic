
/*

Author: Davi Souza de Luna

Licensed under the MIT License.


Abstract: In this code has the head frame functions and the structs

*/


typedef enum frameType{
    PADDING = 0x00,
    PING= 0x01,
    ACK = 0x02,
    ACK_ECN = 0x03,
    RESET_STREAM = 0x04,
    STOP_SENDING = 0x05,
    CRYPTO = 0x06,
    NEW_TOKEN = 0x07,
    STREAM = 0x08,
    MAX_DATA = 0x10,
    MAX_STREAM_DATA = 0x11,
    MAX_STREAMS_BIDI = 0x12,
    MAX_STREAMS_UNI = 0x13,
    DATA_BLOCKED = 0x14,
    STREAM_DATA_BLOCKED = 0x15,
    STREAMS_BLOCKED_BIDI = 0x16,
    STREAMS_BLOCKED_UNI = 0x17,
    NEW_CONNECTION_ID = 0x18,
    RETIRE_CONNECTION_ID = 0x19,
    PATH_CHALLENGE = 0x1a,
    PATH_RESPONSE = 0x1b,
    CONNECTION_CLOSE = 0x1c,
    APPLICATION_CLOSE = 0x1d,
    HANDSHAKE_DONE = 0x1e,
};


/*Is necessary to implement the logic to decode and encode the frames, because after the encoding the frames will be sent to the server in an UDP packet.*/

typedef struct PADDING_FRAME{
    uint8_t type = PADDING;
    }PADDING_FRAME;

typedef struct PING_FRAME{
    uint8_t type= PING;
    }PING_FRAME;

typedef struct ACK_FRAME{
    uint8_t type= ACK;
    int largestAcknowledged;
    int ackDelay;
    int ackRangeCount;
    int firstAckRange;
    //is necessary to has a review of this frame
    }ACK_FRAME;

typedef struct ACK_ECN_FRAME{
    uint8_t type= ACK_ECN;
    int largestAcknowledged;
    int ackDelay;
    int ackRangeCount;
    int firstAckRange;
    int ecnCount;
    int ecnSection;

    }ACK_ECN_FRAME;