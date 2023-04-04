#ifndef PONG_H
#define PONG_H

#include "Message.h"

namespace Core
{
class Pong:public Message
{
public:
    Pong();
    const int messageType_ {9};
    long currentDateTime_ {};
};
}

#endif // PONG_H
