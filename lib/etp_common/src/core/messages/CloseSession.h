#ifndef CLOSESESSION_H
#define CLOSESESSION_H

#include <QString>
#include "Message.h"

class CloseSession:public Message
{
public:
    CloseSession()=default;
    virtual ~CloseSession()=default;
    virtual Type messageType()override;
    virtual QString to_xml()override;
    virtual QString to_json()override;

    QString reason_ {};
};

#endif // CLOSESESSION_H
