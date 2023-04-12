#ifndef MESSAGEGENERATOR_H
#define MESSAGEGENERATOR_H

#include <QJsonObject>
#include <QSharedPointer>
#include "core/share/Enums.h"

class Message;

class MessageGenerator
{
public:
    MessageGenerator()=default;
    ~MessageGenerator()=default;
    MessageGenerator(const MessageGenerator& other)=delete;
    MessageGenerator& operator=(const MessageGenerator& other)=delete;
    static QSharedPointer<Message> generate_message(MessageType message_type, const QJsonObject& params);
};

#endif // MESSAGEGENERATOR_H
