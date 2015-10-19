//
// Created by stengun on 19/10/15.
//

#ifndef FARM_DATPARSER_H
#define FARM_DATPARSER_H


#include <QtCore/qxmlstream.h>
#include <src/data/setobjects.h>
#include <src/data/setcontainers.h>
#include <QtCore/qfile.h>

class Datparser {
public:
    Datparser(QString path);
    ~Datparser();
    void startRead(QFile *datfile);
    ItemCollection* readObject();
private:
    QXmlStreamReader xmlstream;
    QString path;
    void readRoms(ItemCollection *icol);
    void readSamples(Game *icol);

};


#endif //FARM_DATPARSER_H
