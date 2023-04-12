#include "OpenSession.h"

#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

OpenSession::OpenSession(const QJsonObject &params)
    :Message{params}
{

}

QString OpenSession::to_xml()
{

}

QString OpenSession::to_json()
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
        QJsonObject {{"applicationName",applicationName_}},
        QJsonObject {{"applicationVersion",applicationVersion_}},
        QJsonObject {{"serverInstanceId",serverInstanceId_.toString()}},
        QJsonObject {{"currentDateTime",currentDateTime_}},
        QJsonObject {{"earliestRetainedChangeTime",earliestRetainedChangeTime_}},
        QJsonObject {{"sessionId",sessionId_.toString()}}
    };

    //insert supportedProtocols
    QJsonArray supported_protocols {};
    std::transform(supportedProtocols_.begin(),supportedProtocols_.end(),std::back_inserter(supported_protocols),[](const QVariant& item){
        return item.toString();
    });
    fields.append(QJsonObject{{"supportedProtocols",supported_protocols}});

    //insert supportedDataObjects
    QJsonArray supported_dataobjects {};
    std::transform(supportedDataObjects_.begin(),supportedDataObjects_.end(),std::back_inserter(supported_dataobjects),[](const QVariant& item){
        return item.toString();
    });
    fields.append(QJsonObject{{"supportedDataObjects",supported_dataobjects}});

    //insert supportedCompression
    QJsonArray supported_compression {};
    std::transform(supportedCompression_.begin(),supportedCompression_.end(),std::back_inserter(supported_compression),[](const QVariant& item){
        return item.toString();
    });
    fields.append(QJsonObject{{"supportedCompression",supported_compression}});

    //insert supportedFormats
    QJsonArray supported_formats {};
    std::transform(supportedFormats_.begin(),supportedFormats_.end(),std::back_inserter(supported_formats),[](const QVariant& item){
        return item.toString();
    });
    fields.append(QJsonObject{{"supportedFormats",supported_formats}});

    //insert endpointCapabilities
    QJsonArray endpoint_capabilities {};
    std::transform(endpointCapabilities_.begin(),endpointCapabilities_.end(),std::back_inserter(endpoint_capabilities),[](const std::pair<QString,QVariant>& pair){
        return QJsonObject {{pair.first,pair.second.toString()}};
    });
    fields.append(QJsonObject{{"endpointCapabilities",endpoint_capabilities}});

    //insert message part into base part
    json_object.insert("fields", fields);
    return QJsonDocument(json_object).toJson();
}
