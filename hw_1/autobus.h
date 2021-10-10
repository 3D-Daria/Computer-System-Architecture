#ifndef HW_1_AUTOBUS_H
#define HW_1_AUTOBUS_H

#include <stdio.h>
#include <cstring>
#include "rnd.h"

struct autobus {
    short passenger_capacity = 0;
};

void In(autobus &ab, FILE *stream);

void InRnd(autobus &ab);

void Out(autobus &ab, FILE *stream);

#endif //HW_1_AUTOBUS_H
