#ifndef CLOSESESSION_H
#define CLOSESESSION_H

#include <QString>

namespace Core
{
class CloseSession
{
public:
    CloseSession();
    const int messageType_ {5};
    QString reason_ {};
};
}

#endif // CLOSESESSION_H
