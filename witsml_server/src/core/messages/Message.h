#ifndef MESSAGE_H
#define MESSAGE_H

namespace Core
{
class Message
{
private:
    int messageType_ {};
public:
    Message();
    virtual ~Message()=default;
    virtual int messageType()=0;
};
}


#endif // MESSAGE_H
