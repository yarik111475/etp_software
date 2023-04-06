#include "EtpClient.h"

#include <QUrl>
#include <QTimer>
#include <QWebSocket>
#include <QHostAddress>
#include "spdlog/spdlog.h"

#include "core/messages/Message.h"
#include "core/messages/OpenSession.h"
#include "core/messages/CloseSession.h"
#include "core/factories/MessageFactory.h"

void EtpClient::slot_connected()
{

}

void EtpClient::slot_disconnected()
{

}

void EtpClient::slot_text_message_received(const QString &message)
{

}

void EtpClient::slot_pong(quint64 elapsedTime, const QByteArray &payload)
{

}

EtpClient::EtpClient(std::shared_ptr<spdlog::logger> logger_ptr, QObject *parent)
    : QObject(parent),logger_ptr_{logger_ptr}
{
    QObject::connect(socket_ptr_.get(),&QWebSocket::pong,
                     this,&EtpClient::slot_pong);

    socket_ptr_.reset(new QWebSocket);
    QObject::connect(socket_ptr_.get(),&QWebSocket::connected,
                     this,&EtpClient::slot_connected);

    QObject::connect(socket_ptr_.get(),&QWebSocket::disconnected,
                     this,&EtpClient::slot_disconnected);

    QObject::connect(socket_ptr_.get(),&QWebSocket::textMessageReceived,
                     this,&EtpClient::slot_text_message_received);

}

void EtpClient::begin_session(const QString& host, int port)
{
    QUrl url {QString("%1://%2").arg(ws_prefix,host)};
    url.setPort(port);
    socket_ptr_->open(url);
    QTimer::singleShot(1000 * 5,[this](){
        if(socket_ptr_->state()!=QAbstractSocket::ConnectedState){
            socket_ptr_->close();
            socket_ptr_.reset();
            //TODO log connection error here and send signal
            return;
        }
    });

}

void EtpClient::end_session()
{

}
