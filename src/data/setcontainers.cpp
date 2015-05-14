/* 
 * File:   RomSet.cpp
 * Author: Roberto Benfatto
 * 
 * Created on 5 maggio 2015, 15.22
 */

#include <qt/QtCore/qhash.h>
#include "setcontainers.h"

ItemCollection::ItemCollection(QString name, QString parent) {
    this->setName(name);
    this->setParent(parent);
    this->setStatus(status_t::STATUS_UNKNOWN);
    this->itemlist = QHash<QString, SItem>();
}

ItemCollection::~ItemCollection() {
}

/**
 * Adds an item to this collection.
 * @param item The item we want to add inside this collection.
 * @return Returns true if an item was actually inserted into this collection.
 * If the item is present, this function returns false.
 */
bool ItemCollection::addItem(SItem item) {
    if(this->itemlist.find(item.getSha1()) == this->itemlist.end()) return false;
    this->itemlist.insert(item.getSha1(), item);
    return true;
}
/**
 * Removes an item of this collection.
 * @param item The item we want to remove.
 * @return Returns true if the item was removed, else it will return false.
 */
bool ItemCollection::delItem(QString item) {
    if(this->itemlist.find(item) != this->itemlist.end()) return false;
    this->itemlist.remove(item);
    return true;
}

/**
 * Removes an item of this collection.
 * @param item The unique identifier for the item we want to remove.
 * @return Returns true if the item was removed, else it will return false.
 */
bool ItemCollection::delItem(SItem item) {
    return this->delItem(item.getSha1());
}

/**
 * Checks if an item is contained inside this collection.
 * @param item The item we want to find inside the container.
 * @return Returns true if the item is present, otherwise it will return false.
 */
bool ItemCollection::hasItem(SItem item) {
    return this->itemlist.find(item.getSha1()) != this->itemlist.end();
}
