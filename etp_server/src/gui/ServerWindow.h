#ifndef MAINWINDOWS_H
#define MAINWINDOWS_H

#include <memory>
#include <QMainWindow>
#include <QSharedPointer>

class QLineEdit;
class QTextEdit;
class QComboBox;
class QSpinBox;
class QPushButton;
class EtpServer;

namespace spdlog{
    class logger;
}

class ServerWindow : public QMainWindow
{
    Q_OBJECT
private:
    QLineEdit* iplineedit_ptr_ {nullptr};
    QSpinBox* portspinbox_ptr_ {nullptr};
    QPushButton* startbutton_ptr_ {nullptr};
    QPushButton* stopbutton_ptr_ {nullptr};

    QSharedPointer<EtpServer> etpserver_ptr_ {nullptr};
    std::shared_ptr<spdlog::logger> logger_ptr_ {nullptr};

    void init_logger();
    void init_gui();
    void init_server();

public:
    explicit ServerWindow(QWidget *parent = nullptr);
    virtual ~ServerWindow()=default;

private slots:
    void slot_start();
    void slot_stop();

    void slot_client_connected(const QString& client_uid);
    void slot_client_disconnected(const QString& client_uid);

signals:

};

#endif // MAINWINDOWS_H
