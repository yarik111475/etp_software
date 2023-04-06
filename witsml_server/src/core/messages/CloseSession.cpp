#include "CloseSession.h"

Core::Message::Type Core::CloseSession::messageType()
{
    return Message::CLOSE_SESSION;
}
