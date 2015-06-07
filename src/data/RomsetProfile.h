/*
 * File:   RomsetProfile.h
 * Author: Roberto Benfatto
 *
 * Created on 14 maggio 2015, 20.42
 */

#ifndef ROMSETPROFILE_H
#define ROMSETPROFILE_H
#include <QtCore/QString>
#include <QtCore/QObject>
#include <QtCore/QSettings>
#include <QtSql/QSqlDatabase>
#include <QtQml>

#include <iostream>

class RomsetProfile : public QObject {
    Q_OBJECT

    Q_PROPERTY(bool    active      READ isActive        WRITE setActive       NOTIFY activeChanged     )
    Q_PROPERTY(QString name        READ getName         WRITE setName         NOTIFY nameChanged       )
    Q_PROPERTY(QString dbType      READ getDbTypeString WRITE setDbTypeString NOTIFY dbTypeChanged     )
    Q_PROPERTY(DBType  dbTypeE     READ getDbType       WRITE setDbType       NOTIFY dbTypeChanged     )
    Q_PROPERTY(QString dataPath    READ getDatPath      WRITE setDatPath      NOTIFY dataPathChanged   )
    Q_PROPERTY(quint32 romNumber   READ getRomNumber    WRITE setRomNumber    NOTIFY romNumberChanged  )
    Q_PROPERTY(QString mameVersion READ getMameVersion  WRITE setMameVersion  NOTIFY mameVersionChanged)

public:
    enum DBType { DB_DATASET, DB_OWNROMS, DB_BACKUP};
    Q_ENUMS(DBType)


    explicit RomsetProfile(QObject* parent = 0) : QObject(parent), active(false), name(""), settings(), dbType(RomsetProfile::DB_DATASET), datpath(), romNumber(0), mameVersion("") {};
    explicit RomsetProfile(bool active, QString name, DBType dbType, QString dataPath, quint32 romNumber, QString mameVersion, QObject* parent = 0);
    virtual ~RomsetProfile();
    //explicit RomsetProfile(const RomsetProfile& orig);

    QSqlDatabase getDatabase(DBType type);

    bool isActive() { return active; };
    QString getName() { return name; };
    QString getDbTypeString();
    DBType  getDbType() { return dbType; };
    QString getDatPath() { return datpath; };
    quint32 getRomNumber() { return romNumber; };
    QString getMameVersion() { return mameVersion; };

    // Do not forget to declare your class to the QML system.
    static void declareQML() {
        qmlRegisterUncreatableType<RomsetProfile>("org.covolunablu.farm", 1, 0, "DBType", "DBType is not a type, just a wrapper for enums used in the program");
        //qmlRegisterUncreatableType<Enums>("Shared", 1, 0, "Enums", "Enums is not a type, just a wrapper for enums used in the program");
    }

public slots:
    void generateDBFromDat();

    void setActive(bool newValue) {this->active = newValue; emit activeChanged(newValue);};
    void setName(QString name) {this->name = name; emit nameChanged();};
    void setDbType(DBType dbType) {this->dbType = dbType; emit dbTypeChanged();};
    void setDbTypeString(QString dbType);
    void setDatPath(QString path) {this->datpath = path; emit dataPathChanged();};
    void setRomNumber(quint32 romNumber) {this->romNumber = romNumber; emit romNumberChanged();};
    void setMameVersion(QString mameVersion) {this->mameVersion = mameVersion; emit mameVersionChanged();};

signals:
    void nameChanged();
    void activeChanged(bool newValue);
    void dbTypeChanged();
    void dataPathChanged();
    void romNumberChanged();
    void mameVersionChanged();

private:
    bool active;
    QString name;
    DBType dbType;
    QString datpath;
    quint32 romNumber;
    QString mameVersion;

    QSettings settings;

};

#endif	/* ROMSETPROFILE_H */

