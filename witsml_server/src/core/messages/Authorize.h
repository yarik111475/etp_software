#ifndef AUTHORIZE_H
#define AUTHORIZE_H

#include <QString>

namespace Core
{
class Authorize
{
public:
    Authorize();
    const int messageType_ {6};
    QString authorization_ {};
    QString supplementalAuthorization_ {};
};
}

#endif // AUTHORIZE_H
