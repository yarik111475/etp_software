#include <iostream>
#include <QtGlobal>
#include <QHostAddress>
#include <QSharedPointer>
#include <QApplication>

#if defined(Q_OS_LINUX)
#include <signal.h>
#endif

#include "network/EtpServer.h"
#include "gui/ServerWindow.h"

QSharedPointer<EtpServer> etpserver_ptr_ {nullptr};

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

    QApplication a(argc, argv);
    ServerWindow server_window;
    server_window.show();

    /*
    etpserver_ptr_.reset(new EtpServer("localhost", 2324, nullptr));
    const bool& success {etpserver_ptr_->start_listen()};
    if(!success){
        return EXIT_FAILURE;
    }
    std::cout<<"webserver is listening now"<<std::endl;
    */
    return a.exec();
}
