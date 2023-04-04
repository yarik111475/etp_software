#include "HttpServer.h"

#include <iostream>
#include <QTcpServer>
#include <QTcpSocket>
#include <QHostAddress>

Gphm::HttpServer::HttpServer(QObject *parent):QTcpServer{parent}
{

}

void Gphm::HttpServer::incomingConnection(qintptr socketDescriptor)
{
    QTcpSocket* socket_ptr {new QTcpSocket()};
    socket_ptr->setSocketDescriptor(socketDescriptor);

    QObject::connect(socket_ptr,&QTcpSocket::readyRead,
                     this,&HttpServer::slot_ready_read);
    QObject::connect(socket_ptr,&QTcpSocket::disconnected,
                     this,&HttpServer::slot_disconnected);
}

void Gphm::HttpServer::slot_ready_read()
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


void Gphm::HttpServer::slot_disconnected()
{
    QTcpSocket* socket_ptr {static_cast<QTcpSocket*>(sender())};
    if(socket_ptr){
        socket_ptr->close();
        socket_ptr->deleteLater();
        std::cout<<"socket disconnected\n";
    }
}
