/* 
 * File:   setobjects.cpp
 * Author: Roberto Benfatto
 * 
 * Created on 5 maggio 2015, 15.33
 */

#include "setobjects.h"

SItem::SItem() {
    this->setName(nullptr);
    this->setCrc(nullptr);
    this->setMerge(nullptr);
    this->setSha1(nullptr);
    this->setStatus(status_t::STATUS_UNKNOWN);
}

SItem::SItem(QString name) : SItem() {
    this->setName(name);
}

SItem::~SItem() {
}

