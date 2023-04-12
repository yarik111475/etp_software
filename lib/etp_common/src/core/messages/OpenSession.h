#ifndef OPENSESSION_H
#define OPENSESSION_H

#include <map>
#include <vector>
#include <QMap>
#include <QUuid>
#include <QString>
#include <QVector>
#include <QVariant>
#include "Message.h"

class OpenSession:public Message
{
public:
    explicit OpenSession(const QJsonObject& params);
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
    //TODO correct later
    QUuid serverInstanceId_ {};

    //TODO correct T later
    std::vector<QVariant> supportedProtocols_ {};
    std::vector<QVariant> supportedDataObjects_ {};

    QString supportedCompression_ {};
    std::vector<QString> supportedFormats_ {};
    int currentDateTime_ {};
    int earliestRetainedChangeTime_ {};
    QUuid sessionId_ {};

    //TODO corret K, V later
    std::map<QString,QVariant> endpointCapabilities_ {};
};

#endif // OPENSESSION_H
