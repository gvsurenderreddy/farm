#ifndef farm_H
#define farm_H

#include <QtQml/QQmlEngine>
#include <QtQml/QQmlComponent>
#include <QQuickWindow>
#include <QApplication>

class Farm : public QApplication
{
    Q_OBJECT

public:
    Farm(int argc, char** argv);
    virtual ~Farm();

    int exec();

protected:
    void setup();

    QQmlEngine* engine;
    QQuickWindow* window;
};

#endif // farm_H
