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
    void init(QString dbpath, unsigned int version,QString uniquename);
    virtual void onUpdate(QSqlDatabase& db, int oldver, int newver) = 0;
    virtual void onCreate(QSqlDatabase& db) = 0;
    virtual void onOpen(QSqlDatabase& db) = 0;
    virtual void onConfig(QSqlDatabase& db) = 0;
    virtual void onDowngrade(QSqlDatabase& db, int oldver, int newver) = 0;
public:
    DatabaseHelper(QString dbpath, unsigned int version,QString uniquename);
    QString getDatabaseName() { return this->name; };
    QSqlQuery query(const QString str_query, std::list<QVariantList> params={}, bool batch=false);
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

