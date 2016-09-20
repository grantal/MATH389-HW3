#ifndef __llist_h
#define __llist_h

#include "boolean.h"

typedef struct _lnode {
  int data;
  struct _lnode *next;
} lnode;

typedef struct _llist {
  lnode *first;
} llist;

llist *new_llist();
boolean llist_is_empty(llist *self);
int llist_length(llist *self);
boolean llist_contains(llist *self, int value);
void llist_insert(llist *self, int value);
void llist_remove(llist *self, int value);
char *llist_as_string(llist *self);

#endif
