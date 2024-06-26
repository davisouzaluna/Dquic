
#include <stdint.h>

typedef enum{
    server_name = 0,
    max_fragment_length = 1,
    status_request = 5,
    supported_groups = 10,
    signature_algorithms = 13,
    use_srtp = 14,
    heartbeat = 15,
    application_layer_protocol_negotiation = 16,
    signed_certificate_timestamp = 18,
    client_certificate_type = 19,
    server_certificate_type = 20,
    padding = 21,
    pre_shared_key = 41,
    early_data = 42,
    supported_versions = 43,
    cookie = 44,
    psk_key_exchange_modes = 45,
    certificate_authorities = 47,
    oid_filters = 48,
    post_handshake_auth = 49,
    signature_algorithms_cert = 50,
    key_share = 51,
    extension_type_max = 65535
} ExtensionType;

typedef struct {
    ExtensionType extension_type;
    uint8_t extension_data[65535] // Variable length, depending on extension_type. Max length is 65535
} Extension;


typedef enum {
    host_name = 0,
    reserved = 255
} NameType;

typedef struct {
    uint16_t length;
    uint8_t data[];
} HostName;

typedef struct {
    NameType name_type;
    union {
        HostName host_name;
    } name;
} ServerName;

typedef struct {
    uint16_t length;
    ServerName items[];
} ServerNameList;

typedef enum {
    mfl_512 = 1,
    mfl_1024 = 2,
    mfl_2048 = 3,
    mfl_4096 = 4,
    reserved = 255
} MaxFragmentLength;

