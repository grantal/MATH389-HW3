#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bstree.h"

// compile with:
// gcc -o bstree bstree.c bstree_test.c

int main() {
  char command[100];
  bstree *t = new_bstree();
  do {
	// Report contents.
	bstree_output(t);

	// Request action.
	printf("Operation [insert, remove, check, quit]? ");
	int end = scanf("%s", command);
	if (end <= 0) {
	  printf("\n");
	  sprintf(command,"quit");
	} 

	// Handle request.
	if (strcmp(command, "quit") != 0) {
	  if (strcmp(command, "insert") == 0) {
		int value;
		scanf("%d", &value);
		bstree_insert(t, value);
		printf("Done.\n");
	  } else if (strcmp(command, "remove") == 0) {
		int value;
		scanf("%d", &value);
		bstree_remove(t, value);
		printf("Done.\n");
	  } else if (strcmp(command, "check") == 0) {
		int value;
		scanf("%d", &value);
		if (bstree_contains(t, value)) {
		  printf("Found.\n");
		} else {
		  printf("Not found.\n");
		}
	  } else if (strcmp(command, "forwardout") == 0) {
                forward_output(t); 
	  } else if (strcmp(command, "reverseout") == 0) {
                reverse_output(t); 
	  } else {
		printf("Come again????\n");
	  }
	}
  } while (strcmp(command, "quit") != 0);
}
