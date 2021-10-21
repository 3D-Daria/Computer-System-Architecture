#ifndef HW_2_LORRY_H
#define HW_2_LORRY_H

#include <stdio.h>
#include <cstring>
#include "rnd.h"
#include "vehicle.h"

class Lorry : public Vehicle {
private:
    int lift_capacity = 0;

public:
    virtual ~Lorry() {}
    virtual void In(FILE* stream);
    virtual void InRnd();

    virtual void Out(FILE* stream);
};

#endif //HW_2_LORRY_H
