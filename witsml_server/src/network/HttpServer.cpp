#include "HttpServer.h"

#include <iostream>
#include <QTcpServer>
#include <QTcpSocket>
#include <QHostAddress>

HttpServer::HttpServer(const QString &host, int port, QObject *parent)
    :QObject{parent},host_{host},port_{port}
{
    tcp_server_ptr_.reset(new QTcpServer(this));
    QObject::connect(tcp_server_ptr_.get(), &QTcpServer::newConnection,
                     this, &HttpServer::slot_new_connection);
}

bool HttpServer::start_listen()
{
    const bool& ok {tcp_server_ptr_->listen(QHostAddress(host_),port_)};
    if(!ok){
        error_str_=tcp_server_ptr_->errorString();
        tcp_server_ptr_.reset();
    }
    return ok;
}

void HttpServer::slot_ready_read()
{
    QTcpSocket* socket_ptr {static_cast<QTcpSocket*>(sender())};
    if(socket_ptr){


        const QString& request {socket_ptr->readAll()};
        std::cout<<request.toStdString()<<std::endl;
        const QString& response {"HTTP/1.1 200 OK\r\n\r\n"};
        socket_ptr->write(response.toUtf8());
        socket_ptr->disconnectFromHost();
    }
}


void HttpServer::slot_disconnected()
{
    QTcpSocket* socket_ptr {static_cast<QTcpSocket*>(sender())};
    if(socket_ptr){
        const qintptr& descriptor {socket_ptr->socketDescriptor()};
        const auto& found {socket_map_.find(descriptor)};
        if(found!=socket_map_.end()){
            socket_map_.erase(found);
        }
        socket_ptr->close();
        socket_ptr->deleteLater();
        std::cout<<"socket disconnected\n";
    }
}

void HttpServer::slot_new_connection()
{
    QTcpSocket* socket_ptr {tcp_server_ptr_->nextPendingConnection()};
    const qintptr& descriptor {socket_ptr->socketDescriptor()};

    QObject::connect(socket_ptr,&QTcpSocket::readyRead,
                     this,&HttpServer::slot_ready_read);
    QObject::connect(socket_ptr,&QTcpSocket::disconnected,
                     this,&HttpServer::slot_disconnected);
    socket_map_.emplace(descriptor,socket_ptr);

}
