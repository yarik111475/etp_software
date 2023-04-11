#ifndef CLOSESESSION_H
#define CLOSESESSION_H

#include <QString>
#include "Message.h"

class CloseSession:public Message
{
public:
    CloseSession()=default;
    virtual ~CloseSession()=default;
    virtual QString to_xml()override;
    virtual QString to_json()override;

    //base part
    const QString type_ {"record"};
    const QString namespace_ {"Energistics.Etp.v12.Protocol.Core"};
    const QString name_ {"CloseSession"};
    const int protocol_ {0};
    const int messageType_ {5};
    const QString senderRole_ {"client,server"};
    const QString protocolRoles_ {"client, server"};
    const bool multipartFlag_ {false};

    //fields []
    QString reason_ {};
};

#endif // CLOSESESSION_H
