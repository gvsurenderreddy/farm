#include <QApplication>
#include "farm.h"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    farm farm;
    farm.show();
    return app.exec();
}
