#pragma once

#include <QWidget>
#include <QCheckBox>
#include <QLabel>

#include "resource.h"

class InfoDevice : public QWidget
{
public:
    InfoDevice(QWidget* parent, Resource* rec, Device dev);
private:
    Device dev;
    Resource* rec;
};
