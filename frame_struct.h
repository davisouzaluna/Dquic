
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
    uint8_t type;// PADDING;
    }PADDING_FRAME;

bool encodePADDING_FRAME(PADDING_FRAME *paddingFrame, uint8_t *buffer, size_t *bufferLength);
bool decodePADDING_FRAME(PADDING_FRAME *paddingFrame, uint8_t *buffer, size_t *bufferLength);

typedef struct PING_FRAME{
    uint8_t type;// PING;
    }PING_FRAME;
bool encodePING_FRAME(PING_FRAME *pingFrame, uint8_t *buffer, size_t *bufferLength);
bool decodePING_FRAME(PING_FRAME *pingFrame, uint8_t *buffer, size_t *bufferLength);

typedef struct ACK_FRAME{
    uint8_t type;// ACK;
    int largestAcknowledged;
    int ackDelay;
    int ackRangeCount;
    int firstAckRange;
    //is necessary to has a review of this frame
    }ACK_FRAME;
bool encodeACK_FRAME(ACK_FRAME *ackFrame, uint8_t *buffer, size_t *bufferLength);
bool decodeACK_FRAME(ACK_FRAME *ackFrame, uint8_t *buffer, size_t *bufferLength);

typedef struct ACK_ECN_FRAME{
    uint8_t type;// ACK_ECN;
    int largestAcknowledged;
    int ackDelay;
    int ackRangeCount;
    int firstAckRange;
    int ecnCount;
    int ecnSection;

    }ACK_ECN_FRAME;
bool encodeACK_ECN_FRAME(ACK_ECN_FRAME *ackEcnFrame, uint8_t *buffer, size_t *bufferLength);
bool decodeACK_ECN_FRAME(ACK_ECN_FRAME *ackEcnFrame, uint8_t *buffer, size_t *bufferLength);


typedef struct RESET_STREAM_FRAME{
    uint8_t type;// RESET_STREAM;
    int streamId;
    int applicationErrorCode;
    int finalSize;
    }RESET_STREAM_FRAME;
bool encodeRESET_STREAM_FRAME(RESET_STREAM_FRAME *resetStreamFrame, uint8_t *buffer, size_t *bufferLength);
bool decodeRESET_STREAM_FRAME(RESET_STREAM_FRAME *resetStreamFrame, uint8_t *buffer, size_t *bufferLength);

typedef struct STOP_SENDING_FRAME{
    uint8_t type;// STOP_SENDING;
    int streamId;
    int applicationErrorCode;
    }STOP_SENDING_FRAME;
bool encodeSTOP_SENDING_FRAME(STOP_SENDING_FRAME *stopSendingFrame, uint8_t *buffer, size_t *bufferLength);
bool decodeSTOP_SENDING_FRAME(STOP_SENDING_FRAME *stopSendingFrame, uint8_t *buffer, size_t *bufferLength);

typedef struct CRYPTO_FRAME{
    uint8_t type;// CRYPTO;
    int offset;
    int length;
    int cryptoData;
    }CRYPTO_FRAME;
bool encodeCRYPTO_FRAME(CRYPTO_FRAME *cryptoFrame, uint8_t *buffer, size_t *bufferLength);
bool decodeCRYPTO_FRAME(CRYPTO_FRAME *cryptoFrame, uint8_t *buffer, size_t *bufferLength);

typedef struct NEW_TOKEN_FRAME{
    uint8_t type;//= NEW_TOKEN;
    int length;
    int token;
    }NEW_TOKEN_FRAME;
bool encodeNEW_TOKEN_FRAME(NEW_TOKEN_FRAME *newTokenFrame, uint8_t *buffer, size_t *bufferLength);
bool decodeNEW_TOKEN_FRAME(NEW_TOKEN_FRAME *newTokenFrame, uint8_t *buffer, size_t *bufferLength);

typedef struct STREAM_FRAME{    
    uint8_t type;// STREAM;
    int streamId;
    int offset;
    int length;
    int streamData;
    }STREAM_FRAME;
bool encodeSTREAM_FRAME(STREAM_FRAME *streamFrame, uint8_t *buffer, size_t *bufferLength);
bool decodeSTREAM_FRAME(STREAM_FRAME *streamFrame, uint8_t *buffer, size_t *bufferLength);

typedef struct MAX_DATA_FRAME{
    uint8_t type;// MAX_DATA;
    int maximumData;
    }MAX_DATA_FRAME;
