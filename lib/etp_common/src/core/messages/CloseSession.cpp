#include "CloseSession.h"

Message::Type CloseSession::messageType()
{
    return Message::CLOSE_SESSION;
}

QString CloseSession::to_xml()
{

}

QString CloseSession::to_json()
{

}
