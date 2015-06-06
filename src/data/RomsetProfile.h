/* 
 * File:   RomsetProfile.h
 * Author: Roberto Benfatto
 *
 * Created on 14 maggio 2015, 20.42
 */

#ifndef ROMSETPROFILE_H
#define	ROMSETPROFILE_H
#include <QtCore/QString>
#include <QtCore/QObject>
#include <QtCore/QSettings>
#include <QtSql/QSqlDatabase>

class RomsetProfile : public QObject {
public:
    enum DBType { DB_DATASET, DB_OWNROMS, DB_BACKUP};
    RomsetProfile() : name(), settings(), datpath() {};
    RomsetProfile(const RomsetProfile& orig);
    void setName(QString name) { this->name = name; };
    QString getName() {return name; };
    void setDatPath(QString path) {this->datpath = path; };
    QString getDatPath() { return datpath; };
    QSqlDatabase getDatabase(DBType type);
    virtual ~RomsetProfile() {};
public slots:
    void generateDBFromDat();
private:
    QString datpath;
    QString name;
    QSettings settings;
    
};

#endif	/* ROMSETPROFILE_H */

