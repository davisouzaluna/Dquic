

#include <stdint.h>
#include <stdio.h>

typedef struct {
    uint16_t ProtocolVersion;
    uint8_t Random[32];
    uint8_t CipherSuite[2];
} HandshakeHeader;

typedef struct {
    uint16_t legacy_version;
    uint8_t random[32];
    uint8_t legacy_session_id[32];
    uint16_t cipher_suites_length;
    uint8_t *cipher_suites; // Variable length, depending on cipher_suites_length
    uint8_t legacy_compression_methods_length;
    uint8_t *legacy_compression_methods; // Variable length, depending on legacy_compression_methods_length
    // You may need to define structs for Extension, depending on your needs
} ClientHello