

typedef struct {
    uint16_t ProtocolVersion;
    uint8_t Random[32];
    uint8_t CipherSuite[2];
    uint8_t CompressionMethod;
} ServerHello;