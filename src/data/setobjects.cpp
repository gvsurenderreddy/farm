/*
 * File:   setobjects.cpp
 * Author: Roberto Benfatto
 *
 * Created on 5 maggio 2015, 15.33
 */

#include "setobjects.h"

SItem::SItem()
  : name(),
    crc(),
    merge(),
    sha1(),
    status(status_t::STATUS_UNKNOWN)
{

}

SItem::SItem(QString name) : SItem() {
    this->setName(name);
}

SItem::~SItem() {
}

item_t SItem::getType() const {
    return ITEM_OTHER;
}

