// Alex Grant
// Math 389
#include <stdlib.h>
#include "hash.h"
#include "dict.h"


dict *new_dict(int size){
    dict *self = (dict *)malloc(sizeof(dict));
    self->buckets = (llist **)malloc(size*sizeof(llist *));
    self->size = size;
    return self;
}

