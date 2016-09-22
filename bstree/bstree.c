#include <stdlib.h>
#include <stdio.h>
#include "bstree.h"
#include "boolean.h"
#include <assert.h>

bstnode *new_bstnode(int data) {
  bstnode *n = (bstnode *)malloc(sizeof(bstnode));
  n->key = data;
  n->left = NULL;
  n->right = NULL;
  n->next = NULL;
  n->prev = NULL;
  return n;
}

bstree *new_bstree() {
  bstree *self = (bstree *)malloc(sizeof(bstree));
  self->root = NULL;
  return self;
}

boolean bstree_is_empty(bstree *self) {
  return (self->root == NULL);
}

int bstree_size_helper(bstnode *n) {
  if (n == NULL) {
	return 0;
  } else {
	return 1 + bstree_size_helper(n->left) + bstree_size_helper(n->right);
  }
}

int bstree_size(bstree *self) {
  return bstree_size_helper(self->root);
}

boolean bstree_contains(bstree *self, int value) {
  bstnode *n = self->root; 
  while (n != NULL) {
	if (value == n->key) {
	  return TRUE;
	} else if (value < n->key) {
	  n = n->left;
	} else {
	  n = n->right;
	}
  }
  return FALSE;
}

// Where could prev be?
//     ( n is the new node)
//   * Left Child of n
//   * Some Right grandchild of the left Node
//     (Meaning you can take one left and then all rights)
//   If no left child:
//   * n's parent
//   * first grandparent that goes right
//     (meaning all of n's other grandparents are right children,
//      but prev's child that connects to n is on the right
// Whatever prev's next was will become n's next and prev's next will become n
// Then next's prev will be set to n
// Doesn't matter if prev's next is NULL

// n is always a leaf so the first case doesn't matter
// 



void bstree_insert(bstree *self, int value) {
  bstnode *n = self->root; 
  bstnode *p = NULL;
  bstnode *prev = NULL;
  int leftcount = 0;
  int rightcount = 0;

  // Find the parent node of the value.
  while (n != NULL) {
	p = n;
	if (value == n->key) {
	  return;
	} else if (value < n->key) {
	  n = n->left;
	} else {
          prev = p;
	  n = n->right;
	}
  }

  // Place the new node.
  bstnode *x = new_bstnode(value);
  if (p == NULL) {
	self->root = x;
  } else if (value < p->key) {
	p->left = x;
  } else {
	p->right = x;
  }

  x->prev = prev;
  //setting next
  if (prev != NULL){
    x->next = prev->next;
    if (x->next != NULL){
      x->next->prev = x;
    }
    prev->next = x;
  }
  // if x has no prev then either it is the root or its parent is its next
  else if( x != self->root) {
    x->next = p;
    // since prev is NULL, that means it never went right while going down 
    // the tree, so p was the preivous smallest node
    // so I can toss the current value of p->prev
    p->prev = x;
  } 


}


bstnode *bstnode_min_helper(bstnode *n){
  assert(n != NULL);
  while (n->left != NULL) {
	n = n->left;
  }
  return n;
}

bstnode *bstnode_max_helper(bstnode *n){
  assert(n != NULL);
  while (n->right != NULL) {
	n = n->right;
  }
  return n;
}

int min_helper(bstnode *n) {
  return bstnode_min_helper(n)->key;
}

void bstree_remove_helper(bstnode **px, int value) {
  if (*px == NULL) {
	return;
  } else {
	if (value == (*px)->key) {

	  // Value is at this node. Remove it.
	  if ((*px)->right == NULL) {

		// Remove this node.
		(*px) = (*px)->left;
	  } else {

		// Replace key of this node.
		int k = min_helper((*px)->right);
		(*px)->key = k;
		// Remove the replacement key's node.
		bstree_remove_helper(&((*px)->right), k);
	  }
	} else if (value < (*px)->key) {

	  // Delete in left subtree.
	  bstree_remove_helper(&((*px)->left), value);	  
	} else {

	  // Delete in right subtree.
	  bstree_remove_helper(&((*px)->right), value);	  
	}
  }
}

void bstree_remove(bstree *self, int value) {
  bstree_remove_helper(&self->root, value);
}

void bstree_output_helper(bstnode *x) {
  if (x == NULL) {
	printf(".");
  } else {
	printf("[%d ", x->key);
	bstree_output_helper(x->left);
	printf(" ");
	bstree_output_helper(x->right);
	printf("]");
  }
}

void bstree_output(bstree *self) {
  bstree_output_helper(self->root);
  printf("\n");
}

void forward_output(bstree *self){
    bstnode *n = bstnode_min_helper(self->root);
    printf("[");
    while(n != NULL) {
        if(n->next == NULL){
            //leave off comma for last element
            printf("%d",n->key);
        }
        else {
            printf("%d, ",n->key);
        }       
        n = n->next;
    }
    printf("]\n");
}

void reverse_output(bstree *self){
    bstnode *n = bstnode_max_helper(self->root);
    printf("[");
    while(n != NULL) {
        if(n->prev == NULL){
            //leave off comma for last element
            printf("%d",n->key);
        }
        else {
            printf("%d, ",n->key);
        }       
        n = n->prev;
    }
    printf("]\n");
}

/*
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

char *bstree_as_string(bstree *self) {
  char *s;
  if (bstree_is_empty(self)) {
	s = malloc(3);
	sprintf(s, "{}");
	return s;
  } else {
	int commas = bstree_length(self)-1;
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
*/
