/* 
 * File:   RomSet.h
 * Author: Roberto Benfatto
 *
 * Created on 5 maggio 2015, 15.22
 */

#ifndef ROMSET_H
#define	ROMSET_H
#include <QtCore/QString>
#include <QtCore/QList>
#include "setobjects.h"
#include "datastruct.h"
class RomSet {
public:
    RomSet(QString* name, QString* parent=NULL);
    
    RomSet(const RomSet& orig);
    virtual ~RomSet();
private:
    QString* name;
    QString* parent;
    QString* cloneof;
    QList<SItem*>* romlist;
    QList<SItem*>* sharedlist;
    QList<SItem*>* biosroms;
    set_t set_type;
    status_t set_status;
};

#endif	/* ROMSET_H */

