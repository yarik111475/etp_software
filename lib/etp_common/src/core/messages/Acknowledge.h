#ifndef ACKNOWLEDGE_H
#define ACKNOWLEDGE_H

#include "Message.h"

class Acknowledge:public Message
{
public:
    Acknowledge()=default;
    virtual ~Acknowledge()=default;
    virtual Type messageType()override;
    virtual QString to_xml()override;
    virtual QString to_json()override;
};

#endif // ACKNOWLEDGE_H
