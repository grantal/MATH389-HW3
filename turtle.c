#include <string.h>
#include <stdio.h>
#include <stdlib.h>            
#include "turtle.h"


turtle *new_turtle(char *name) {
    turtle *self = (turtle *)malloc(sizeof(turtle));
    self->name = (char *)malloc(strlen(name)+1);
    strcpy(self->name, name);
    self->direction = 'E';
    self->x_pos = 0;
    self->y_pos = 0;
    self->pen_up = 1;
    self->ink = 10;
    return self;
}

void forward(turtle *t) {
    switch(t->direction) {
        case 'E':
            t->x_pos++;   
            break;
        case 'S':
            t->y_pos--;   
            break;
        case 'W':
            t->x_pos--;   
            break;
        case 'N':
            t->y_pos++;   
            break;
        default:
            fprintf(stderr, "Error: Turtle %s has direction %c\nTurtle direction should be E, S, W, or N.\n",t->name, t->direction);
    }
    if (!(t->pen_up)) {
        if (t->ink <= 0) {
            t->pen_up = 1;
        }
        else{
            t->ink--;
            if (t->ink <= 0) {
                t->pen_up = 1;
            }
        }
    }
}

void turn_left(turtle *t) {
    switch(t->direction) {
        case 'E':
            t->direction = 'N';
            break;
        case 'S':
            t->direction = 'E';
            break;
        case 'W':
            t->direction = 'S';
            break;
        case 'N':
            t->direction = 'W';
            break;
        default:
            fprintf(stderr, "Error: Turtle %s has direction %c\nTurtle direction should be E, S, W, or N.\n",t->name, t->direction);
    }
}

void turn_right(turtle *t) {
    switch(t->direction) {
        case 'E':
            t->direction = 'S';
            break;
        case 'S':
            t->direction = 'W';
            break;
        case 'W':
            t->direction = 'N';
            break;
        case 'N':
            t->direction = 'E';
            break;
        default:
            fprintf(stderr, "Error: Turtle %s has direction %c\nTurtle direction should be E, S, W, or N.\n",t->name, t->direction);
    }
}

void pen_down(turtle *t){
    t->pen_up = 0;
}
void pen_up(turtle *t){ 
    t->pen_up = 1;
}
char *as_string(turtle *t){
    char *retstring = (char *)malloc(strlen(t->name)+ 100);
    sprintf(retstring, "turtle '%s' at (%d,%d) with heading %c\n", t->name,t->x_pos,t->y_pos,t->direction);
    if (!(t->pen_up)) {
        sprintf((char *)(retstring + strlen(retstring)), "drawing");
        if (t->ink == 1){
            sprintf((char *)(retstring + strlen(retstring)), " with low ink");
        }
        sprintf((char *)(retstring + strlen(retstring)), "\n");
    }
    if (t->ink <= 0) {
        sprintf((char *)(retstring + strlen(retstring)), "empty\n");
    }
    return retstring;
}
void replenish(turtle *t){
    t->ink += 10;
}

