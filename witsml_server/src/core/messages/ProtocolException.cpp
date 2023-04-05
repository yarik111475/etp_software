#include "ProtocolException.h"

Core::Message::Type Core::ProtocolException::messageType()
{
    return Message::PROTOCOL_EXCEPTION;
}
