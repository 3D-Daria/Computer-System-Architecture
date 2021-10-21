#ifndef HW_2_VEHICLE_H
#define HW_2_VEHICLE_H

#include "rnd.h"
#include <stdio.h>
#include <cstring>

class Vehicle {
protected:
    static Random rnd_numbers;
    static Random rnd_keys;
    int tank_capacity = 0;
    double fuel_per_100km = 0.0;

public:
    virtual ~Vehicle() {};
    static Vehicle* StaticIn(FILE* stream);
    static Vehicle* StaticInRnd();

    virtual void In(FILE* stream) = 0;
    virtual void InRnd() = 0;

    virtual void Out(FILE* stream);

    virtual double MaxDistance();
};

#endif //HW_2_VEHICLE_H
