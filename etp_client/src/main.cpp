#include <QApplication>
#include "gui/ClientWindow.h"
#include "network/EtpClient.h"

#if defined(Q_OS_LINUX)
#include <signal.h>
#endif

int main(int argc, char *argv[])
{
#if defined(Q_OS_LINUX)
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

    QApplication app(argc,argv);
    EtpClient etp_client(nullptr);
    etp_client.begin_session("127.0.0.1",2345);
    ClientWindow client_window;
    client_window.show();
    return app.exec();
}
