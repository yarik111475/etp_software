#ifndef MESSAGEFACTORY_H
#define MESSAGEFACTORY_H

#include <QJsonObject>
#include <QSharedPointer>
#include "core/messages/Message.h"

namespace Core
{
class Message;

class MessageFactory
{
public:
    MessageFactory()=default;
    ~MessageFactory()=default;

    MessageFactory(const MessageFactory& other)=delete;
    MessageFactory& operator=(const MessageFactory& other)=delete;

    static QSharedPointer<Message> create(Message::Type type, const QJsonObject& params);
};
}


#endif // MESSAGEFACTORY_H
