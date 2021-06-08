#pragma once

#include <QMainWindow>
#include <QtGui/QPainter>
#include <QtGui/QResizeEvent>
#include <QtGui/QExposeEvent>
#include <QtGui/QBackingStore>
#include <QtCore/QElapsedTimer>
#include <QApplication>
#include <QGridLayout>
#include <QLabel>
#include <QMdiArea>
#include <QDebug>
#include <QTimer>
#include <memory>

#include "devbutton.h"
#include "resource.h"

class MainWindow : public QMainWindow
{

public:

 MainWindow(QWidget *parent = 0);

protected:

 virtual bool event(QEvent *event) override;
 virtual void resizeEvent(QResizeEvent *event) override;

private :

     void renderLater();
     void renderNow();
     void renderScene();

     QMdiArea* mdiArea;
     DevButton* button;
     Resource rec;
};
