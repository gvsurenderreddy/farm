//
// Created by stengun on 15/12/15.
//

#ifndef FARM_FOLDERPARSER_H
#define FARM_FOLDERPARSER_H


#include <QtCore/qstring.h>
#include <src/data/setcontainers.h>
#include <quazip5/quazip.h>
#include <quazip5/quazipfile.h>
#include <QDebug>

class FolderParser {
public:
    FolderParser(QString path);

};

class SetReader {
public:
    SetReader() {};
    static ItemCollection* itemFromZip(QString path);
};


#endif //FARM_FOLDERPARSER_H
