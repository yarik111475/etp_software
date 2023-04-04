#ifndef AUTHORIZE_H
#define AUTHORIZE_H

#include <QString>
#include "Message.h"

namespace Core
{
class Authorize:public Message
{
public:
    Authorize();
    const int messageType_ {6};
    QString authorization_ {};
    QString supplementalAuthorization_ {};
};
}

#endif // AUTHORIZE_H
