#ifndef HW_2_BUS_H
#define HW_2_BUS_H

#include <stdio.h>
#include <cstring>
#include "rnd.h"
#include "vehicle.h"

class Bus : public Vehicle{
private:
    short passenger_capacity = 0;

public:
    virtual ~Bus() {}
    virtual void In(FILE* stream);
    virtual void InRnd();

    virtual void Out(FILE* stream);
};

#endif //HW_2_BUS_H
