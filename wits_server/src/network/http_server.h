#ifndef HTTPSERVER_H
#define HTTPSERVER_H

#include <map>
#include <memory>
#include <QTcpServer>

class QString;
class QTcpServer;
class QTcpSocket;
class QHostAddress;

namespace Gphm
{
class HttpServer:public QTcpServer
{
    Q_OBJECT
private:
    std::map<qintptr,std::shared_ptr<QTcpSocket>> socket_map_ ;

public:
    explicit HttpServer(QObject* parent=nullptr);
    virtual ~HttpServer()=default;

protected:
    virtual void incomingConnection(qintptr socketDescriptor);

private slots:
    void slot_ready_read();
    void slot_disconnected();
};
}


#endif // HTTPSERVER_H
