#include "devbutton.h"

DevButton::DevButton(QWidget* parent, Resource *rec) : QWidget(parent)
{
    this->rec = rec;

}

void DevButton::Init(QWidget* parent)
{
    int x = 0;
    for(int g=0; g < 5;g++)
    {
        for(auto d : rec->devices)
        {
            if(d.group != g) continue;

            QPushButton *devButton = new QPushButton(d.name.c_str(), parent);
            QPalette pal = devButton->palette();
            switch (d.status) {
                case 0:
                    pal.setColor(QPalette::Button, QColor(Qt::green));
                    break;
                case 1:
                    pal.setColor(QPalette::Button, QColor(Qt::red));
                    break;
                case 2:
                    pal.setColor(QPalette::Button, QColor(Qt::yellow));
                    break;
                case 3:
                    pal.setColor(QPalette::Button, QColor(Qt::blue));
                    break;
                default:
                    break;
            }

            devButton->setAutoFillBackground(true);
            devButton->setPalette(pal);
            devButton->update();
            devButton->setGeometry(50 + (g * 120),50 + (x * 30),60,30);

            connect(devButton, &QPushButton::clicked, this, [=](){

                InfoDevice* iDevice = new InfoDevice(rec->parent, rec, d);
                iDevice->resize(300,400);
                iDevice->move(100,100);
                iDevice->setWindowTitle(d.name.c_str());
                iDevice->show();
            });

            x++;
        }
        x=0;
    }

}

void DevButton::crch(QWidget* parent)
{
    qDebug() << "adawddaw";
}
