#ifndef AUTHORIZERESPONSE_H
#define AUTHORIZERESPONSE_H

#include <QVector>
#include <QString>
#include "Message.h"

namespace Core
{
class AuthorizeResponse:public Message
{
public:
    AuthorizeResponse()=default;
    virtual ~AuthorizeResponse()=default;
    virtual int messageType()override;

    bool success_ {};
    QVector<QString> challenges_ {};
};
}

#endif // AUTHORIZERESPONSE_H
