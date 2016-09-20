// Alex Grant
// Math 389
#include <stdio.h>
#include "hash.h"

int main(){
    printf("%s's hash is %d\n", "hello",h("hello"));
    printf("%s's hash is %d\n", "jimfix",h("jimfix"));
    printf("%s's hash is %d\n", "bob",h("bob"));
    printf("%s's hash is %d\n", "alex grant",h("alex grant"));
    printf("%s's hash is %d\n", "jfsljsdkjfl",h("jfsljsdkjfl"));
    printf("%s's hash is %d\n", "my name is jeff.",h("my name is jeff."));
}
