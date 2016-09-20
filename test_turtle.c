// Alex Grant
// Math 389
#include <stdio.h>
#include <string.h>
#include "turtle.h"


// compile with gcc -o turt test_turtle.c turtle.c -lm

const int MAX_TURTLES = 10;

int main(){
    char turtname[100];
    char action[100];
    // to store turtles to act on
    turtle *turtles[10] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};

    do{
        printf(">>>> ");
        // this has some weird behavior if you don't input exactly 2 strings,
        // but since this is just for my own testing, I'm okay with that
        scanf("%s %s", turtname, action);
        
        int i;
        for (i=0;i < MAX_TURTLES; i++){
            // There should be no turtles after the first empty spot in the array
            // They should all be at the front
            if (turtles[i] == NULL) {
                if (strcmp(action, "create") == 0){
                    turtles[i] = new_turtle(turtname); 
                    printf("Done.\n");
                } 
                break;
            }
            else if (strcmp(turtles[i]->name, turtname) == 0){
                turtle *t = turtles[i];
                if(strcmp(action,"forward") == 0){
                    forward(t);
                    printf("Done.\n");
                }       
                else if(strcmp(action,"create") == 0){
                    printf("This turtle already exists!\n");
                }
                else if(strcmp(action,"report") == 0){
                    printf("%s", as_string(t));
                }
                else if(strcmp(action,"left") == 0){
                    turn_left(t);
                    printf("Done.\n");
                }
                else if(strcmp(action,"right") == 0){
                    turn_right(t);
                    printf("Done.\n");
                }
                else if(strcmp(action,"pendown") == 0){
                    pen_down(t);
                    printf("Done.\n");
                }
                else if(strcmp(action,"penup") == 0){
                    pen_up(t);
                    printf("Done.\n");
                }
                else if(strcmp(action,"replenish") == 0){
                    replenish(t);
                    printf("Done.\n");
                }
                else{
                    printf("unrecognized command\n");
                }
                break;
            }
        }

    } while(strcmp(action, "q"));
    
}
