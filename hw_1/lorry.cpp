#include "lorry.h"

void In(lorry &l, FILE *stream) {
    fscanf(stream, "%i", &(l.lift_capacity));
}

void InRnd(lorry &l) {
    l.lift_capacity = Random();
}

void Out(lorry &l, FILE *stream) {
    fprintf(stream, "It is lorry: lift capacity = %i, ", l.lift_capacity);
}
