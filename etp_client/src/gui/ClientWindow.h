#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <memory>
#include <QMainWindow>
#include <QSharedPointer>

class QSpinBox;
class QLineEdit;
class QTextEdit;
class QPushButton;
class EtpClent;

namespace spdlog{
    class logger;
}

class ClientWindow : public QMainWindow
{
    Q_OBJECT
private:
    QLineEdit* iplineedit_ptr_ {nullptr};
    QSpinBox* portspinbox_ptr_ {nullptr};
    QPushButton* beginpushbutton_ptr_ {nullptr};
    QPushButton* endpushbutton_ptr_ {nullptr};

    QSharedPointer<EtpClent> etpclient_ptr_ {nullptr};
    std::shared_ptr<spdlog::logger> logger_ptr_ {nullptr};

public:
    explicit ClientWindow(QWidget *parent = nullptr);
    virtual ~ClientWindow()=default;

    void init_logger();
    void init_gui();

private slots:
    void slot_begin();
    void slot_end();

signals:

};

#endif // MAINWINDOW_H
