#include <iostream>
#include <QtConcurrent/QtConcurrent>
#include "Populator.h"

void Populator::run() {
    if(parser == nullptr) return;
    emit started(parser->getTotalSets());
    int bios=0,mech=0,oth=0;
    int count = 0;
    std::list<ItemCollection*> games;
    while(true) {
        ItemCollection *col = parser->readObject();
        if(col == nullptr) {
            if(!games.empty()) db->addSets(games);
            break;
        }
        if(count < 1000) {
            games.push_back(col);
            count++;
        } else {
            count = 0;
            db->addSets(games);
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
}

void Populator::stop() {
    //Safe stop
}

void Populator::setDatPath(QString path) {
    if(path.isEmpty()) return;
    this->xmlpath = path;
    delete this->parser;
    this->parser = new Datparser(path);
    this->dat_info = parser->startRead();
}

Populator::Populator(QString dbpath) {
    this->db = new DBGameSets(dbpath, 1);
    db->init(dbpath, 1);
    this->parser = nullptr;
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