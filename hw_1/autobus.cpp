#include "autobus.h"

void In(autobus &ab, FILE *stream) {
    fscanf(stream, "%i", &(ab.passenger_capacity));
}

void InRnd(autobus &ab) {
    ab.passenger_capacity = Random();
}

void Out(autobus &ab, FILE *stream) {
    fprintf(stream, "It is autobus: passenger capacity = %i, ", ab.passenger_capacity);
}
