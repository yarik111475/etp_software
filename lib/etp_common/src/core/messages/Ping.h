#ifndef PING_H
#define PING_H

#include "Message.h"

class Ping:public Message
{
public:
    explicit Ping(const QJsonObject& params);
    virtual ~Ping()=default;
    virtual QString to_xml()override;
    virtual QString to_json()override;

    //base part
    const QString type_ {"record"};
    const QString namespace_ {"Energistics.Etp.v12.Protocol.Core"};
    const QString name_ {"Ping"};
    const int protocol_ {0};
    const int messageType_ {8};
    const QString senderRole_ {"client,server"};
    const QString protocolRoles_ {"client, server"};
    const bool multipartFlag_ {false};

    //fields []
    long currentDateTime_ {};
};

#endif // PING_H
