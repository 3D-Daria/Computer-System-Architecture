#ifndef HW_2_CONTAINER_H
#define HW_2_CONTAINER_H

#include "vehicle.h"

class Container {
private:
    int len_;
    Vehicle** storage_;
    int size_;

    void Clear();

public:
    Container();
    Container(int size);
    ~Container();

    void In(char *file_name);
    void InRnd();
    void Out(char *file_name);
    void BubbleSort();

};


#endif //HW_2_CONTAINER_H
