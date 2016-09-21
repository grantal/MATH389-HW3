// Alex Grant
// Math 389
#include <stdio.h>
#include "llist.h"

// compile with:
// gcc -o llist test_llist.c llist.c -lm

int main(){
    llist *l = new_llist();
    
    printf("Is empty? %d\n", llist_is_empty(l));  
    printf("Length: %d\n", llist_length(l));  
    
    llist_insert(l, "test", 20);

    printf("Length: %d\n", llist_length(l));  
    
    printf("Is there a value at '%s'? %d\n", "hello", llist_contains(l,"hello"));

    llist_insert(l, "hello", 45);

    printf("Is there a value at '%s'? %d\n", "hello", llist_contains(l,"hello"));
    
    printf("Value at '%s': %d\n", "test", llist_get(l,"test")); 
    printf("Value at '%s': %d\n", "hello", llist_get(l,"hello")); 
    
    llist_update(l, "test", 32);
    
    printf("Value at '%s': %d\n", "test", llist_get(l,"test")); 
    
    printf("Is empty? %d\n", llist_is_empty(l));  
    printf("Length: %d\n", llist_length(l));  

    llist_remove(l, "hello");
    printf("Length: %d\n", llist_length(l));  
    printf("Is there a value at '%s'? %d\n", "hello", llist_contains(l,"hello"));
    printf("Value at '%s': %d\n", "hello", llist_get(l,"hello")); 


}
