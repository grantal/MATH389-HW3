#include <stdlib.h>
#include <stdio.h>
#include "llist.h"
#include "boolean.h"

lnode *new_lnode(char *k, int v) {
  lnode *n = (lnode *)malloc(sizeof(lnode));
  n->k = k;
  n->v = v;
  n->next = NULL;
  return n;
}

// helper function that gets lnode with key k
lnode *get_lnode(llist *self, char *k) {
  lnode *n = self->first; 
  while (n != NULL) {
	if (strcmp(n->k, k) == 0) {
	  return n;
	}
	n = n->next;
  }
  return NULL;
}

llist *new_llist() {
  llist *self = (llist *)malloc(sizeof(llist));
  self->first = NULL;
  return self;
}

boolean llist_is_empty(llist *self) {
  return (self->first == NULL);
}

int llist_length(llist *self) {
  int l = 0;
  lnode *n = self->first;
  while (n != NULL) {
	n = n->next;
	l++;
  }
  return l;
}

boolean llist_contains(llist *self, char *k) {
  lnode *n = get_lnode(self, k); 
  return n != NULL;
}

void llist_insert(llist *self, char *k, int v) {
  if (!llist_contains(self,k)) {
	lnode *n = new_lnode(k,v);
	n->next = self->first; 
	self->first = n;
  }
}

void llist_remove(llist *self, char* k) {
  lnode *n = self->first; 
  lnode *p = NULL;
  while (n != NULL) {
	if (strcmp(n->k, k) == 0) {
	  if (p == NULL) {
		// Remove from the front.
		self->first = self->first->next;
	  } else {
		// Remove from one of the other positions.
		p->next = n->next;
	  }
	  return;
	}
	p = n;
	n = n->next;
  }
}

int num_chars(int d) {
  int l = 1;
  if (d < 0) {
	l = 2;
	d = -d;
  }
  while (d > 9) {
	l++;
	d = d / 10;
  }
  return l;
}



int llist_get(llist *self, char *k){
    lnode *n = get_lnode(self, k);
    if (n != NULL) {
        return n->v;
    }
    else {
        return -1;
    }
}

void llist_update(llist *self, char *k, int v) {
    lnode *n = get_lnode(self, k);
    if (n != NULL) {
        n->v = v;
    }
}

