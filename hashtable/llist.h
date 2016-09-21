#ifndef __llist_h
#define __llist_h

#include "boolean.h"

typedef struct _lnode {
  char *k;
  int v;
  struct _lnode *next;
} lnode;

typedef struct _llist {
  lnode *first;
} llist;

llist *new_llist();
boolean llist_is_empty(llist *self);
int llist_length(llist *self);
boolean llist_contains(llist *self, char *k);
void llist_insert(llist *self, char *k, int v);
void llist_remove(llist *self, char *k);
int llist_get(llist *self, char *k);
void llist_update(llist *self, char *k, int v);

#endif
