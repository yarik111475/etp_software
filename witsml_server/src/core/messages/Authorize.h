#ifndef AUTHORIZE_H
#define AUTHORIZE_H

#include <QString>
#include "Message.h"

namespace Core
{
class Authorize:public Message
{
public:
    Authorize()=default;
    virtual ~Authorize()=default;
    virtual Type messageType()override;

    QString authorization_ {};
    QString supplementalAuthorization_ {};
};
}

#endif // AUTHORIZE_H
