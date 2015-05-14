/* 
 * File:   DatabaseHelper.cpp
 * Author: Roberto Benfatto
 * 
 * Created on 6 maggio 2015, 14.29
 */

#include "DatabaseHelper.h"

DatabaseHelper::DatabaseHelper(QString dbpath, unsigned int version,QString uniquename) {
    if (version < 1) throw "Error: database version must be > 0.";
    this->version = version;
    this->initializing = false;
    this->name = dbpath;
    QSqlDatabase::addDatabase("QSQLITE", uniquename);
    this->db = QSqlDatabase::database(uniquename, false);
    this->db.setDatabaseName(dbpath);
    if (this->db.open()) {
        onOpen(db);
        onConfig(db);
        int ver = getVersion();
        if (ver == 0) this->onCreate(db);
        else if (ver < version) this->onUpdate(db, ver, version);
        else if (ver > version) onDowngrade(db, ver, version);
        setVersion(version);
    } else {
        throw "Error: cannot open database";
    }
}

QSqlQuery DatabaseHelper::query(const QString str_query, std::list<QVariant> params) {
    if (db.isOpen()) {
        db.transaction();
        QSqlQuery qry = QSqlQuery(db);
        qry.prepare(str_query);
        if (!params.empty()) {
            for (auto val : params) {
                qry.addBindValue(val);
            }
        }
        qry.exec();
        qry.finish();
        if (qry.lastError().type() != QSqlError::NoError) {
            db.rollback();
            //Insert logging things here
        } else {
            db.commit();
        }
        return qry;
    } else {
        throw new QSqlError("Can't query database while closed");
    }
}

void DatabaseHelper::close() {
    std::lock_guard<std::mutex> Guard(this->Mutex);
    if (this->initializing) throw "Error: invalid state";
    if (this->db.isOpen()) {
        this->db.close();
    }
}

int DatabaseHelper::getVersion() {
    QSqlQuery qry = this->query("pragma user_version");
    if (qry.lastError().type() == QSqlError::NoError) {
        return qry.value(0).toInt();
    }
    throw "Error getting database version.";
}

void DatabaseHelper::setVersion(int version) {
    QSqlQuery qry = this->query("pragma user_version=?", { version });
    if (qry.lastError().type() == QSqlError::NoError) {
        this->version = version;
        return;
    }
    throw "Error setting database version.";
}

DatabaseHelper::~DatabaseHelper() {
    close();
    QSqlDatabase::removeDatabase(db.connectionName());
}

