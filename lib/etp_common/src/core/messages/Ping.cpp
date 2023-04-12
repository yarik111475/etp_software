#include "Ping.h"

#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

Ping::Ping(const QJsonObject &params)
    :Message{params}
{

}

QString Ping::to_xml()
{

}

QString Ping::to_json()
{
    QJsonObject json_object {
        {"type", type_},
        {"namespace",namespace_},
        {"name", name_},
        {"protocol", protocol_},
        {"messageType", messageType_},
        {"senderRole", senderRole_},
        {"protocolRoles", protocolRoles_},
        {"multipartFlag", multipartFlag_}
    };
    return QJsonDocument(json_object).toJson();
}
