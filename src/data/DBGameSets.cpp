/* 
 * File:   DBGameSets.cpp
 * Author: Roberto Benfatto
 * 
 * Created on 12 maggio 2015, 22.18
 */

#include <iostream>
#include "DBGameSets.h"
DBGameSets::DBGameSets(const QString dbpath, unsigned int version) : DatabaseHelper(dbpath, version, DBNAME) {
}

void DBGameSets::init(QString dbpath, unsigned int version) {
    DatabaseHelper::init(dbpath, version, DBNAME);
}

void DBGameSets::onConfig(QSqlDatabase& db) {
    db.transaction();
    QSqlQuery qry = QSqlQuery(db);
    qry.prepare("pragma foreign_keys=ON");
    qry.exec();
    qry.finish();
    db.commit();
}

void DBGameSets::onCreate(QSqlDatabase& db) {
    initializing = true;
    this->query("\
create table ROMSET ( \
setname varchar(255) NOT NULL PRIMARY KEY, \
year varchar(255), \
manufacturer varchar(255), \
description varchar(255), \
type int NOT NULL)");
    this->query("\
create table ROM ( \
romname varchar(255) NOT NULL, \
setname varchar(255) NOT NULL REFERENCES ROMSET(setname), \
hash varchar(255), \
crc varchar(255), \
size int, \
is_baddump int not null, \
primary key (romname, setname) \
)");
    this->query("\
create table share ( \
parent varchar(255) not null references ROMSET(setname), \
child varchar(255) not null references ROMSET(setname), \
primary key (parent, child) \
)");
    initializing = false;
}

void DBGameSets::onUpdate(QSqlDatabase& db, int oldver, int newver) {
    initializing = true;
    //Do update tables and related stuff
    initializing = false;
}

bool DBGameSets::addRom(QString setname, Rom* rom) {
    /**
     * params=(romname, setname, romhash, romcrc, size, 1 if is_baddump else 0)
     */
    int baddump = rom->getStatus() == status_t::STATUS_BADDUMP ? 1 : 0;
    QSqlQuery qry = query("insert into ROM values (?,?,?,?,?,?)",
                          {{rom->getName()}, {setname}, {rom->getSha1()}, {rom->getCrc()}, {rom->getSize()}, {baddump} },
        true);
    return qry.lastError().type() == QSqlError::NoError;
}

bool DBGameSets::addSet(ItemCollection* game) {
    /*
     * params=(setname, year, manufacturer, description, rom type))
     */
    QSqlQuery qry = query("insert into romset values (?,?,?,?,?)",
          { {game->getName()}, {game->getYear()}, {game->getManufacturer()}, {game->getDescription()}, {game->getType()} },
        true);
    if (qry.lastError().type() != QSqlError::NoError) return false;
    QVariantList romname, crc, sha1, setname, size, baddump;
    auto itr = game->getItemIteratorBegin();
    while (itr != game->getItemIteratorEnd()) {
        Rom* val = reinterpret_cast<Rom*>(itr.value());
        romname << val->getName();
        setname << game->getName();
        sha1 << val->getSha1();
        crc << val->getCrc();
        size << val->getSize();
        baddump << (val->getStatus() == status_t::STATUS_BADDUMP ? 1 : 0);
        ++itr;
        //if (this->addRom(game->getName(), reinterpret_cast<Rom*>(itr.value()))) ++itr;
        //else return false;
    }
    qry = query("insert into ROM values (?,?,?,?,?,?)", {romname, setname, sha1, crc, size, baddump}, true);
    return qry.lastError().type() == QSqlError::NoError;
}



DBGameSets::~DBGameSets() {
}

