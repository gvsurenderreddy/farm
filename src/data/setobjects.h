/* 
 * File:   setobjects.h
 * Author: Roberto Benfatto
 *
 * Created on 5 maggio 2015, 15.33
 */

#ifndef SETITEM_H
#define	SETITEM_H
#include <QtCore/QString>
#include "datastruct.h"
class SItem {
public:
    SItem(QString name);
    SItem(const SItem& orig);
    void setName(QString* name);
    void setType(item_t item_type);
    void setStatus(status_t item_status);
    QString getName();
    item_t getType();
    status_t getStatus();
    virtual ~SItem();
private:
    QString name;
    QString sha1;
    QString crc;
    item_t item_type;
    status_t status;
};

class Sample: public SItem {
public:
    Sample(QString name);;
    virtual ~Sample();
};

class Rom: public SItem {
public:
    Rom(QString name);;
    virtual ~Rom();
private:
    int size;
};

#endif	/* SETITEM_H */

