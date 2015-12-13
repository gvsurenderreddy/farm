#include <iostream>
#include <src/utils/Datparser.h>
#include <src/data/DBGameSets.h>
#include <QtCore/qprocess.h>
#include <QtWidgets/qmainwindow.h>
#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qpushbutton.h>
#include <src/workers/Populator.h>
#include <QtWidgets/qprogressbar.h>
#include "farm.h"

int main(int argc, char** argv)
{
    Populator* pop = new Populator("/home/stengun/mame166.dat", "./test.db");
    QApplication app(argc, argv);

    QMainWindow w(nullptr);
    QWidget* centwidget = new QWidget(&w);
    w.setCentralWidget(centwidget);
    QVBoxLayout* ml = new QVBoxLayout(&w);
    QPushButton* btn = new QPushButton("diocane");
    QProgressBar* pbar = new QProgressBar();
    pbar->setValue(0);
    QObject::connect(pop, SIGNAL(started(int)), pbar, SLOT(setMaximum(int)));
    QObject::connect(pop, SIGNAL(progressRangeChanged(int,int)), pbar, SLOT(setRange(int, int)));
    QObject::connect(pop, SIGNAL(progressChanged(int)), pbar, SLOT(setValue(int)));
    QObject::connect(pop, &Populator::finished, btn, [btn] { btn->setText("Finito"); });
    QObject::connect(btn, SIGNAL(clicked()), pop, SLOT(run()));
    ml->addWidget(pbar);
    ml->addWidget(btn);
    centwidget->setLayout(ml);
    w.show();
    app.exec();

//    Farm farm(argc, argv);
//    return farm.exec();
}
