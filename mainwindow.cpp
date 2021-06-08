#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{

    setMinimumSize(QSize(600,600));


    for(int i=0; i <10; i++)
    {
        int group = rand()%5;
        rec.devices.push_back({
                                 std::to_string(group) + "-" + std::to_string(rand()%1000),
                                 group, rand() % 4, false, true
                              });
    }

    button = new DevButton(this, &rec);
    button->Init(this);

    rec.parent = parent;


}

bool MainWindow::event(QEvent *event)
{
    if(event->type() == QEvent::UpdateRequest)
    {
        renderNow();
        return true;
    }
    return QWidget::event(event);
}

void MainWindow::resizeEvent(QResizeEvent *resizeEvent)
{

}

void MainWindow::renderLater()
{

}

void MainWindow::renderNow()
{
    renderScene();

    renderLater();
}


void MainWindow::renderScene()
{

}

