#include "farm.h"

#include <QtCore/QDebug>
#include <iostream>

#include <QtQml/QQmlEngine>
#include <QGuiApplication>
#include <QQmlContext>
#include <QQuickView>


Farm::Farm(int argc, char** argv)
  : QApplication(argc, argv),
    engine(nullptr),
    window(nullptr)
{
}

Farm::~Farm()
{
}

int Farm::exec()
{
    setup();
    return QApplication::exec();
}


void Farm::setup()
{
    engine = new QQmlEngine(this);
    QQmlComponent* mainQmlView = new QQmlComponent(engine, this);
    connect(engine, SIGNAL(quit()), this, SLOT(quit()));

    mainQmlView->loadUrl(QUrl("qrc:///qml/window.qml"));
    if (!mainQmlView->isReady()) {
        std::cerr << mainQmlView->errorString().toStdString() << std::endl;
        std::exit(-1);
    }

    QObject *topLevel = mainQmlView->create();
    window = qobject_cast<QQuickWindow*>(topLevel);

//     QSurfaceFormat surfaceFormat = window->requestedFormat();
//     window->setFormat(surfaceFormat);
//     window->show();


    QStringList dataList;
    dataList.append("Item 1");
    dataList.append("Item 2");
    dataList.append("Item 3");
    dataList.append("Item 4");

    QQmlContext* context = engine->rootContext();
    context->setContextProperty("myModel", QVariant::fromValue(dataList));
}

