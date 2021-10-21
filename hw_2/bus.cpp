#include "bus.h"

void Bus::In(FILE *stream) {
    this->Vehicle::In(stream);
    fscanf(stream, "%i", &passenger_capacity);
}

void Bus::InRnd() {
    this->Vehicle::InRnd();
    passenger_capacity = Vehicle::rnd_numbers.Get();
}

void Bus::Out(FILE *stream) {
    fprintf(stream, "It is a bus: passenger capacity = %i, ", passenger_capacity);
    this->Vehicle::Out(stream);
}