#include "EtpServer.h"
#include "EtpConnection.h"

#include <QThreadPool>
#include <QHostAddress>

EtpServer::EtpServer(std::shared_ptr<spdlog::logger> logger_ptr, QObject *parent)
    :QObject{parent},logger_ptr_{logger_ptr},server_uid_{QUuid::createUuid()}
{
    webserver_ptr_.reset(new QWebSocketServer(server_uid_.toString(),QWebSocketServer::NonSecureMode));
    QObject::connect(webserver_ptr_.get(),&QWebSocketServer::newConnection,
                     this,&EtpServer::slot_new_connection);
}

void EtpServer::init(const QString &host, int port)
{
    host_=host;
    port_=port;
}

bool EtpServer::start_listen()
{
    if(webserver_ptr_ && webserver_ptr_->isListening()){
        error_str_=QObject::tr("Server is listening now...");
        return false;
    }
    const bool& ok {webserver_ptr_->listen(QHostAddress(host_),port_)};
    if(!ok){
        error_str_=webserver_ptr_->errorString();
    }
    return ok;
}

void EtpServer::stop_listen()
{
    if(webserver_ptr_ && webserver_ptr_->isListening()){
        webserver_ptr_->close();
    }
}

void EtpServer::slot_new_connection()
{
    //get incoming websocket
    QWebSocket* websocket_ptr {webserver_ptr_->nextPendingConnection()};

    //create new connection object and move socket into it
    EtpConnection* etpconnection_ptr {new EtpConnection(websocket_ptr,logger_ptr_)};
    etpconnection_ptr->setAutoDelete(false);

    //get new client uid (to use if needed)
    const QString& client_uid {etpconnection_ptr->client_uid()};
    emit signal_client_connected(client_uid);

    //TODO make needed signal/slot connections if needed
    QObject::connect(etpconnection_ptr,&EtpConnection::signal_disconnected,
                     this,&EtpServer::signal_client_disconnected);

    //start connection in new thread
    QThreadPool::globalInstance()->start(etpconnection_ptr);
}
