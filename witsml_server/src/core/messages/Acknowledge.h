#ifndef ACKNOWLEDGE_H
#define ACKNOWLEDGE_H

#include "Message.h"

namespace Core
{
class Acknowledge:public Message
{
public:
    Acknowledge();
    const int messageType_ {1001};
};
}

#endif // ACKNOWLEDGE_H
