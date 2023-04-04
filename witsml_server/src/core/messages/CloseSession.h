#ifndef CLOSESESSION_H
#define CLOSESESSION_H

#include <QString>
#include "Message.h"

namespace Core
{
class CloseSession:public Message
{
public:
    CloseSession();
    const int messageType_ {5};
    QString reason_ {};
};
}

#endif // CLOSESESSION_H
