#include "Populator.h"//
// Created by stengun on 11/11/15.
//

#include <iostream>
#include <QtConcurrent/QtConcurrent>
#include "Populator.h"

void Populator::run() {
    parser->startRead();
    emit started(parser->getTotalSets());
    int bios=0,mech=0,oth=0;
    QFutureWatcher<void> futureDBWatcher;
    QVector<std::list<ItemCollection*>> setvector;
    int count = 0;
    std::list<ItemCollection*> games;
    while(true) {
        ItemCollection *col = parser->readObject();
        if(col == nullptr) {
            if(!games.empty()) setvector.append(games);
            break;
        }
        if(count < 1000) {
            games.push_back(col);
            count++;
        } else {
            count = 0;
            setvector.append(games);
            games = std::list<ItemCollection*>();
        }
        switch(col->getType()) {
            case TYPE_BIOS:
                bios++;
                break;
            case TYPE_GAME:
            case TYPE_MECHANICAL:
                mech++;
                break;
            case TYPE_DEVICE:
                oth++;
            default:
                break;
        }
        emit progressChanged(bios+mech+oth);
    }
    emit progressChanged(0);
    qInfo("PARSED sets: %d", mech);
    qInfo("PARSED BIOS only: %d", bios);
    qInfo("PARSED OTHER: %d", oth);
    futureDBWatcher.setFuture(QtConcurrent::map(setvector, [=](std::list<ItemCollection*> itm ) { db->addSets(itm);}));
    futureDBWatcher.waitForFinished();
}

void Populator::stop() {
    //Safe stop
}

Populator::Populator(QString datpath, QString dbpath) {
    this->db = new DBGameSets(dbpath, 1);
    db->init(dbpath, 1);
    this->parser = new Datparser(datpath);
}

Populator::Populator() {

}

Populator::~Populator() {
    delete db;
    delete parser;
}

//-------

bool Populator::beginParse() {

}

int Populator::countTotalSets() {

}