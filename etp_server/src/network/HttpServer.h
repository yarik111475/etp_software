#ifndef HTTPSERVER_H
#define HTTPSERVER_H

#include <map>
#include <memory>
#include <QObject>
#include <QSharedPointer>

class QString;
class QTcpServer;
class QTcpSocket;
class QHostAddress;

class HttpServer:public QObject
{
    Q_OBJECT
private:
    QString host_ {};
    int port_ {};
    QString error_str_ {};
    QSharedPointer<QTcpServer> tcp_server_ptr_ {nullptr};
    std::map<qintptr,QTcpSocket*> socket_map_ {};

public:
    explicit HttpServer(const QString& host, int port,QObject* parent=nullptr);
    virtual ~HttpServer()=default;
    bool start_listen();
    void stop_listen();


private slots:
    void slot_ready_read();
    void slot_disconnected();
    void slot_new_connection();
};

#endif // HTTPSERVER_H
