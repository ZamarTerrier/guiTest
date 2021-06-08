#pragma once
#include <QWidget>
#include <string>
#include <vector>

struct Device{
    std::string name;
    int group;
    int status;
    bool ctrlState;
    bool ctrlHDState;
};

class Resource
{
public:
    Resource();
    std::vector<Device> devices;
    QWidget* parent;
};

