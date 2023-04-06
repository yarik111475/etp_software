#ifndef ETPCLIENT_H
#define ETPCLIENT_H

#include <memory>
#include <QObject>

class QWebSocket;

namespace spdlog{
    class logger;
}

class EtpClient : public QObject
{
    Q_OBJECT
private:
    const QString ws_prefix {"ws"}; //wss for secure connection
    std::shared_ptr<spdlog::logger> logger_ptr_ {nullptr};
    std::shared_ptr<QWebSocket> socket_ptr_ {nullptr};

private slots:
    void slot_connected();
    void slot_disconnected();
    void slot_text_message_received(const QString& message);
    void slot_pong(quint64 elapsedTime, const QByteArray &payload);

public:
    explicit EtpClient(std::shared_ptr<spdlog::logger> logger_ptr,QObject *parent = nullptr);
    virtual ~EtpClient()=default;

    void begin_session(const QString &host, int port);
    void end_session();

signals:

};

#endif // ETPCLIENT_H
