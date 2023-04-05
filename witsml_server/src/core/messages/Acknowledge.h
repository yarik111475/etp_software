#ifndef ACKNOWLEDGE_H
#define ACKNOWLEDGE_H

#include "Message.h"

namespace Core
{
class Acknowledge:public Message
{
public:
    Acknowledge()=default;
    virtual ~Acknowledge()=default;
    virtual Type messageType()override;
};
}

#endif // ACKNOWLEDGE_H
