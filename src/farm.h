#ifndef farm_H
#define farm_H

#include <QtQml/QQmlEngine>
#include <QtQml/QQmlComponent>
#include <QQuickWindow>

class Farm : public QObject
{
    Q_OBJECT

public:
    Farm();
    virtual ~Farm();

    void create();

protected:
    QQmlEngine* engine;
    QQmlComponent* mainQmlView;
    QQuickWindow* window;
};

#endif // farm_H
