#pragma once

#include <QWidget>
#include <QPushButton>
#include <QApplication>
#include <QMdiArea>
#include <QDebug>

#include "resource.h"
#include "infodevice.h"

class DevButton : public QWidget
{
public:
    DevButton(QWidget* parent, Resource* rec);
    void Init(QWidget* parent);
private slots:
    void crch(QWidget* parent);
private:
    Resource* rec;
};
