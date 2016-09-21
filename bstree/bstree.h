#ifndef __bstree_h
#define __bstree_h

#include "boolean.h"

typedef struct _bstnode {
  int key;
  struct _bstnode *left;
  struct _bstnode *right;
} bstnode;

typedef struct _bstree {
  bstnode *root;
} bstree;

bstree *new_bstree();
boolean bstree_is_empty(bstree *self);
int bstree_size(bstree *self);
boolean bstree_contains(bstree *self, int value);
void bstree_insert(bstree *self, int value);
void bstree_remove(bstree *self, int value);
// char *bstree_as_string(bstree *self);
void bstree_output(bstree *self);

#endif
