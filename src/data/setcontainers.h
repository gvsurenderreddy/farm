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
#include "setobjects.h"
#include "datastruct.h"

class ItemCollection {
    public:
        //ItemCollection();
        ItemCollection(QString name, QString parent=nullptr);
        void setName(QString name) { this->name = name; };
        QString getName() const { return this->name; };
        void setParent(QString parent) { this->parent = parent; };
        QString getParent() const { return this->parent; };
        void setStatus(status_t status) { this->set_status = set_status; };
        status_t getStatus() const { return this->set_status; };
        virtual set_t getType() const = 0;
        virtual ~ItemCollection();
        QHash<QString,SItem>::iterator getItemIteratorBegin() { return itemlist.begin(); };
        QHash<QString,SItem>::iterator getItemIteratorEnd() { return itemlist.end(); };
        bool addItem(SItem item);
        bool delItem(SItem item);
        bool delItem(QString item);
        bool hasItem(SItem item);
    private:
        QString name;
        QString parent;
        QHash<QString, SItem> itemlist;
        status_t set_status;
};

class Game : public ItemCollection {
    public:
        Game(QString name, QString parent=nullptr) : ItemCollection(name, parent) {};
        QString getDescription() const {
            return description;
        }
        void setDescription(QString description) {
            this->description = description;
        }
        QString getManufacturer() const {
            return manufacturer;
        }
        void setManufacturer(QString manufacturer) {
            this->manufacturer = manufacturer;
        }
        int getYear() const {
            return year;
        }
        void setYear(int year) {
            this->year = year;
        }
        virtual set_t getType() { return set_t::TYPE_GAME; };
        virtual ~Game();
    private:
        int year;
        QString description;
        QString manufacturer;
    
};

class Bios : public Game {
    public:
        Bios(QString name, QString parent=nullptr) : Game(name, parent) {};
        set_t getType() { return set_t::TYPE_BIOS; };
        virtual ~Bios();
};

class Mechanical : public ItemCollection {
    public:
        Mechanical(QString name, QString parent=nullptr) : ItemCollection(name, parent) {};
        set_t getType() { return set_t::TYPE_MECHANICAL; };
        virtual ~Mechanical();
};

#endif	/* SETCONTAINERS_H */
