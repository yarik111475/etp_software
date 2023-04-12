#include "MessageGenerator.h"

#include "core/messages/Ping.h"
#include "core/messages/Pong.h"
#include "core/messages/Authorize.h"
#include "core/messages/Acknowledge.h"
#include "core/messages/OpenSession.h"
#include "core/messages/CloseSession.h"
#include "core/messages/RequestSession.h"
#include "core/messages/ProtocolException.h"
#include "core/messages/AuthorizeResponse.h"

QSharedPointer<Message> MessageGenerator::generate_message(MessageType message_type, const QJsonObject &params)
{
    switch(message_type){
    case REQUEST_SESSION:
        return QSharedPointer<Message>(new RequestSession(params));
    case OPEN_SESSION:
        return QSharedPointer<Message>(new OpenSession(params));
    case CLOSE_SESSION:
        return QSharedPointer<Message>(new CloseSession(params));
    case AUTHORIZE:
        return QSharedPointer<Message>(new Authorize(params));
    case AUTHORISE_RESPONSE:
        return QSharedPointer<Message>(new AuthorizeResponse(params));
    case PING:
        return QSharedPointer<Message>(new Ping(params));
    case PONG:
        return QSharedPointer<Message>(new Pong(params));
    case PROTOCOL_EXCEPTION:
        return QSharedPointer<Message>(new ProtocolException(params));
    case ACKNOWLEDGE:
        return QSharedPointer<Message>(new Acknowledge(params));
    }
    return nullptr;
}
