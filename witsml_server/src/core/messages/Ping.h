#ifndef PING_H
#define PING_H

namespace Core
{
class Ping
{
public:
    Ping();
    const int messageType_ {8};
    long currentDateTime_ {};
};
}

#endif // PING_H
