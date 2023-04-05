#include "AuthorizeResponse.h"

Core::Message::Type Core::AuthorizeResponse::messageType()
{
    return Message::AUTHORISE_RESPONSE;
}
