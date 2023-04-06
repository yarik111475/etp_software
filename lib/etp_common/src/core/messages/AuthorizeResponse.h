#ifndef AUTHORIZERESPONSE_H
#define AUTHORIZERESPONSE_H

#include <QVector>
#include <QString>
#include "Message.h"

class AuthorizeResponse:public Message
{
public:
    AuthorizeResponse()=default;
    virtual ~AuthorizeResponse()=default;
    virtual Type messageType()override;
    virtual QString to_xml()override;
    virtual QString to_json()override;

    bool success_ {};
    QVector<QString> challenges_ {};
};

#endif // AUTHORIZERESPONSE_H