bool encodeMAX_DATA_FRAME(MAX_DATA_FRAME *maxDataFrame, uint8_t *buffer, size_t *bufferLength);
bool decodeMAX_DATA_FRAME(MAX_DATA_FRAME *maxDataFrame, uint8_t *buffer, size_t *bufferLength);

typedef struct MAX_STREAM_DATA_FRAME{
    uint8_t type;// MAX_STREAM_DATA;
    int streamId;
    int maximumStreamData;
    }MAX_STREAM_DATA_FRAME;
bool encodeMAX_STREAM_DATA_FRAME(MAX_STREAM_DATA_FRAME *maxStreamDataFrame, uint8_t *buffer, size_t *bufferLength);
bool decodeMAX_STREAM_DATA_FRAME(MAX_STREAM_DATA_FRAME *maxStreamDataFrame, uint8_t *buffer, size_t *bufferLength);
//Bidirecional streams
typedef struct MAX_STREAMS_BIDI_FRAME{
    uint8_t type;// MAX_STREAMS_BIDI;
    int maximumStreamsBidi;
    }MAX_STREAMS_BIDI_FRAME;
bool encodeMAX_STREAMS_BIDI_FRAME(MAX_STREAMS_BIDI_FRAME *maxStreamsBidiFrame, uint8_t *buffer, size_t *bufferLength);
bool decodeMAX_STREAMS_BIDI_FRAME(MAX_STREAMS_BIDI_FRAME *maxStreamsBidiFrame, uint8_t *buffer, size_t *bufferLength);
//Unidirecional streams
typedef struct MAX_STREAMS_UNI_FRAME{
    uint8_t type;// MAX_STREAMS_UNI;
    int maximumStreamsUni;
    }MAX_STREAMS_UNI_FRAME;
bool encodeMAX_STREAMS_UNI_FRAME(MAX_STREAMS_UNI_FRAME *maxStreamsUniFrame, uint8_t *buffer, size_t *bufferLength);
bool decodeMAX_STREAMS_UNI_FRAME(MAX_STREAMS_UNI_FRAME *maxStreamsUniFrame, uint8_t *buffer, size_t *bufferLength);


typedef struct DATA_BLOCKED_FRAME{
    uint8_t type;// DATA_BLOCKED;
    int dataLimit;
    }DATA_BLOCKED_FRAME;
bool encodeDATA_BLOCKED_FRAME(DATA_BLOCKED_FRAME *dataBlockedFrame, uint8_t *buffer, size_t *bufferLength);
bool decodeDATA_BLOCKED_FRAME(DATA_BLOCKED_FRAME *dataBlockedFrame, uint8_t *buffer, size_t *bufferLength);

typedef struct STREAM_DATA_BLOCKED_FRAME{
    uint8_t type;// STREAM_DATA_BLOCKED;
    int streamId;
    int dataLimit;
    }STREAM_DATA_BLOCKED_FRAME;
bool encodeSTREAM_DATA_BLOCKED_FRAME(STREAM_DATA_BLOCKED_FRAME *streamDataBlockedFrame, uint8_t *buffer, size_t *bufferLength);
bool decodeSTREAM_DATA_BLOCKED_FRAME(STREAM_DATA_BLOCKED_FRAME *streamDataBlockedFrame, uint8_t *buffer, size_t *bufferLength);

typedef struct STREAMS_BLOCKED_BIDI_FRAME{
    uint8_t type;// STREAMS_BLOCKED_BIDI;
    int streamLimit;
    }STREAMS_BLOCKED_BIDI_FRAME;
bool encodeSTREAMS_BLOCKED_BIDI_FRAME(STREAMS_BLOCKED_BIDI_FRAME *streamsBlockedBidiFrame, uint8_t *buffer, size_t *bufferLength);
bool decodeSTREAMS_BLOCKED_BIDI_FRAME(STREAMS_BLOCKED_BIDI_FRAME *streamsBlockedBidiFrame, uint8_t *buffer, size_t *bufferLength);

typedef struct STREAMS_BLOCKED_UNI_FRAME{
    uint8_t type;// STREAMS_BLOCKED_UNI;
    int streamLimit;
    }STREAMS_BLOCKED_UNI_FRAME;
