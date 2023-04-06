#include "ProtocolException.h"

Message::Type ProtocolException::messageType()
{
    return Message::PROTOCOL_EXCEPTION;
}

QString ProtocolException::to_xml()
{

}

QString ProtocolException::to_json()
{

}
