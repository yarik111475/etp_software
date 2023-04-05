#ifndef CLOSESESSION_H
#define CLOSESESSION_H

#include <QString>
#include "Message.h"

namespace Core
{
class CloseSession:public Message
{
public:
    CloseSession()=default;
    virtual ~CloseSession()=default;
    virtual Type messageType()override;

    QString reason_ {};
};
}

#endif // CLOSESESSION_H
