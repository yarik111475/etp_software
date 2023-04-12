#include "ProtocolException.h"

#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

ProtocolException::ProtocolException(const QJsonObject &params)
    :Message{params}
{

}

QString ProtocolException::to_xml()
{

}

QString ProtocolException::to_json()
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
        QJsonObject {{"error",error_.toString()}}
    };

    //insert errors
    QJsonArray errors {};
    std::transform(errors_.begin(),errors_.end(),std::back_inserter(errors),[](const std::pair<QString,QVariant>& pair){
        return QJsonObject {{pair.first,pair.second.toString()}};
    });
    fields.append(QJsonObject{{"errors",errors}});

    //insert message part into base part
    json_object.insert("fields", fields);
    return QJsonDocument(json_object).toJson();
}
