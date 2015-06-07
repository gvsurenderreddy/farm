/*
 * File:   RomsetProfile.cpp
 * Author: Roberto Benfatto
 *
 * Created on 14 maggio 2015, 20.42
 */

#include "RomsetProfile.h"

// commented out because I'm not sure about the clone of the parent
//RomsetProfile::RomsetProfile(const RomsetProfile& orig)
// : RomsetProfile(orig.name, orig.datpath, orig.active, orig.dbType, orig.parent())
//{
//}
RomsetProfile::RomsetProfile(bool active, QString name, RomsetProfile::DBType dbType, QString dataPath, quint32 romNumber, QString mameVersion, QObject* parent): QObject(parent)
{
    this->active = active;
    this->name = name;
    this->dbType = dbType;
    this->datpath = dataPath;
    this->romNumber = romNumber;
    this->mameVersion = mameVersion;
}



RomsetProfile::~RomsetProfile() {
}

void RomsetProfile::generateDBFromDat()
{

}

QString RomsetProfile::getDbTypeString()
{
    switch(dbType) {
        case RomsetProfile::DB_DATASET:
            return "dataset";
        case RomsetProfile::DB_BACKUP:
            return "backup";
        case RomsetProfile::DB_OWNROMS:
            return "own roms";
    }
}

void RomsetProfile::setDbTypeString(QString dbType)
{
    if (dbType == "dataset")
        setDbType(DB_DATASET);
    else if (dbType == "own roms")
        setDbType(DB_OWNROMS);
    else if (dbType == "backup")
        setDbType(DB_BACKUP);
    else
        std::cerr<<"unrecognized db type: "<<dbType.toStdString()<<std::endl;
}


