#include "ClientWindow.h"

#include <QUrl>
#include <QLabel>
#include <QSpinBox>
#include <QLineEdit>
#include <QTextEdit>
#include <QGroupBox>
#include <QStatusBar>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

ClientWindow::ClientWindow(QWidget *parent) : QMainWindow(parent)
{
    setWindowTitle("Etp client");
    init_logger();
    init_gui();
}

void ClientWindow::init_logger()
{

}

void ClientWindow::init_gui()
{
    beginpushbutton_ptr_=new QPushButton(QObject::tr("Begin session"));
    QObject::connect(beginpushbutton_ptr_,&QPushButton::clicked,
                     this,&ClientWindow::slot_begin);
    endpushbutton_ptr_=new QPushButton(QObject::tr("End session"));
    QObject::connect(endpushbutton_ptr_,&QPushButton::clicked,
                     this,&ClientWindow::slot_end);

    iplineedit_ptr_=new QLineEdit;
    iplineedit_ptr_->setInputMask("000.000.000.000;0");

    portspinbox_ptr_=new QSpinBox;
    portspinbox_ptr_->setRange(0,0xFFFF);
    portspinbox_ptr_->setAlignment(Qt::AlignRight);
    portspinbox_ptr_->setValue(2345);
    portspinbox_ptr_->setFixedWidth(50);

    QGridLayout* gridlayout_ptr {new QGridLayout};
    gridlayout_ptr->addWidget(new QLabel(QObject::tr("Address:")),0,0);
    gridlayout_ptr->addWidget(iplineedit_ptr_,0,1);

    gridlayout_ptr->addWidget(new QLabel(QObject::tr("Port:")),1,0);
    gridlayout_ptr->addWidget(portspinbox_ptr_,1,1);

    gridlayout_ptr->addWidget(beginpushbutton_ptr_,0,2);
    gridlayout_ptr->addWidget(endpushbutton_ptr_,1,2);

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

void ClientWindow::slot_begin()
{

}

void ClientWindow::slot_end()
{

}

