#include <stdlib.h>
#include <stdio.h>
#include "llist.h"
#include "boolean.h"

lnode *new_lnode(int data) {
  lnode *n = (lnode *)malloc(sizeof(lnode));
  n->data = data;
  n->next = NULL;
  return n;
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

boolean llist_contains(llist *self, int value) {
  lnode *n = self->first; 
  while (n != NULL) {
	if (n->data == value) {
	  return TRUE;
	}
	n = n->next;
  }
  return FALSE;
}

void llist_insert(llist *self, int value) {
  if (!llist_contains(self,value)) {
	lnode *n = new_lnode(value);
	n->next = self->first; 
	self->first = n;
  }
}

void llist_remove(llist *self, int value) {
  lnode *n = self->first; 
  lnode *p = NULL;
  while (n != NULL) {
	if (n->data == value) {
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

char *llist_as_string(llist *self) {
  char *s;
  if (llist_is_empty(self)) {
	s = malloc(3);
	sprintf(s, "{}");
	return s;
  } else {
	int commas = llist_length(self)-1;
	int chars = 0;
	
	// Compute the total length of the data items' characters.
	lnode *n = self->first;
	while (n != NULL) {
	  chars += num_chars(n->data);
	  n = n->next;
	}
	int l = 2 + (2*commas) + chars;
	s = malloc(l+1);
  
	// Fill the string.
	sprintf(s, "{");
	chars = 1;

	n = self->first;
	sprintf(s+chars, "%d", n->data);
	chars += num_chars(n->data);
	n = n->next;
	while (n != NULL) {
	  sprintf(s+chars, ", %d", n->data);
	  chars += 2 + num_chars(n->data);
	  n = n->next;
	}
	sprintf(s+chars, "}");

	// Done. Return it.
	return s;
  }
}
