/* 
 * File:   RomSet.cpp
 * Author: Roberto Benfatto
 * 
 * Created on 5 maggio 2015, 15.22
 */

#include "setcontainers.h"

RomSet::RomSet(QString* name, QString* parent) {
    this->name = name;
    this->parent = parent;
}

RomSet::RomSet(const RomSet& orig) {
}

RomSet::~RomSet() {
}

