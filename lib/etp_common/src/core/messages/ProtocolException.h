#ifndef PROTOCOLEXCEPTION_H
#define PROTOCOLEXCEPTION_H

#include <QMap>
#include <QString>
#include <QVariant>
#include "Message.h"

class ProtocolException:public Message
{
public:
    ProtocolException()=default;
    virtual ~ProtocolException()=default;
    virtual Type messageType()override;
    virtual QString to_xml()override;
    virtual QString to_json()override;

    //TODO correct type later
    QVariant error_ {};

    //TODO correct K, V later
    QMap<QString,QVariant> errors_ {};
};

#endif // PROTOCOLEXCEPTION_H
