#ifndef ACKNOWLEDGE_H
#define ACKNOWLEDGE_H

#include "Message.h"

class Acknowledge:public Message
{
public:
    Acknowledge()=default;
    virtual ~Acknowledge()=default;
    virtual QString to_xml()override;
    virtual QString to_json()override;

    //base part
    const QString type_ {"record"};
    const QString namespace_ {"Energistics.Etp.v12.Protocol.Core"};
    const QString name_ {"Acknowledge"};
    const int protocol_ {0};
    const int messageType_ {1001};
    const QString senderRole_ {"*"};
    const QString protocolRoles_ {"client, server"};
    const bool multipartFlag_ {false};

    //fields []
};

#endif // ACKNOWLEDGE_H
