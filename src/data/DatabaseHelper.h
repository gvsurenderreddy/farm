/* 
 * File:   DatabaseHelper.h
 * Author: Roberto Benfatto
 *
 * Created on 6 maggio 2015, 14.29
 */

#ifndef DATABASEHELPER_H
#define	DATABASEHELPER_H
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtCore/QVariant>
#include <mutex>
#include <list>

class DatabaseHelper {
protected:
    bool initializing;
    QSqlDatabase db;
    virtual void onUpdate(QSqlDatabase& db, int oldver, int newver) {};
    virtual void onCreate(QSqlDatabase& db) {};
    virtual void onOpen(QSqlDatabase& db) {};
    virtual void onConfig(QSqlDatabase& db) {};
    virtual void onDowngrade(QSqlDatabase& db, int oldver, int newver) {};
public:
    DatabaseHelper(QString dbpath, unsigned int version,QString uniquename);
    QString getDatabaseName() { return this->name; };
    QSqlQuery query(const QString str_query, std::list<QVariant> params={});
    void close();
    virtual ~DatabaseHelper();
private:
    int getVersion();
    void setVersion(int version);
    DatabaseHelper(const DatabaseHelper& orig);
    QString name;
    int version;
    std::mutex Mutex;
};

#endif	/* DATABASEHELPER_H */

