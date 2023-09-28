/*
    Davi Souza de Luna

    Licensed under the MIT License.

    Abstract:
        This file contains the header for packet functions.

*/

#ifndef packet_h_included
#define packet_h_included

#include <stdint.h>

struct Header {
    uint8_t formHeader;        // The form header must have 1 bit
    uint8_t fixedBit;          // The fixed bit must have 1 bit.
    uint8_t versionSpecific;   // The form-specific must have 7 bits
    uint32_t *version;         // The version must have 32 bits and initially (before connection it's null)
    uint8_t DConnIDLen;        // The Destination connection length must have 8 bits
    uint16_t DConnID;          // Arbitrary value
    uint16_t OConnIDLen;       // The origin connection length must have 16 bits
    uint8_t OConnID;           // The origin connection ID must have 8 bits
    uint32_t Sversion;         // Supported version
    uint8_t identifyBit;
    uint64_t long_Packet_Type;
    
    union {
        struct {
            uint8_t tokenLength;
            uint8_t *token;
        } initialFields;
        struct {
            uint8_t *RETRY_token;
            uint8_t Retry_Integrity_Tag;
        } retryFields;
    };
};

enum HeaderHandshakeType {
    INITIAL,
    ZERO_RTT,
    HANDSHAKE,
    RETRY,
};

int handlePacket(enum HeaderHandshakeType type);



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

struct NEW_TOKEN_Frame {
    enum QUICFrameType type;
    uint64_t length;
    uint8_t *token;
};

void longHeader(struct Header *header);

void shortHeader(struct Header *header);

void versionNegotiation(struct Header *header);
#endif
