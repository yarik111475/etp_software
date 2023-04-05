#include "Ping.h"

Core::Message::Type Core::Ping::messageType()
{
    return Message::PING;
}
