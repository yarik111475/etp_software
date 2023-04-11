#ifndef OPENSESSION_H
#define OPENSESSION_H

#include <QMap>
#include <QUuid>
#include <QString>
#include <QVector>
#include <QVariant>
#include "Message.h"

class OpenSession:public Message
{
public:
    OpenSession()=default;
    virtual ~OpenSession()=default;
    virtual QString to_xml()override;
    virtual QString to_json()override;

    //base part
    const QString type_ {"record"};
    const QString namespace_ {"Energistics.Etp.v12.Protocol.Core"};
    const QString name_ {"OpenSession"};
    const int protocol_ {0};
    const int messageType_ {2};
    const QString senderRole_ {"server"};
    const QString protocolRoles_ {"client, server"};
    const bool multipartFlag_ {false};

    //fields []
    QString applicationName_ {};
    QString applicationVersion_ {};
    QUuid serverInstanceId_ {};

    //TODO correct T later
    QVector<QVariant> supportedProtocols_ {};
    QVector<QVariant> supportedDataObjects_ {};

    QString supportedCompression_ {};
    QStringList supportedFormats_ {};
    long currentDateTime_ {};
    long earliestRetainedChangeTime_ {};
    QUuid sessionId_ {};

    //TODO corret K, V later
    QMap<QString,QVariant> endpointCapabilities_ {};
};

#endif // OPENSESSION_H
