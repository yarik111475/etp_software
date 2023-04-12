#ifndef AUTHORIZE_H
#define AUTHORIZE_H

#include <map>
#include <QString>
#include <QVariant>
#include "Message.h"

class Authorize:public Message
{
public:
    explicit Authorize(const QJsonObject& params);
    virtual ~Authorize()=default;
    virtual QString to_xml()override;
    virtual QString to_json()override;

    //base part
    const QString type_ {"record"};
    const QString namespace_ {"Energistics.Etp.v12.Protocol.Core"};
    const QString name_ {"Authorize"};
    const int protocol_ {0};
    const int messageType_ {6};
    const QString senderRole_ {"client,server"};
    const QString protocolRoles_ {"client, server"};
    const bool multipartFlag_ {false};

    //fields []
    QString authorization_ {};
    std::map<QString,QVariant> supplementalAuthorization_ {};
};

#endif // AUTHORIZE_H
