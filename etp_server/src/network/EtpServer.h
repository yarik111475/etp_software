#ifndef HTTPSERVER_H
#define HTTPSERVER_H

#include <map>
#include <memory>
#include <QUuid>
#include <QObject>
#include <QSharedPointer>
#include <QWebSocketServer>

class QString;
class QHostAddress;

namespace spdlog{
    class logger;
}

class EtpServer:public QObject
{
    Q_OBJECT
private:
    QUuid server_uid_ {};
    QString host_ {};
    int port_ {};
    QString error_str_ {};
    QSharedPointer<QWebSocketServer> webserver_ptr_ {nullptr};
    std::shared_ptr<spdlog::logger> logger_ptr_ {nullptr};

public:
    explicit EtpServer(std::shared_ptr<spdlog::logger> logger_ptr, QObject* parent=nullptr);
    virtual ~EtpServer()=default;

    void init(const QString& host, int port);
    bool start_listen();
    void stop_listen();

    inline QString err_str()const{
        return error_str_;
    }
    inline bool is_listening()const{
        return (webserver_ptr_ && webserver_ptr_->isListening());
    }


private slots:
    void slot_new_connection();

signals:
    void signal_client_connected(const QString& client_uid);
    void signal_client_disconnected(const QString& client_uid);
};

#endif // HTTPSERVER_H
