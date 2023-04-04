#ifndef PING_H
#define PING_H

#include "Message.h"

namespace Core
{
class Ping:public Message
{
public:
    Ping();
    const int messageType_ {8};
    long currentDateTime_ {};
};
}

#endif // PING_H
