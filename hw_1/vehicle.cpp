#include "vehicle.h"

bool In(vehicle &v, FILE  *stream) {
    if (stream != nullptr) {
        int k;
        fscanf(stream, "%i", &k);
        fscanf(stream, "%i", &(v.tank_capacity));
        fscanf(stream, "%lf", &(v.fuel_per_100km));
        switch (k) {
            case 1:
                v.k = vehicle::LORRY;
                In(v.l, stream);
                return true;
            case 2:
                v.k = vehicle::AUTOBUS;
                In(v.ab, stream);
                return true;
            case 3:
                v.k = vehicle::MOTORCAR;
                In(v.mc, stream);
                return true;
            default:
                return false;
        }
    }
    return false;
}

bool InRnd(vehicle &v) {
    int k = rand() % 3 + 1;
    v.tank_capacity = Random();
    v.fuel_per_100km = Random() * 1.0 + Random() * 0.01;
    switch (k) {
        case 1:
            v.k = vehicle::LORRY;
            InRnd(v.l);
            return true;
        case 2:
            v.k = vehicle::AUTOBUS;
            InRnd(v.ab);
            return true;
        case 3:
            v.k = vehicle::MOTORCAR;
            InRnd(v.mc);
            return true;
        default:
            return false;
    }
}

void Out(vehicle &v, FILE *stream) {
    bool ok_vehicle = true;
    switch (v.k) {
        case 1:
            Out(v.l, stream);
            break;
        case 2:
            Out(v.ab, stream);
            break;
        case 3:
            Out(v.mc, stream);
            break;
        default:
            fprintf(stream, "Incorrect vehicle\n");
            ok_vehicle = false;
    }
    if (ok_vehicle){
        fprintf(stream, "tank capacity = %i litres, fuel per 100km = %f; max distance = %f\n",
                v.tank_capacity, v.fuel_per_100km, MaxDistance(v));
    }
}

double MaxDistance(vehicle &v) {
    return v.tank_capacity * 100.0 / v.fuel_per_100km;
}
