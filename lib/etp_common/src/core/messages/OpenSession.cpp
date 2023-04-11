#include "OpenSession.h"

#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

QString OpenSession::to_xml()
{

}

QString OpenSession::to_json()
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
