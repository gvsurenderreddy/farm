
#include <src/utils/Datparser.h>
#include <QtWidgets/qmainwindow.h>
#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qpushbutton.h>
#include <src/workers/Populator.h>
#include <QtWidgets/qprogressbar.h>
#include <QtWidgets/qlineedit.h>
#include <QtWidgets/qfiledialog.h>
#include <src/gui/FarmMain.h>
#include "farm.h"

int main(int argc, char** argv)
{
    //Populator* pop = new Populator("./test.db");
    QApplication app(argc, argv);
    FarmMain wmain;
    wmain.show();
    app.exec();

//    Farm farm(argc, argv);
//    return farm.exec();
}
