#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <memory>
#include <QMainWindow>

namespace spdlog{
    class logger;
}

class ClientWindow : public QMainWindow
{
    Q_OBJECT
private:
    std::shared_ptr<spdlog::logger> logger_ptr_ {nullptr};

public:
    explicit ClientWindow(QWidget *parent = nullptr);
    virtual ~ClientWindow()=default;

    void init_logger();
    void init_gui();

signals:

};

#endif // MAINWINDOW_H
