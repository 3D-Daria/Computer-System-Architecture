#ifndef HW_1_VEHICLE_H
#define HW_1_VEHICLE_H

#include "lorry.h"
#include "autobus.h"
#include "motorcar.h"

struct vehicle {
    // значения ключей для каждой из фигур
    enum key {LORRY = 1, AUTOBUS, MOTORCAR};
    key k; // ключ
    int tank_capacity = 0;
    double fuel_per_100km = 0.0;
    // используемые альтернативы
    union { // используем простейшую реализацию
        lorry l;
        autobus ab;
        motorcar mc;
    };
};

bool In( vehicle &v, FILE *stream);

bool InRnd(vehicle &v);

void Out(vehicle &v, FILE *stream);

double MaxDistance(vehicle &v);

#endif //HW_1_VEHICLE_H
