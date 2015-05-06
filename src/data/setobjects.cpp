/* 
 * File:   setobjects.cpp
 * Author: Roberto Benfatto
 * 
 * Created on 5 maggio 2015, 15.33
 */

#include "setobjects.h"

SItem::SItem(QString* name) {
    this->setName(name);
    this->setCrc(NULL);
    this->setMerge(NULL);
    this->setSha1(NULL);
    this->setStatus(status_t.STATUS_UNKNOWN);
}

SItem::~SItem() {
    delete this->name;
    delete this->crc;
    delete this->merge;
    delete this->sha1;
}

