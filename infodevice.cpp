#include "infodevice.h"

InfoDevice::InfoDevice(QWidget* parent, Resource* rec, Device dev)
    :QWidget(parent)
{
    this->rec = rec;
    this->dev = dev;

    QLabel* name = new QLabel(this);
    QFont font = name->font();
    font.setPointSize(24);
    name->setGeometry(0,0, 600,30);
    std::string temp = "Name : " + dev.name;
    name->setText(temp.c_str());
    name->setFont(font);
    name->show();

    QLabel* statusLabel = new QLabel(this);
    font = statusLabel->font();
    font.setPointSize(18);
    statusLabel->setGeometry(120,45, 600,30);
    statusLabel->setText("Status");
    statusLabel->setFont(font);
    statusLabel->show();
    QLabel* status = new QLabel(this);
    font = status->font();
    font.setPointSize(14);
    status->setGeometry(122,87, 600,30);
    std::string sstatus;
    switch (dev.status) {
    case 0:
        sstatus = "Ok";
        status->setStyleSheet("color : rgb(0,200,0)");
        break;
    case 1:
        sstatus = "Danger";
        status->setStyleSheet("color : rgb(200,0,0)");
        break;
    case 2:
        sstatus = "Warning";
        status->setStyleSheet("color : rgb(255,255,0)");
        break;
    case 3:
        sstatus = "Offline";
        status->setStyleSheet("color : rgb(0,0,200)");
        break;
    default:
        break;
    }
    status->setText(sstatus.c_str());

    status->setFont(font);
    status->show();


    QLabel* ctrlState = new QLabel(this);
    font = ctrlState->font();
    font.setPointSize(18);
    ctrlState->setGeometry(80,129, 600,30);
    ctrlState->setText("Control State");
    ctrlState->setFont(font);
    ctrlState->show();
    QCheckBox* cSCheck = new QCheckBox(this);
    cSCheck->setGeometry(150,171, 600,30);
    cSCheck->setChecked(dev.ctrlState);


    QLabel* ctrlHDState = new QLabel(this);
    font = ctrlHDState->font();
    font.setPointSize(18);
    ctrlHDState->setGeometry(70,191, 600,30);
    ctrlHDState->setText("Controll HD State");
    ctrlHDState->setFont(font);
    ctrlHDState->show();
    QCheckBox* cSHDCheck = new QCheckBox(this);
    cSHDCheck->setGeometry(150,233, 600,30);
    cSHDCheck->setChecked(dev.ctrlHDState);
}

