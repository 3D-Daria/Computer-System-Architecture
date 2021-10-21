#ifndef HW_2_MOTORCAR_H
#define HW_2_MOTORCAR_H

#include <stdio.h>
#include <cstring>
#include "rnd.h"
#include "vehicle.h"

class Motorcar : public Vehicle {
private:
    short max_speed = 0;

public:
    virtual ~Motorcar() {}
    virtual void In(FILE* stream);
    virtual void InRnd();

    virtual void Out(FILE* stream);
};

#endif //HW_2_MOTORCAR_H
