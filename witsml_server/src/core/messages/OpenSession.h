#ifndef OPENSESSION_H
#define OPENSESSION_H

#include <QMap>
#include <QUuid>
#include <QString>
#include <QVector>
#include <QVariant>
#include "Message.h"

namespace Core
{
class OpenSession:public Message
{
public:
    OpenSession()=default;
    virtual ~OpenSession()=default;
    virtual Type messageType()override;

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
}

#endif // OPENSESSION_H
