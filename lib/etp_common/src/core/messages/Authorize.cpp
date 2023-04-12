#include "Authorize.h"

#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

Authorize::Authorize(const QJsonObject &params)
    :Message{params}
{

}

QString Authorize::to_xml()
{

}

QString Authorize::to_json()
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

    //message part
    QJsonArray fields {
        QJsonObject {{"authorization",authorization_}}
    };

    //insert supplementalAuthorization
    QJsonArray supplemental_authorization {};
    std::transform(supplementalAuthorization_.begin(),supplementalAuthorization_.end(),std::back_inserter(supplemental_authorization),[](const std::pair<QString,QVariant>& pair){
        return QJsonObject {{pair.first,pair.second.toString()}};
    });
    fields.append(QJsonObject{{"supplementalAuthorization",supplemental_authorization}});

    //insert message part into base part
    json_object.insert("fields", fields);
    return QJsonDocument(json_object).toJson();
}
