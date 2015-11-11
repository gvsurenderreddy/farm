/* 
 * File:   DBGameSets.h
 * Author: Roberto Benfatto
 *
 * Created on 12 maggio 2015, 22.18
 */

#ifndef DBGAMESETS_H
#define	DBGAMESETS_H
#define DBNAME "setdatabase.db"
#include "DatabaseHelper.h"
#include "setcontainers.h"
#include <QtCore/QString>

class DBGameSets : public DatabaseHelper {
public:
    DBGameSets(const QString dbpath, unsigned int version);
    bool addRom(QString setname, Rom* rom);
    bool addSet(ItemCollection* game);
    void init(QString dbpath, unsigned int version);
    virtual void onConfig(QSqlDatabase& db);
    virtual void onCreate(QSqlDatabase& db);
    virtual void onUpdate(QSqlDatabase& db, int oldver, int newver);
    virtual void onOpen(QSqlDatabase& db) {};
    virtual void onDowngrade(QSqlDatabase& db, int oldver, int newver) {};
//    operator<<(Game& game);
    virtual ~DBGameSets();
private:
    DBGameSets(const DBGameSets& orig) = delete;
};

#endif	/* DBGAMESETS_H */

