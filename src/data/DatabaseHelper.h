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
#include <QtCore/QVariant>
#include <mutex>
#include <list>
class DatabaseHelper {
protected:
    bool initializing;
    QSqlDatabase db;
    virtual void onUpdate(QSqlDatabase& db, int oldver, int newver) = 0;
    virtual void onCreate(QSqlDatabase& db) = 0;
    virtual void onOpen(QSqlDatabase& db) {};
    virtual void onConfig(QSqlDatabase& db) {};
    virtual void onDowngrade(QSqlDatabase& db) {};
public:
    DatabaseHelper(QString dbpath, int version);
    QString getDatabaseName() { return this->name; };
    QSqlQuery query(const QString str_query, std::list<auto> params={});
    void close();
    virtual ~DatabaseHelper();
private:
    int getVersion();
    void setVersion(int version);
    DatabaseHelper(const DatabaseHelper& orig) = delete;
    QString name;
    int version;
    std::mutex Mutex;
};

#endif	/* DATABASEHELPER_H */

