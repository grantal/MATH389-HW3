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
void insert(dict *d, char *k, int v);
int look_up(dict *d, char *k);
void update(dict *d, char *k, int v);
// remove d, like remove dictionary
void removed(dict *d, char *k);


#endif
