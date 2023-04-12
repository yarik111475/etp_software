#ifndef ENUMS_H
#define ENUMS_H

//message type
enum MessageType{
    PING,
    PONG,
    AUTHORIZE,
    ACKNOWLEDGE,
    OPEN_SESSION,
    CLOSE_SESSION,
    REQUEST_SESSION,
    AUTHORISE_RESPONSE,
    PROTOCOL_EXCEPTION
};

//message format
enum MessageFormat{
    XML,
    JSON
};

#endif // ENUMS_H
