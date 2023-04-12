#ifndef AUTHORIZERESPONSE_H
#define AUTHORIZERESPONSE_H

#include <QVector>
#include <QString>
#include "Message.h"

class AuthorizeResponse:public Message
{
public:
    explicit AuthorizeResponse(const QJsonObject& params);
    virtual ~AuthorizeResponse()=default;
    virtual QString to_xml()override;
    virtual QString to_json()override;

    //base part
    const QString type_ {"record"};
    const QString namespace_ {"Energistics.Etp.v12.Protocol.Core"};
    const QString name_ {"AuthorizeResponse"};
    const int protocol_ {0};
    const int messageType_ {7};
    const QString senderRole_ {"client,server"};
    const QString protocolRoles_ {"client, server"};
    const bool multipartFlag_ {false};

    //fields []
    bool success_ {};
    QVector<QString> challenges_ {};
};

#endif // AUTHORIZERESPONSE_H
