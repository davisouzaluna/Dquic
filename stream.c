/*
    Davi Souza de Luna

    Licensed under the MIT License.

    Abstract:
        This file contains the implementation of stream functions.
*/
#include <stdint.h>

enum StreamIDType {
    CLIENT_BIDIRECTIONAL = 0x00,
    SERVER_BIDIRECTIONAL = 0x01,
    CLIENT_UNIDIRECTIONAL = 0x02,
    SERVER_UNIDIRECTIONAL = 0x03

};

/*The streams frames is necessary to implement the comunication logic. The information on how flow state communication occurs is located in section 3.1 and 3.2 of RFC 9000 */


//void createFlow(int streamID)

void handleStreamType(StreamIDType type){

    switch (type) {
        case CLIENT_BIDIRECTIONAL:
        createFlow(static_cast<int>(type));
        default:
            // Caso o tipo não seja reconhecido
            // Trate isso conforme necessário
            break;
    
    }
}

void BidirecionalFlow(){
    
}