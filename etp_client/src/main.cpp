#include <QApplication>
#include "gui/MainWindow.h"

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
    MainWindow main_window;
    main_window.show();
    return app.exec();
}
