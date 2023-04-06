#ifndef MESSAGE_H
#define MESSAGE_H

#include <QString>

class Message
{
private:
    int messageType_ {};
public:
    //message type
    enum Type{
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
    enum Format{
        XML,
        JSON
    };

    Message();
    virtual ~Message()=default;
    virtual Type messageType()=0;
    virtual QString to_xml()=0;
    virtual QString to_json()=0;
};

#endif // MESSAGE_H
