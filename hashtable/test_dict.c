// Alex Grant
// Math 389
#include <stdio.h>
#include "dict.h"
#include "llist.h"

// compile with:
// gcc -o dict test_dict.c dict.c llist.c hash.c -lm

int main(){
    dict *d = new_dict(47);
    printf("%d\n", d->size);

    llist *l = new_llist();
    
    printf("Is empty? %d\n", llist_is_empty(l));  
    printf("Length: %d\n", llist_length(l));  
    
    

}
