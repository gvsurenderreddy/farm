/* 
 * File:   datastruct.h
 * Author: Roberto Benfatto
 *
 * Created on 5 maggio 2015, 15.24
 */

#ifndef DATASTRUCT_H
#define	DATASTRUCT_H

enum status_t {
    STATUS_BADDUMP,
    STATUS_NODUMP,
    STATUS_GOOD,
    STATUS_UNKNOWN
};

enum item_t {
    ITEM_ROM,
    ITEM_CHD,
    ITEM_SAMPLE,
    ITEM_OTHER
};

enum set_t {
    TYPE_BIOS,
    TYPE_GAME,
    TYPE_MECHANICAL,
    TYPE_OTHER
};

#endif	/* DATASTRUCT_H */
