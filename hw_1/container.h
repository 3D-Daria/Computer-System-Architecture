#ifndef HW_1_CONTAINER_H
#define HW_1_CONTAINER_H

#include "vehicle.h"

struct  container {
    int cur_length;
    vehicle* cont;
};

// Инициализация контейнера
void Init(container &c, int n);

// Очистка контейнера от элементов (освобождение памяти)
void Clear(container &c);

// Ввод содержимого контейнера из указанного потока
void In(container &c, char *file_name);

// Случайный ввод содержимого контейнера
void InRnd(container &c, int size);

// Вывод содержимого контейнера в указанный поток
void Out(container &c, char *file_name);

void BubbleSort(container &c);

#endif //HW_1_CONTAINER_H
