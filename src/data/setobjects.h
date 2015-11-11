/*
 * File:   setobjects.h
 * Author: Roberto Benfatto
 *
 * Created on 5 maggio 2015, 15.33
 */

#ifndef SETOBJECTS_H
#define SETOBJECTS_H
#include <QtCore/QString>
#include "datastruct.h"

class SItem {
public:
    void setName(QString name) { this->name = name; };
    QString getName() { return this->name; };
    void setSha1(QString sha1) { this->sha1 = sha1; };
    QString getSha1() { return this->sha1; };
    void setCrc(QString crc) { this->crc = crc; };
    QString getCrc() { return this->crc; };
    void setMerge(QString name) { this->merge = name; };
    bool hasMerge() { return this->merge != nullptr; };
    QString getMerge() { return this->merge; };
    void setStatus(status_t item_status) { this->status = item_status; };
    status_t getStatus() { return this->status; };
    //Abstract methods, defines the interface of SItem
    SItem();
    SItem(QString name);
//    SItem(SItem const& copy);
    virtual item_t getType() = 0;
    virtual ~SItem() {};
private:
    QString name;
    QString sha1;
    QString crc;
    QString merge;
    status_t status;
};

class Sample: public SItem {
public:
    Sample() : SItem() {};
/*    Sample(SItem const& copy) : SItem(copy) {};
    Sample(Sample const& copy) : SItem(copy) {};*/
    Sample(QString name) : SItem(name) {};
    item_t getType() { return item_t::ITEM_SAMPLE; };
};

class Rom: public SItem {
public:
    Rom() : SItem () {};
    Rom(QString name) : SItem(name) {};
/*    Rom(SItem const& copy) : SItem(copy) {};
    Rom(Rom const& copy) : SItem(copy) { this->size = copy.size; };*/
    void setSize(int size) { this->size = size; };
    int getSize() { return size; };
    item_t getType() { return item_t::ITEM_ROM; };
private:
    int size;
};

#endif	/* SETOBJECTS_H */

