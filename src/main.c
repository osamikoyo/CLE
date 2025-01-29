#include <stdlib.h>
#include <math.h>

typedef struct {
    int x;
    int y;
}dote;

typedef struct {
    dote *dotes;
}field;

dote * new_dote(int x, int y) {
    dote *dotes = malloc(sizeof(dote));
    dotes->x = x;
    dotes->y = y;
    return dotes;
}

void free_dote(dote *d) {
    free(d);
}

static dote *get_line(dote *dote1, dote *dote2) {
    double distance = sqrt(pow(dote1->x - dote2->x, 2) + pow(dote1->y - dote2->y, 2));

    int steps = (dote1->x - dote2->x != 0) ? abs(dote1->x - dote2->x) : abs(dote1->y - dote2->y);

    double deltaX = (double)(dote1->x - dote2->x) / steps;
}

