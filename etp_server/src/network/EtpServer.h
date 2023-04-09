#ifndef HTTPSERVER_H
#define HTTPSERVER_H

#include <map>
#include <memory>
#include <QUuid>
#include <QObject>
#include <QSharedPointer>

class QString;
class QHostAddress;
class QWebSocketServer;

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
    explicit EtpServer(const QString& host, int port, std::shared_ptr<spdlog::logger> logger_ptr, QObject* parent=nullptr);
    virtual ~EtpServer()=default;
    bool start_listen();
    void stop_listen();


private slots:
    void slot_new_connection();
};

#endif // HTTPSERVER_H
