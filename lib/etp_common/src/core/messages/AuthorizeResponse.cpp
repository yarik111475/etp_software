#include "AuthorizeResponse.h"

Message::Type AuthorizeResponse::messageType()
{
    return Message::AUTHORISE_RESPONSE;
}

QString AuthorizeResponse::to_xml()
{

}

QString AuthorizeResponse::to_json()
{

}
