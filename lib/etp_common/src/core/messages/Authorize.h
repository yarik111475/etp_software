#ifndef AUTHORIZE_H
#define AUTHORIZE_H

#include <QString>
#include "Message.h"

class Authorize:public Message
{
public:
    Authorize()=default;
    virtual ~Authorize()=default;
    virtual Type messageType()override;
    virtual QString to_xml()override;
    virtual QString to_json()override;

    QString authorization_ {};
    QString supplementalAuthorization_ {};
};

#endif // AUTHORIZE_H
