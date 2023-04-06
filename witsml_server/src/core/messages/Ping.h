#ifndef PING_H
#define PING_H

#include "Message.h"

namespace Core
{
class Ping:public Message
{
public:
    Ping()=default;
    virtual ~Ping()=default;
    virtual Type messageType()override;

    long currentDateTime_ {};
};
}

#endif // PING_H
