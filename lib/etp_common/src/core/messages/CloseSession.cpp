#include "CloseSession.h"

#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

CloseSession::CloseSession(const QJsonObject &params)
    :Message{params}
{

}

QString CloseSession::to_xml()
{

}

QString CloseSession::to_json()
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
    QJsonArray fields {
        QJsonObject {{"reason",reason_}}
    };

    //insert message part into base part
    json_object.insert("fields", fields);
    return QJsonDocument(json_object).toJson();
}
