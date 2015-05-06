/* 
 * File:   RomSet.h
 * Author: Roberto Benfatto
 *
 * Created on 5 maggio 2015, 15.22
 */

#ifndef SETCONTAINERS_H
#define	SETCONTAINERS_H
#include <QtCore/QString>
#include <QtCore/QList>
#include "setobjects.h"
#include "datastruct.h"

class ItemCollection {
    public:
        //ItemCollection();
        ItemCollection(QString* name, QString* parent=NULL);
        void setName(QString* name) { this->name = name; };
        QString* getName() { return this->name; };
        void setParent(QString* parent) { this->parent = parent; };
        QString* getParent() { return this->parent; };
        void setStatus(status_t status) { this->set_status = set_status; };
        status_t getStatus() { return this->set_status; };
        virtual set_t getType() const = 0;
        virtual ~ItemCollection();
        bool addItem(SItem item);
        bool delItem(SItem item);
        bool delItem(QString item);
        bool hasItem(SItem item);
    private:
        QString* name;
        QString* parent;
        QHash<QString, SItem> itemlist;
        status_t set_status;
};

class Bios : public ItemCollection {
    public:
        Bios(QString* name, QString* parent=NULL) : ItemCollection(name, parent) {};
        set_t getType() { return set_t.TYPE_BIOS; };
        virtual ~Bios();
};

class Game : public ItemCollection {
    public:
        Game(QString* name, QString* parent=NULL) : ItemCollection(name, parent) {};
        set_t getType() { return set_t.TYPE_GAME; };
        virtual ~Game();
};

class Mechanical : public ItemCollection {
    public:
        Mechanical(QString* name, QString* parent=NULL) : ItemCollection(name, parent) {};
        set_t getType() { return set_t.TYPE_MECHANICAL; };
        virtual ~Mechanical();
};

#endif	/* SETCONTAINERS_H */

