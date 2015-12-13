//
// Created by stengun on 11/11/15.
//

#ifndef FARM_POPULATOR_H
#define FARM_POPULATOR_H


#include <QtCore/qobject.h>
#include <QtCore/qrunnable.h>
#include <src/utils/Datparser.h>
#include <src/data/DBGameSets.h>
#include <QtCore/qthread.h>

/**
 * Populator class that parses an xml datfile and converts it in a more efficent SQL database.
 * This class is actually the base worker that's responsible for progress, start and stop of other subworkers.
 */
class Populator : public QObject {
    Q_OBJECT
    QThread th_parser;
    QThread th_db;
signals:
    void progressChanged(int processed);
    void progressRangeChanged(int a, int b);
    void finished();
    void started(int total);

public slots:
    void run(); //implement this for the base functionality as a thread.
    void stop(); // this actually kills the worker and its childrens

public:
    Populator(QString datpath, QString dbpath);
    Populator();
    ~Populator();
    void setDatPath(QString path) { this->xmlpath = path; };
    QString getDatPath() { return this->xmlpath; };
    void setDbPath(QString path) { this->dbpath = path; }; // maybe I have to remove this
    QString getDbPath() { return this->dbpath; }
private:
    QString xmlpath, dbpath;
    Datparser* parser;
    DBGameSets* db;
    bool beginParse();
    int countTotalSets(); //maybe not useful
};


#endif //FARM_POPULATOR_H
