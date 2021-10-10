#ifndef HW_1_LORRY_H
#define HW_1_LORRY_H

#include <stdio.h>
#include <cstring>
#include "rnd.h"

struct lorry{
    int lift_capacity = 0;
};

void In(lorry &l, FILE *stream);

void InRnd(lorry &l);

void Out(lorry &l, FILE *stream);

#endif //HW_1_LORRY_H
