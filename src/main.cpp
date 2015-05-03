#include <QtGui/QGuiApplication>
#include <QtQml/QQmlEngine>
#include <QtQuick/QQuickWindow>

#include <QtCore/QtDebug>

#include "farm.h"
#include <iostream>

int main(int argc, char** argv)
{
    std::cerr << 0 <<std::endl;
    QGuiApplication app(argc, argv);


    std::cerr << 1 <<std::endl;
    Farm farm;
    farm.create();

    std::cerr << 2 <<std::endl;

    bool ret = app.exec();

    std::cerr << 3 <<std::endl;

    return ret;
}
