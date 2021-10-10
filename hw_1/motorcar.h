#ifndef HW_1_MOTORCAR_H
#define HW_1_MOTORCAR_H

#include <stdio.h>
#include <cstring>
#include "rnd.h"

struct motorcar {
    short max_speed = 0;
};

void In(motorcar &mc, FILE *stream);

void InRnd(motorcar &mc);

void Out(motorcar &mc, FILE *stream);

#endif //HW_1_MOTORCAR_H
