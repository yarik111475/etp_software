#ifndef PROTOCOLEXCEPTION_H
#define PROTOCOLEXCEPTION_H

#include <map>
#include <QMap>
#include <QString>
#include <QVariant>
#include "Message.h"

class ProtocolException:public Message
{
public:
    explicit ProtocolException(const QJsonObject& params);
    virtual ~ProtocolException()=default;
    virtual QString to_xml()override;
    virtual QString to_json()override;

    //base part
    const QString type_ {"record"};
    const QString namespace_ {"Energistics.Etp.v12.Protocol.Core"};
    const QString name_ {"ProtocolException"};
    const int protocol_ {0};
    const int messageType_ {1000};
    const QString senderRole_ {"*"};
    const QString protocolRoles_ {"client, server"};
    const bool multipartFlag_ {true};

    //fields []
    //TODO correct type later
    QVariant error_ {};

    //TODO correct K, V later
    std::map<QString,QVariant> errors_ {};
};

#endif // PROTOCOLEXCEPTION_H
