// Alex Grant
// Math 389
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

// hash function
// will need to mod by array size 
int h(char *k){

    // int probably only good for small strings
    int retval = 0;
    int i;
    for (i = 0; i < strlen(k); i++){
        // first 31 characters don't come up a lot
        // 97 is the first prime after 127-31
        retval += ((int)k[i] - 31) * (int)pow((double)97,(double)i);

    } 

    // negative numbers can't be indices
    return abs(retval);
}
