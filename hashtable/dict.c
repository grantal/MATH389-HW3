// Alex Grant
// Math 389
#include <stdlib.h>
#include "hash.h"
#include "llist.h"
#include "dict.h"


dict *new_dict(int size){
    dict *self = (dict *)malloc(sizeof(dict));
    self->buckets = (llist **)malloc(size*sizeof(llist *));
    self->size = size;
    // sets the buckets to NULL
    int i;
    for (i = 0; i < size; i++){
        self->buckets[i]=NULL;
    }
    return self;
}

// inserts into dict
void insert(dict *d, char *k, int v){
    int i = h(k) % d->size;
    if (d->buckets[i] == NULL){
        d->buckets[i] = new_llist();
    } 
    llist_insert(d->buckets[i], k, v); 
}

// looks up element
int look_up(dict *d, char *k){
    int i = h(k) % d->size;
    if (d->buckets[i] == NULL){
        return -1;
    }
    else {
        return llist_get(d->buckets[i], k);
    }
}

// updates an element
void update(dict *d, char *k, int v){
    int i = h(k) % d->size;
    llist_update(d->buckets[i], k, v);
}

// removes an element
void removed(dict *d, char *k){
    int i = h(k) % d->size;
    llist_remove(d->buckets[i], k);
    // if k was the only element in this bucket, delete this bucket
    if(llist_is_empty(d->buckets[i])){
        free(d->buckets[i]);
        d->buckets[i] = NULL;
    }
}

