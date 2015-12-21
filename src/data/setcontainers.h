/* 
 * File:   RomSet.h
 * Author: Roberto Benfatto
 *
 * Created on 5 maggio 2015, 15.22
 */

#ifndef SETCONTAINERS_H
#define	SETCONTAINERS_H
#include <QtCore/QString>
#include <QtCore/QHash>
#include <QtSql/qsqldatabase.h>
#include "setobjects.h"
#include "datastruct.h"

class ItemCollection {
    public:
        ItemCollection();
        ItemCollection(QString name);
        void setName(QString name) { this->name = name; }
        QString getName() const { return this->name; }
        void setParent(QString parent) { this->parent = parent; }
        QString getParent() const { return this->parent; }
        void setStatus(status_t status) { this->set_status = set_status; }
        status_t getStatus() const { return this->set_status; }
        QString getDescription() const { return description;  }
        void setDescription(QString description) { this->description = description; }
        QString getManufacturer() const { return manufacturer; }
        void setManufacturer(QString manufacturer) { this->manufacturer = manufacturer; }
        int getYear() const { return year; }
        void setYear(int year) { this->year = year; }
        virtual set_t getType() = 0;
//        virtual bool writeToDb(QSqlDatabase &db) const = 0;
        virtual ~ItemCollection() {};
        QHash<QString,SItem*>::iterator getItemIteratorBegin() { return itemlist.begin(); };
        QHash<QString,SItem*>::iterator getItemIteratorEnd() { return itemlist.end(); };
        bool addItem(SItem* item);
        bool delItem(SItem* item);
        bool delItem(QString item);
        bool hasItem(SItem* item);
        int getItemQuantity() { return this->itemlist.size(); };
    private:
        QString name;
        QString parent;
        QString description;
        QString manufacturer;
        int year;
        QHash<QString, SItem*> itemlist;
        status_t set_status;
};

class Device : public ItemCollection {
    public:
        Device(QString name) : ItemCollection(name) {};
        set_t getType() { return TYPE_DEVICE; };
};

class Game : public ItemCollection {
    public:
        Game(QString name) : ItemCollection(name) {};
        virtual set_t getType() { return TYPE_GAME; };
        //virtual bool writeToDb(QSqlDatabase& db) {};
    
};

class Bios : public Game {
    public:
        Bios(QString name) : Game(name) {};
        set_t getType() { return TYPE_BIOS; };
        //virtual bool writeToDb(QSqlDatabase& db) {};
};

class Mechanical : public ItemCollection {
    public:
        Mechanical(QString name) : ItemCollection(name) {};
        virtual set_t getType() { return TYPE_MECHANICAL; };
        //virtual bool writeToDb(QSqlDatabase& db) {};
};

#endif	/* SETCONTAINERS_H */
