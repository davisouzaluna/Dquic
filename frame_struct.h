
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

typedef struct RESET_STREAM_FRAME{
    uint8_t type= RESET_STREAM;
    int streamId;
    int applicationErrorCode;
    int finalSize;
    }RESET_STREAM_FRAME;

typedef struct STOP_SENDING_FRAME{
    uint8_t type= STOP_SENDING;
    int streamId;
    int applicationErrorCode;
    }STOP_SENDING_FRAME;

typedef struct CRYPTO_FRAME{
    uint8_t type= CRYPTO;
    int offset;
    int length;
    int cryptoData;
    }CRYPTO_FRAME;

typedef struct NEW_TOKEN_FRAME{
    uint8_t type= NEW_TOKEN;
    int length;
    int token;
    }NEW_TOKEN_FRAME;

typedef struct STREAM_FRAME{    
    uint8_t type= STREAM;
    int streamId;
    int offset;
    int length;
    int streamData;
    }STREAM_FRAME;

typedef struct MAX_DATA_FRAME{
    uint8_t type= MAX_DATA;
    int maximumData;
    }MAX_DATA_FRAME;

typedef struct MAX_STREAM_DATA_FRAME{
    uint8_t type= MAX_STREAM_DATA;
    int streamId;
    int maximumStreamData;
    }MAX_STREAM_DATA_FRAME;

//Bidirecional streams
typedef struct MAX_STREAMS_BIDI_FRAME{
    uint8_t type= MAX_STREAMS_BIDI;
    int maximumStreamsBidi;
    }MAX_STREAMS_BIDI_FRAME;

//Unidirecional streams
typedef struct MAX_STREAMS_UNI_FRAME{
    uint8_t type= MAX_STREAMS_UNI;
    int maximumStreamsUni;
    }MAX_STREAMS_UNI_FRAME;


typedef struct DATA_BLOCKED_FRAME{
    uint8_t type= DATA_BLOCKED;
    int dataLimit;
    }DATA_BLOCKED_FRAME;

typedef struct STREAM_DATA_BLOCKED_FRAME{
    uint8_t type= STREAM_DATA_BLOCKED;
    int streamId;
    int dataLimit;
    }STREAM_DATA_BLOCKED_FRAME;

typedef struct STREAMS_BLOCKED_BIDI_FRAME{
    uint8_t type= STREAMS_BLOCKED_BIDI;
    int streamLimit;
    }STREAMS_BLOCKED_BIDI_FRAME;

typedef struct STREAMS_BLOCKED_UNI_FRAME{
    uint8_t type= STREAMS_BLOCKED_UNI;
    int streamLimit;
    }STREAMS_BLOCKED_UNI_FRAME;

typedef struct NEW_CONNECTION_ID_FRAME{
    uint8_t type= NEW_CONNECTION_ID;
    int sequenceNumber;
    int connectionId;
    int statelessResetToken;
    }NEW_CONNECTION_ID_FRAME;

typedef struct RETIRE_CONNECTION_ID_FRAME{
    uint8_t type= RETIRE_CONNECTION_ID;
    int sequenceNumber;
    }RETIRE_CONNECTION_ID_FRAME;

typedef struct PATH_CHALLENGE_FRAME{    
    uint8_t type= PATH_CHALLENGE;
    int data;
    }PATH_CHALLENGE_FRAME;

typedef struct PATH_RESPONSE_FRAME{
    uint8_t type= PATH_RESPONSE;
    int data;
    }PATH_RESPONSE_FRAME;

typedef struct CONNECTION_CLOSE_FRAME{
    uint8_t type= CONNECTION_CLOSE;
    int errorCode;
    int frameType;
    int reasonPhrase;
    }CONNECTION_CLOSE_FRAME;

typedef struct APPLICATION_CLOSE_FRAME{
    uint8_t type= APPLICATION_CLOSE;
    int errorCode;
    int frameType;
    int reasonPhrase;
    }APPLICATION_CLOSE_FRAME;

typedef struct HANDSHAKE_DONE_FRAME{
    uint8_t type= HANDSHAKE_DONE;
    }HANDSHAKE_DONE_FRAME;

typedef struct FRAME{
    uint8_t type;
    int largestAcknowledged;
    int ackDelay;
    int ackRangeCount;
    int firstAckRange;
    int ecnCount;
    int ecnSection;
    int streamId;
    int applicationErrorCode;
    int finalSize;
    int offset;
    int length;
    int cryptoData;
    int maximumData;
    int maximumStreamData;
    int maximumStreamsBidi;
    int maximumStreamsUni;
    int dataLimit;
    int streamLimit;
    int sequenceNumber;
    int connectionId;
    int statelessResetToken;
    int data;
    int errorCode;
    int frameType;
    int reasonPhrase;
    }FRAME;

typedef struct FRAME_LIST{
    FRAME frame;
    struct FRAME_LIST *next;
    }FRAME_LIST;

