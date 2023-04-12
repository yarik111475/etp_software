#include "Pong.h"

#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

Pong::Pong(const QJsonObject &params)
    :Message{params}
{

}

QString Pong::to_xml()
{

}

QString Pong::to_json()
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
