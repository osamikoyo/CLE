#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#define SIZE_WIDTH 120
#define SIZE_HEIGHT 50
#define

typedef struct {
    int x;
    int y;
}dote;

typedef struct {
    dote *field;
    bool color;
}no_animate_render;

dote * new_dote(int x, int y) {
    dote *dotes = malloc(sizeof(dote));
    dotes->x = x;
    dotes->y = y;
    return dotes;
}

static dote *new_dotes(int count) {
    dote *dotes = calloc(count, sizeof(dote));
    return dotes;
}

void free_dote(dote *d) {
    free(d);
}

static dote *get_line(dote *dote1, dote *dote2) {
    double distance = sqrt(pow(dote1->x - dote2->x, 2) + pow(dote1->y - dote2->y, 2));

    int steps = (dote1->x - dote2->x != 0) ? abs(dote1->x - dote2->x) : abs(dote1->y - dote2->y);

    double deltaX = (double)(dote1->x - dote2->x) / steps;
    double deltaY = (double)(dote1->y - dote2->y) / steps;
    dote *line_dotes = new_dotes(steps);

    for (int i =0; i <= steps; i++) {
        double x = dote1->x + i * deltaX;
        double y = dote1->y + i * deltaY;
        dote *d = new_dote((int)x, (int)y);
        *(line_dotes + i) = *d;
        free_dote(d);
    }

    return line_dotes;
}

void render(no_animate_render *render) {
    for (int i = 0; i < SIZE_WIDTH; i++) {
        for (int j = 0; j < SIZE_HEIGHT; j++) {
            if ((render->field + i)->x == i && (render->field + j)->y == j){
                printf("#");
            } else {
                printf(" ");
            }
        }
    }
}

int main() {

}