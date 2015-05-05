/* 
 * File:   setobjects.cpp
 * Author: Roberto Benfatto
 * 
 * Created on 5 maggio 2015, 15.33
 */

#include "setobjects.h"

SItem::SItem(QString name) {
    this->name = name;
}

SItem::SItem(const SItem& orig) {
}

SItem::~SItem() {
}

Sample::Sample(QString name) : SItem(name) {
}

Rom::Rom(QString name) : SItem(name) {
}

