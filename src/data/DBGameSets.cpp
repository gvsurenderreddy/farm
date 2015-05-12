/* 
 * File:   DBGameSets.cpp
 * Author: Roberto Benfatto
 * 
 * Created on 12 maggio 2015, 22.18
 */

#include "DBGameSets.h"
#include "setobjects.h"
#include "setcontainers.h"
#include <QtSql/QSqlError>
DBGameSets::DBGameSets(const QString dbpath, unsigned int version) : DatabaseHelper(dbpath, version, dbname) {
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
    this->query(db, "\
        create table ROMSET (\
        setname varchar(255) NOT NULL PRIMARY KEY,\
        year varchar(255),\
        manufacturer varchar(255),\
        description varchar(255),\
        is_bios int NOT NULL)\
        ");
    this->query(db, "\
        create table ROM (\
        romname varchar(255) NOT NULL,\
        setname varchar(255) NOT NULL REFERENCES ROMSET(setname),\
        hash varchar(255),\
        crc varchar(255),\
        size int,\
        is_baddump int not null,\
        primary key (romname, setname)\
        )\
        ")
    this->query(db, "\
        create table share (\
        parent varchar(255) not null references ROMSET(setname),\
        child varchar(255) not null references ROMSET(setname),\
        primary key (parent, child)\
        )\
        ");
    initializing = false;
}

void DBGameSets::onUpdate(QSqlDatabase& db, int oldver, int newver) {
    initializing = true;
    //Do update tables and related stuff
    initializing = false;
}

bool DBGameSets::addRom(QString gamename, Rom& rom) {
    /**
     * params=(romname, setname, romhash, romcrc, size, 1 if is_baddump else 0)
     */
    int baddump = rom.getStatus() == status_t.STATUS_BADDUMP ? 1 : 0;
    QSqlQuery qry = this->query("\
                                insert into ROM values (?,?,?,?,?,?)\
                                ",
                                { rom.getName(), gamename, rom.getSha1(), rom.getCrc(), rom.getSize(), baddump }
    );
    return qry.lastError().type() == QSqlError::NoError;
}

bool DBGameSets::addSet(Game& game) {
    /*
     * params=(setname, year, manufacturer, description, 1 if isbios else 0))
     */
    QSqlQuery qry = query("insert into romset values (?,?,?,?,?)",
          { game.getName(), game.getYear(), game.getManufacturer(), game.getDescription(), game.getType() == TYPE_BIOS ? 1 : 0 }
    );
    if (qry.lastError().type() != QSqlError::NoError) return false;
    QHash::const_iterator itr = game.getItemIteratorBegin();
    while (itr != game.getItemIteratorEnd()) {
        if (this->addRom(game.getName(), *itr)) ++itr;
        else return false;
    }
    return true;
}



DBGameSets::~DBGameSets() {
}

