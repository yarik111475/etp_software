#ifndef REQUESTSESSION_H
#define REQUESTSESSION_H

#include <QMap>
#include <QUuid>
#include <QString>
#include <QVector>
#include <QVariant>

namespace Core
{
class RequestSession
{
public:
    RequestSession();
    const int messageType_ {1};
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
}

#endif // REQUESTSESSION_H
