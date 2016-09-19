#ifndef __turtle_h
#define __turtle_h

// Type description for turtle.
//

typedef struct _turtle {
    char *name;
    char direction;
    int x_pos;
    int y_pos;
    int pen_up;
    int ink;
} turtle;

// Method prototypes.
//
turtle *new_turtle(char *name);
void forward(turtle *t);
void turn_left(turtle *t);
void turn_right(turtle *t);
/*
void pen_down(turtle *t);
void pen_up(turtle *t);
char *as_string(turtle *t);
void replenish(turtle *t);
*/

#endif
