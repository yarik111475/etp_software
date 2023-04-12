#include "RequestSession.h"

#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

RequestSession::RequestSession(const QJsonObject &params)
    :Message{params}
{

}

QString RequestSession::to_xml()
{

}

QString RequestSession::to_json()
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
        QJsonObject {{"clientInstanceId",clientInstanceId_.toString()}},
        QJsonObject {{"currentDateTime",currentDateTime_}},
        QJsonObject {{"earliestRetainedChangeTime",earliestRetainedChangeTime_}},
        QJsonObject {{"serverAuthorizationRequired",serverAuthorizationRequired_}}
    };

    //insert requestedProtocols
    QJsonArray requested_protocols {};
    std::transform(requestedProtocols_.begin(),requestedProtocols_.end(),std::back_inserter(requested_protocols),[](const QVariant& item){
        return item.toString();
    });
    fields.append(QJsonObject{{"requestedProtocols",requested_protocols}});

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
        return pair.second.toString();
    });
    fields.append(QJsonObject{{"endpointCapabilities",endpoint_capabilities}});

    //insert message part into base part
    json_object.insert("fields", fields);
    return QJsonDocument(json_object).toJson();
}
