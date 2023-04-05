#include "MessageFactory.h"

#include "core/messages/Ping.h"
#include "core/messages/Pong.h"
#include "core/messages/Authorize.h"
#include "core/messages/Acknowledge.h"
#include "core/messages/OpenSession.h"
#include "core/messages/CloseSession.h"
#include "core/messages/RequestSession.h"
#include "core/messages/AuthorizeResponse.h"
#include "core/messages/ProtocolException.h"

QSharedPointer<Core::Message> Core::MessageFactory::create(Message::Type type, const QJsonObject &params)
{
    switch(type){
    case Message::REQUEST_SESSION:
        return QSharedPointer<Message>(new RequestSession);
    case Message::OPEN_SESSION:
        return QSharedPointer<Message>(new OpenSession);
    case Message::CLOSE_SESSION:
        return QSharedPointer<Message>(new CloseSession);
    case Message::AUTHORIZE:
        return QSharedPointer<Message>(new Authorize);
    case Message::AUTHORISE_RESPONSE:
        return QSharedPointer<Message>(new AuthorizeResponse);
    case Message::PING:
        return QSharedPointer<Message>(new Ping);
    case Message::PONG:
        return QSharedPointer<Message>(new Pong);
    case Message::PROTOCOL_EXCEPTION:
        return QSharedPointer<Message>(new ProtocolException);
    case Message::ACKNOWLEDGE:
        return QSharedPointer<Message>(new Acknowledge);
    default:
        return nullptr;
    }
    return nullptr;
}
