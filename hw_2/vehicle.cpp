#include "lorry.h"
#include "bus.h"
#include "motorcar.h"

Random Vehicle::rnd_numbers(1, 100);
Random Vehicle::rnd_keys(1, 3);

Vehicle* Vehicle::StaticIn(FILE *stream) {
    int key;
    fscanf(stream, "%i", &key);
    Vehicle* v;
    switch (key) {
        case 1:
            v = new Lorry();
            break;
        case 2:
            v = new Bus();
            break;
        case 3:
            v = new Motorcar();
            break;
        default:
            return nullptr;
    }

    v->In(stream);
    return v;
}

Vehicle* Vehicle::StaticInRnd() {
    auto key = Vehicle::rnd_keys.Get();
    Vehicle* v = nullptr;
    switch (key) {
        case 1:
            v = new Lorry();
            break;
        case 2:
            v = new Bus();
            break;
        case 3:
            v = new Motorcar();
            break;
    }

    v->InRnd();
    return v;
}

void Vehicle::In(FILE *stream) {
    fscanf(stream, "%i", &tank_capacity);
    fscanf(stream, "%lf", &fuel_per_100km);
}

void Vehicle::InRnd() {
    tank_capacity = Vehicle::rnd_numbers.Get();
    fuel_per_100km = Vehicle::rnd_numbers.Get() * 0.01 + Vehicle::rnd_numbers.Get();
}

void Vehicle::Out(FILE* stream) {
    fprintf(stream, "tank capacity = %i litres, fuel per 100km = %f; max distance = %f\n",
            tank_capacity, fuel_per_100km, MaxDistance());
}

double Vehicle::MaxDistance() {
    return tank_capacity * 100.0 / fuel_per_100km;
}