bool encodeSTREAMS_BLOCKED_UNI_FRAME(STREAMS_BLOCKED_UNI_FRAME *streamsBlockedUniFrame, uint8_t *buffer, size_t *bufferLength);
bool decodeSTREAMS_BLOCKED_UNI_FRAME(STREAMS_BLOCKED_UNI_FRAME *streamsBlockedUniFrame, uint8_t *buffer, size_t *bufferLength);

typedef struct NEW_CONNECTION_ID_FRAME{
    uint8_t type;// NEW_CONNECTION_ID;
    int sequenceNumber;
    int connectionId;
    int statelessResetToken;
    }NEW_CONNECTION_ID_FRAME;
bool encodeNEW_CONNECTION_ID_FRAME(NEW_CONNECTION_ID_FRAME *newConnectionIdFrame, uint8_t *buffer, size_t *bufferLength);
bool decodeNEW_CONNECTION_ID_FRAME(NEW_CONNECTION_ID_FRAME *newConnectionIdFrame, uint8_t *buffer, size_t *bufferLength);

typedef struct RETIRE_CONNECTION_ID_FRAME{
    uint8_t type;// RETIRE_CONNECTION_ID;
    int sequenceNumber;
    }RETIRE_CONNECTION_ID_FRAME;
bool encodeRETIRE_CONNECTION_ID_FRAME(RETIRE_CONNECTION_ID_FRAME *retireConnectionIdFrame, uint8_t *buffer, size_t *bufferLength);
bool decodeRETIRE_CONNECTION_ID_FRAME(RETIRE_CONNECTION_ID_FRAME *retireConnectionIdFrame, uint8_t *buffer, size_t *bufferLength);

typedef struct PATH_CHALLENGE_FRAME{    
    uint8_t type;// PATH_CHALLENGE;
    int data;
    }PATH_CHALLENGE_FRAME;
bool encodePATH_CHALLENGE_FRAME(PATH_CHALLENGE_FRAME *pathChallengeFrame, uint8_t *buffer, size_t *bufferLength);
bool decodePATH_CHALLENGE_FRAME(PATH_CHALLENGE_FRAME *pathChallengeFrame, uint8_t *buffer, size_t *bufferLength);

typedef struct PATH_RESPONSE_FRAME{
    uint8_t type;// PATH_RESPONSE;
    int data;
    }PATH_RESPONSE_FRAME;
bool encodePATH_RESPONSE_FRAME(PATH_RESPONSE_FRAME *pathResponseFrame, uint8_t *buffer, size_t *bufferLength);
bool decodePATH_RESPONSE_FRAME(PATH_RESPONSE_FRAME *pathResponseFrame, uint8_t *buffer, size_t *bufferLength);

typedef struct CONNECTION_CLOSE_FRAME{
    uint8_t type;// CONNECTION_CLOSE;
    int errorCode;
    int frameType;
    int reasonPhrase;
    }CONNECTION_CLOSE_FRAME;
bool encodeCONNECTION_CLOSE_FRAME(CONNECTION_CLOSE_FRAME *connectionCloseFrame, uint8_t *buffer, size_t *bufferLength);
bool decodeCONNECTION_CLOSE_FRAME(CONNECTION_CLOSE_FRAME *connectionCloseFrame, uint8_t *buffer, size_t *bufferLength);

typedef struct APPLICATION_CLOSE_FRAME{
    uint8_t type;// APPLICATION_CLOSE;
    int errorCode;
    int frameType;
    int reasonPhrase;
    }APPLICATION_CLOSE_FRAME;
bool encodeAPPLICATION_CLOSE_FRAME(APPLICATION_CLOSE_FRAME *applicationCloseFrame, uint8_t *buffer, size_t *bufferLength);
bool decodeAPPLICATION_CLOSE_FRAME(APPLICATION_CLOSE_FRAME *applicationCloseFrame, uint8_t *buffer, size_t *bufferLength);

typedef struct HANDSHAKE_DONE_FRAME{
    uint8_t type;// HANDSHAKE_DONE;
    }HANDSHAKE_DONE_FRAME;
bool encodeHANDSHAKE_DONE_FRAME(HANDSHAKE_DONE_FRAME *handshakeDoneFrame, uint8_t *buffer, size_t *bufferLength);
bool decodeHANDSHAKE_DONE_FRAME(HANDSHAKE_DONE_FRAME *handshakeDoneFrame, uint8_t *buffer, size_t *bufferLength);


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

