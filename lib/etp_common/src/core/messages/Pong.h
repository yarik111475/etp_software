#ifndef PONG_H
#define PONG_H

#include "Message.h"

class Pong:public Message
{
public:
    explicit Pong(const QJsonObject& params);
    virtual ~Pong()=default;
    virtual QString to_xml()override;
    virtual QString to_json()override;

    //base part
    const QString type_ {"record"};
    const QString namespace_ {"Energistics.Etp.v12.Protocol.Core"};
    const QString name_ {"Pong"};
    const int protocol_ {0};
    const int messageType_ {9};
    const QString senderRole_ {"client,server"};
    const QString protocolRoles_ {"client, server"};
    const bool multipartFlag_ {false};

    //fields []
    long currentDateTime_ {};
};

#endif // PONG_H
