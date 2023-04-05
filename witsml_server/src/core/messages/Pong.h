#ifndef PONG_H
#define PONG_H

#include "Message.h"

namespace Core
{
class Pong:public Message
{
public:
    Pong()=default;
    virtual ~Pong()=default;
    virtual Type messageType()override;

    long currentDateTime_ {};
};
}

#endif // PONG_H
