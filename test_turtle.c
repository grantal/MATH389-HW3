// Alex Grant
// Math 389
#include <stdio.h>
#include <string.h>

int main(){
    char turtname[100];
    char action[100];
    do{
        printf(">>>> ");
        scanf("%s %s", turtname, action);

    } while(strcmp(turtname, "q"));
    
}
