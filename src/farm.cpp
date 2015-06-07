#include "farm.h"

#include <QtCore/QDebug>
#include <iostream>

#include <QtQml/QQmlEngine>
#include <QGuiApplication>
#include <QQmlContext>
#include <QQuickView>

#include <RomsetProfile.h>

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
    RomsetProfile::declareQML();

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

    // profiles
    QList<QObject*> profileList; // bool active, QString name, DBType dbType, QString dataPath, quint32 romNumber, QString mameVersion, QObject* parent = 0
    profileList.append(new RomsetProfile(false, "Default", RomsetProfile::DB_DATASET, "/var/lib/farm/data/",    55, "14.0", context));
    profileList.append(new RomsetProfile(false, "Ciccolo", RomsetProfile::DB_DATASET, "/home/test/.farm/data/", 53, "14.0", context));
    profileList.append(new RomsetProfile(false, "Fillo's", RomsetProfile::DB_OWNROMS, "/home/test/farm/data/",  34, "14.0", context));
    profileList.append(new RomsetProfile(true,  "v13",     RomsetProfile::DB_BACKUP,  "/var/lib/farm/data/",    20, "13.0", context));
    profileList.append(new RomsetProfile(false, "v13.2",   RomsetProfile::DB_DATASET, "/var/lib/farm/data/",    23, "13.2", context));

    context->setContextProperty("profileList", QVariant::fromValue(profileList));
}

