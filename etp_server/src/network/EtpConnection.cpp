#include "EtpConnection.h"

#include <QTimer>
#include <QtWebSockets>

void EtpConnection::operate_message(const QString &message)
{

}

EtpConnection::EtpConnection(QWebSocket *websocket_ptr, std::shared_ptr<spdlog::logger> logger_ptr, QObject *parent)
    : QObject(parent),websocket_ptr_{QSharedPointer<QWebSocket>(std::move(websocket_ptr))},logger_ptr_{logger_ptr},client_uid_{QUuid::createUuid()}
{
    //make signal/slot connections for socket
    QObject::connect(websocket_ptr_.get(),&QWebSocket::disconnected,
                     this,&EtpConnection::slot_disconnected);
    QObject::connect(websocket_ptr_.get(),&QWebSocket::pong,
                     this,&EtpConnection::slot_pong);
    QObject::connect(websocket_ptr_.get(),&QWebSocket::textMessageReceived,
                     this,&EtpConnection::slot_text_message_received);

    //create ping timer
    pingtimer_ptr_.reset(new QTimer);
    pingtimer_ptr_->setInterval(ping_interval_);

    //make signal/slot connections for ping timer
    QObject::connect(pingtimer_ptr_.get(),&QTimer::timeout,
                     this,&EtpConnection::slot_pingtimeout);
}

void EtpConnection::run()
{
    //start ping timer
    pingtimer_ptr_->start();

    //start message queue
    while(flag_){
        std::unique_lock<std::mutex> lock(mtx_);
        cv_.wait(lock, [this]{
            return !message_queue_.empty();
        });

        //get current message from queue and unlock
        const QString& message {message_queue_.dequeue()};
        lock.unlock();

        //check if flag_ is set (for quit if socket disconnected)
        if(!flag_ || !message.isEmpty()){
            return;
        }

        //operate message
        operate_message(message);
    }
}

void EtpConnection::slot_pingtimeout()
{
    websocket_ptr_->ping("payload");
}

void EtpConnection::slot_pong(quint64 elapsedTime, const QByteArray &payload)
{
    Q_UNUSED(elapsedTime)
    Q_UNUSED(payload)
}

void EtpConnection::slot_text_message_received(const QString &message)
{
    std::lock_guard<std::mutex> lock(mtx_);
    message_queue_.enqueue(message);
    cv_.notify_one();
}

void EtpConnection::slot_disconnected()
{
    flag_=false;
    message_queue_.enqueue(QString{});
    cv_.notify_one();
}
