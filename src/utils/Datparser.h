//
// Created by stengun on 19/10/15.
//

#ifndef FARM_DATPARSER_H
#define FARM_DATPARSER_H


#include <QtCore/qxmlstream.h>
#include <src/data/setobjects.h>
#include <src/data/setcontainers.h>
#include <QtCore/qfile.h>
#include <mutex>

class Datparser {
public:
    Datparser(QString path);
    ~Datparser();
    int getTotalSets();
    void startRead();
    ItemCollection* readObject();
private:
    QXmlStreamReader xmlstream;
    QFile* datfile;
    int totalsets;
    std::mutex Mutex;

};


#endif //FARM_DATPARSER_H
