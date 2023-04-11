#ifndef REQUESTSESSION_H
#define REQUESTSESSION_H

#include <QMap>
#include <QUuid>
#include <QString>
#include <QVector>
#include <QVariant>
#include "Message.h"

class RequestSession:public Message
{
public:
    RequestSession()=default;
    virtual ~RequestSession()=default;;
    virtual QString to_xml()override;
    virtual QString to_json()override;

    //base part
    const QString type_ {"record"};
    const QString namespace_ {"Energistics.Etp.v12.Protocol.Core"};
    const QString name_ {"RequestSession"};
    const int protocol_ {0};
    const int messageType_ {1};
    const QString senderRole_ {"client"};
    const QString protocolRoles_ {"client, server"};
    const bool multipartFlag_ {false};

    //fields []
    QString applicationName_ {};
    QString applicationVersion_ {};
    //TODO correct later
    QUuid clientInstanceId_ {};

    //TODO correct T later
    QVector<QVariant> requestedProtocols_ {};
    QVector<QVariant> supportedDataObjects_ {};

    QString supportedCompression_ {};
    QStringList supportedFormats_ {};
    long currentDateTime_ {};
    long earliestRetainedChangeTime_ {};

    //TODO corret K, V later
    QMap<QString,QVariant> endpointCapabilities_ {};

    bool serverAuthorizationRequired_ {};
};

#endif // REQUESTSESSION_H
