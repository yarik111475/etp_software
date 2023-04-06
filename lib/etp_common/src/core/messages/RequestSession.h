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
    virtual ~RequestSession()=default;
    virtual Type messageType()override;
    virtual QString to_xml()override;
    virtual QString to_json()override;

    QString applicationName_ {};
    QString applicationVersion_ {};
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
