#ifndef PROTOCOLEXCEPTION_H
#define PROTOCOLEXCEPTION_H

#include <QMap>
#include <QString>
#include <QVariant>

namespace Core
{
class ProtocolException
{
public:
    ProtocolException();
    const int messageType_ {1000};

    //TODO correct type later
    QVariant error_ {};

    //TODO correct K, V later
    QMap<QString,QVariant> errors_ {};
};
}

#endif // PROTOCOLEXCEPTION_H