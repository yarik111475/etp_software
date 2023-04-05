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

QSharedPointer<Core::Message> Core::MessageFactory::create(int type, const QJsonObject &params)
{
    switch(type){
    case 1:
        return QSharedPointer<Message>(new RequestSession);
    case 2:
        return QSharedPointer<Message>(new OpenSession);
    case 5:
        return QSharedPointer<Message>(new CloseSession);
    case 6:
        return QSharedPointer<Message>(new Authorize);
    case 7:
        return QSharedPointer<Message>(new AuthorizeResponse);
    case 8:
        return QSharedPointer<Message>(new Ping);
    case 9:
        return QSharedPointer<Message>(new Pong);
    case 1000:
        return QSharedPointer<Message>(new ProtocolException);
    case 1001:
        return QSharedPointer<Message>(new Acknowledge);
    default:
        return nullptr;
    }
    return nullptr;
}
