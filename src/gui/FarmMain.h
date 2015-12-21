//
// Created by stengun on 13/12/15.
//

#ifndef FARM_FARMMAIN_H
#define FARM_FARMMAIN_H

#include <src/workers/Populator.h>
#include "Ui_MainWindow.h"

class FarmMain : public QMainWindow, Ui_MainWindow {
    Q_OBJECT
public:
    FarmMain();
private:
    void setupConnections();
    void populateDatInfo();
    Populator* pop;
};


#endif //FARM_FARMMAIN_H
