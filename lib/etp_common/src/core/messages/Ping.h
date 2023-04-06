#ifndef PING_H
#define PING_H

#include "Message.h"

class Ping:public Message
{
public:
    Ping()=default;
    virtual ~Ping()=default;
    virtual Type messageType()override;
    virtual QString to_xml()override;
    virtual QString to_json()override;

    long currentDateTime_ {};
};

#endif // PING_H
