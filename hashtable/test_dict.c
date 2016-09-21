// Alex Grant
// Math 389
#include <stdio.h>
#include "dict.h"
#include "llist.h"

// compile with:
// gcc -o dict test_dict.c dict.c llist.c hash.c -lm

int main(){
    dict *d = new_dict(47);
    printf("Size: %d\n", d->size);

    insert(d, "hi", 52); 

    printf("Element at '%s': %d\n", "hi", look_up(d,"hi"));
    printf("Element at '%s': %d\n", "kdhsdj", look_up(d,"kdhsdj"));
    
    update(d, "hi", 75); 
    insert(d, "kdhsdj", 35); 
    printf("Element at '%s': %d\n", "hi", look_up(d,"hi"));
    printf("Element at '%s': %d\n", "kdhsdj", look_up(d,"kdhsdj"));

    removed(d, "kdhsdj"); 
    printf("Element at '%s': %d\n", "kdhsdj", look_up(d,"kdhsdj"));
    insert(d, "kdhsdj", 42); 
    printf("Element at '%s': %d\n", "kdhsdj", look_up(d,"kdhsdj"));
}
