#include "ServerWindow.h"
#include "network/EtpServer.h"

#include <QUrl>
#include <QLabel>
#include <QSpinBox>
#include <QLineEdit>
#include <QTextEdit>
#include <QComboBox>
#include <QGroupBox>
#include <QStatusBar>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QHostAddress>
#include "spdlog/spdlog.h"

void ServerWindow::init_logger()
{

}

void ServerWindow::init_gui()
{
    startbutton_ptr_=new QPushButton(QObject::tr("Start"));
    QObject::connect(startbutton_ptr_,&QPushButton::clicked,
                     this,&ServerWindow::slot_start);
    stopbutton_ptr_=new QPushButton(QObject::tr("Stop"));
    QObject::connect(stopbutton_ptr_,&QPushButton::clicked,
                     this,&ServerWindow::slot_stop);

    iplineedit_ptr_=new QLineEdit;
    iplineedit_ptr_->setInputMask("000.000.000.000;0");
    portspinbox_ptr_=new QSpinBox;
    portspinbox_ptr_->setRange(0,0xFFFF);
    portspinbox_ptr_->setAlignment(Qt::AlignRight);
    portspinbox_ptr_->setValue(2324);
    portspinbox_ptr_->setFixedWidth(50);

    QGridLayout* gridlayout_ptr {new QGridLayout};
    gridlayout_ptr->addWidget(new QLabel(QObject::tr("Address:")),0,0);
    gridlayout_ptr->addWidget(iplineedit_ptr_,0,1);

    gridlayout_ptr->addWidget(new QLabel(QObject::tr("Port:")),1,0);
    gridlayout_ptr->addWidget(portspinbox_ptr_,1,1);

    gridlayout_ptr->addWidget(startbutton_ptr_,0,2);
    gridlayout_ptr->addWidget(stopbutton_ptr_,1,2);

    QGroupBox* connectiongroupbox_ptr {new QGroupBox(QObject::tr("Connection"))};
    connectiongroupbox_ptr->setLayout(gridlayout_ptr);

    QGroupBox* outputgroupbox_ptr {new QGroupBox(QObject::tr("Output"))};

    QVBoxLayout* mainvboxlayout_ptr {new QVBoxLayout};
    mainvboxlayout_ptr->addWidget(connectiongroupbox_ptr,0);
    mainvboxlayout_ptr->addWidget(outputgroupbox_ptr,10);

    QWidget* centralwidget_ptr {new QWidget};
    centralwidget_ptr->setLayout(mainvboxlayout_ptr);
    setCentralWidget(centralwidget_ptr);

    statusBar()->showMessage(QObject::tr("Ready..."));
}

void ServerWindow::init_server()
{
    //create etp server
    etpserver_ptr_.reset(new EtpServer(logger_ptr_));
    //make signal/slot connections
    QObject::connect(etpserver_ptr_.get(),&EtpServer::signal_client_connected,
                     this,&ServerWindow::slot_client_connected);
    QObject::connect(etpserver_ptr_.get(),&EtpServer::signal_client_disconnected,
                     this,&ServerWindow::slot_client_disconnected);
}

ServerWindow::ServerWindow(QWidget *parent) : QMainWindow(parent)
{
    init_logger();
    init_gui();
    init_server();
}

void ServerWindow::slot_start()
{
    if(!etpserver_ptr_){
        return;
    }
    etpserver_ptr_->init(QHostAddress(QHostAddress::LocalHost).toString(),0);
    const bool& ok {etpserver_ptr_->start_listen()};
    if(!ok){
        const QString& msg {etpserver_ptr_->err_str()};
        statusBar()->showMessage(msg);
        return;
    }
    statusBar()->showMessage(QObject::tr("Listening..."));
}

void ServerWindow::slot_stop()
{
    if(etpserver_ptr_ && etpserver_ptr_->is_listening()){
        etpserver_ptr_->stop_listen();
        statusBar()->showMessage(QObject::tr("Ready..."));
    }
}

void ServerWindow::slot_client_connected(const QString &client_uid)
{

}

void ServerWindow::slot_client_disconnected(const QString &client_uid)
{

}
