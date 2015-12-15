//
// Created by stengun on 13/12/15.
//

#include <QtWidgets/qfiledialog.h>
#include <src/utils/FolderParser.h>
#include "FarmMain.h"

void FarmMain::populateDatInfo() {
    for(QString line : pop->getDatInfo())
        this->listWidget->addItem(line);
}

void FarmMain::setupConnections() {
    QObject::connect(this->actionLoad_dat, &QAction::triggered, [=]{ pop->setDatPath(QFileDialog::getOpenFileName(this)); populateDatInfo(); });
    QObject::connect(this->btn_database, &QPushButton::clicked, this->pop, &Populator::run);
    QObject::connect(this->pop, &Populator::started, this->progressBar, &QProgressBar::setMaximum);
    QObject::connect(this->pop, &Populator::progressChanged, this->progressBar, &QProgressBar::setValue);
    QObject::connect(this->btn_zip, &QPushButton::clicked, [=] { this->lineEdit_zip->setText(QFileDialog::getOpenFileName(this));});
    QObject::connect(this->btn_check, &QPushButton::clicked, [=]{ SetReader::itemFromZip(this->lineEdit_zip->text()); });
}

FarmMain::FarmMain() {
    this->pop = new Populator("./test.db");
    setupUi(this);
    setupConnections();
}