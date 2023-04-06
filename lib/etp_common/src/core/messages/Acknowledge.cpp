#include "Acknowledge.h"

Core::Message::Type Core::Acknowledge::messageType()
{
    return Message::ACKNOWLEDGE;
}
