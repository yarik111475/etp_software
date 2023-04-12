#include "AuthorizeResponse.h"

#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

AuthorizeResponse::AuthorizeResponse(const QJsonObject &params)
    :Message{params}
{

}

QString AuthorizeResponse::to_xml()
{

}

QString AuthorizeResponse::to_json()
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
        QJsonObject {{"success",success_}}
    };

    //insert chalenges
    QJsonArray chalenges {};
    std::transform(challenges_.begin(),challenges_.end(),std::back_inserter(chalenges),[](const QString& item){
        return item;
    });
    fields.append(QJsonObject{{"chalenges",chalenges}});

    //insert message part into base part
    json_object.insert("fields", fields);
    return QJsonDocument(json_object).toJson();
}
