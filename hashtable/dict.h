// Alex Grant
// Math 221
#ifndef __dict_h
#define __dict_h

#include "llist.h"

typedef struct _dict {
    llist **buckets;
    int size;
} dict;

dict *new_dict(int size);


#endif
