#include <iostream>
#include <QtGlobal>
#include <QHostAddress>
#include <QSharedPointer>
#include <QCoreApplication>

#if defined(Q_OS_LINUX)
#include <signal.h>
#endif

#include "network/HttpServer.h"

QSharedPointer<HttpServer> http_server_ptr_ {nullptr};

int main(int argc, char *argv[])
{
#if defined (Q_OS_LINUX)
    //create signal handler lambda
    const auto signal_handler{[](int signum){
            exit(EXIT_SUCCESS);
    }};
    //connect to signals
    signal(SIGTERM, signal_handler);
    signal(SIGINT, signal_handler);
    signal(SIGKILL, signal_handler);
    signal(SIGHUP, signal_handler);
#endif

    QCoreApplication a(argc, argv);
    http_server_ptr_.reset(new HttpServer("localhost",8080));
    const bool& success {http_server_ptr_->start_listen()};
    if(!success){
        return EXIT_FAILURE;
    }
    std::cout<<"http server is listening now"<<std::endl;
    return a.exec();
}
