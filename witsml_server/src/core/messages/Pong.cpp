#include "Pong.h"

Core::Message::Type Core::Pong::messageType()
{
    return Message::PONG;
}
