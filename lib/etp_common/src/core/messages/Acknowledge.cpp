#include "Acknowledge.h"

#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

Acknowledge::Acknowledge(const QJsonObject &params)
    :Message{params}
{

}

QString Acknowledge::to_xml()
{

}

QString Acknowledge::to_json()
{
    //base part
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

    //message part
    QJsonArray fields {};

    //insert message part into base part
    json_object.insert("fields", fields);
    return QJsonDocument(json_object).toJson();
}
