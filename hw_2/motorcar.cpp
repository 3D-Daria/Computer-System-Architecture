#include "motorcar.h"

void Motorcar::In(FILE *stream) {
    this->Vehicle::In(stream);
    fscanf(stream, "%i", &max_speed);
}

void Motorcar::InRnd() {
    this->Vehicle::InRnd();
    max_speed = Vehicle::rnd_numbers.Get();
}

void Motorcar::Out(FILE *stream) {
    fprintf(stream, "It is a motorcar: max speed = %i, ", max_speed);
    this->Vehicle::Out(stream);
}