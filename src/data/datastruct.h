/* 
 * File:   datastruct.h
 * Author: Roberto Benfatto
 *
 * Created on 5 maggio 2015, 15.23
 */

#ifndef DATASTRUCT_H
#define	DATASTRUCT_H

enum chk_error_t {
    WRONG_NAME,
    WRONG_CHECKSUM,
    WRONG_SIZE,
    WRONG_CRC,
    UNFIXABLE
};

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
    TYPE_BIOS=0,
    TYPE_GAME=1,
    TYPE_MECHANICAL=2,
    TYPE_DEVICE=3,
    TYPE_OTHER=4
};

#endif	/* DATASTRUCT_H */
