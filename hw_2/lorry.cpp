#include "lorry.h"

void Lorry::In(FILE *stream) {
    this->Vehicle::In(stream);
    fscanf(stream, "%i", &lift_capacity);
}

void Lorry::InRnd() {
    this->Vehicle::InRnd();
    lift_capacity = Vehicle::rnd_numbers.Get();
}

void Lorry::Out(FILE *stream) {
    fprintf(stream, "It is a lorry: lift capacity = %i, ", lift_capacity);
    this->Vehicle::Out(stream);
}