#ifndef ETPCONNECTION_H
#define ETPCONNECTION_H

#include <mutex>
#include <memory>
#include <condition_variable>
#include <QUuid>
#include <QQueue>
#include <QObject>
#include <QRunnable>
#include <QSharedPointer>

class QTimer;
class QWebSocket;

namespace spdlog{
    class logger;
}

class EtpConnection : public QObject, public QRunnable
{
    Q_OBJECT
private:
    QUuid client_uid_ ;
    bool flag_ {false};
    const int ping_interval_ {1000 * 5};
    std::mutex mtx_ {};
    std::condition_variable cv_ {};
    QQueue<QString> message_queue_ {};
    QSharedPointer<QTimer> pingtimer_ptr_ {nullptr};
    QSharedPointer<QWebSocket> websocket_ptr_ {nullptr};
    std::shared_ptr<spdlog::logger> logger_ptr_ {nullptr};

    void operate_message(const QString& message);

public:
    explicit EtpConnection(QWebSocket* websocket_ptr, std::shared_ptr<spdlog::logger> logger_ptr, QObject *parent = nullptr);
    virtual ~EtpConnection()=default;
    virtual void run() override;
    inline QString client_uid()const{
        return client_uid_.toString(QUuid::WithoutBraces);
    }

private slots:
    void slot_pingtimeout();
    void slot_pong(quint64 elapsedTime, const QByteArray &payload);
    void slot_text_message_received(const QString &message);
    void slot_disconnected();

signals:
    void signal_disconnected(const QString& client_uid);
};

#endif // ETPCONNECTION_H
