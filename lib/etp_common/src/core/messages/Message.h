#ifndef MESSAGE_H
#define MESSAGE_H

#include <QString>
#include <QJsonObject>

class Message
{
protected:
    QJsonObject params_;

public:
    explicit Message(const QJsonObject& params);
    virtual ~Message()=default;
    virtual QString to_xml()=0;
    virtual QString to_json()=0;
};

#endif // MESSAGE_H
