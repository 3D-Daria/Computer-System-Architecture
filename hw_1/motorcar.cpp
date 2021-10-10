#include "motorcar.h"

void In (motorcar &mc, FILE *stream) {
    fscanf(stream, "%i", &(mc.max_speed));
}

void InRnd(motorcar &mc) {
    mc.max_speed = Random();
}

void Out(motorcar &mc, FILE *stream) {
    fprintf(stream, "It is motorcar: max speed = %i, ", mc.max_speed);
}
