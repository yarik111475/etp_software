#ifndef PONG_H
#define PONG_H

#include "Message.h"

class Pong:public Message
{
public:
    Pong()=default;
    virtual ~Pong()=default;
    virtual Type messageType()override;
    virtual QString to_xml()override;
    virtual QString to_json()override;

    long currentDateTime_ {};
};

#endif // PONG_H
