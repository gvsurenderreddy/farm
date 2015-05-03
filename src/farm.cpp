#include "farm.h"

#include <QtCore/QDebug>
#include <iostream>

#include <QtQml/QQmlEngine>
#include <QGuiApplication>


Farm::Farm()
  : QObject()
{
}

Farm::~Farm()
{
}

void Farm::create()
{
    engine = new QQmlEngine();
    mainQmlView = new QQmlComponent(engine);
    connect(engine, SIGNAL(quit()), QGuiApplication::instance(), SLOT(quit()));

    mainQmlView->loadUrl(QUrl("qrc:///qml/window.qml"));
    if (!mainQmlView->isReady()) {
        std::cerr << mainQmlView->errorString().toStdString() << std::endl;
        QGuiApplication::exit(-1);
        exit(-1);
        return;
    }

    QObject *topLevel = mainQmlView->create();
    window = qobject_cast<QQuickWindow*>(topLevel);

//     QSurfaceFormat surfaceFormat = window->requestedFormat();
//     window->setFormat(surfaceFormat);
    window->show();
}

