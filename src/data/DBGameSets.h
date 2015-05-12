/* 
 * File:   DBGameSets.h
 * Author: Roberto Benfatto
 *
 * Created on 12 maggio 2015, 22.18
 */

#ifndef DBGAMESETS_H
#define	DBGAMESETS_H

#include "DatabaseHelper.h"

class DBGameSets : public DatabaseHelper {
    static const QString dbname = "setdatabase.db";
public:
    DBGameSets(const QString dbpath, unsigned int version);
    bool addRom(QString gamename, Rom& rom);
    bool addSet(Game& game);
    virtual void onConfig(QSqlDatabase& db);
    virtual void onCreate(QSqlDatabase& db);
    virtual void onUpdate(QSqlDatabase& db, int oldver, int newver);
    operator<<();
    virtual ~DBGameSets();
private:
    DBGameSets(const DBGameSets& orig) = delete;

};

#endif	/* DBGAMESETS_H */

