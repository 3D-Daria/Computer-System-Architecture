#include "container.h"

// Инициализация контейнера
void Init(container &c, int n) {
    c.cont = (vehicle*) malloc(n * sizeof (vehicle));
    c.cur_length = 0;
}

// Очистка контейнера от элементов (освобождение памяти)
void Clear(container &c){
    free(c.cont);
    c.cur_length = 0;
}

// Ввод содержимого контейнера из указанного потока
void In(container &c, char *file_name){
    FILE *stream = fopen(file_name, "r");
    int n = -1;
    while (!feof(stream)){
        if (n == -1){
            fscanf(stream, "%i", &n);
            Init(c, n);
        }
        if (In(c.cont[c.cur_length], stream)){
            c.cur_length += 1;
        }
    }
    fclose(stream);
}

// Случайный ввод содержимого контейнера
void InRnd(container &c, int size){
    Init(c, size);
    while (c.cur_length < size){
        if (InRnd(c.cont[c.cur_length])){
            c.cur_length += 1;
        }
    }
}

// Вывод содержимого контейнера в указанный поток
void Out(container &c, char *file_name){
    FILE *stream = fopen(file_name, "w");
    fprintf(stream, "Container contains %i elements.\n", c.cur_length);
    for (int i = 0; i < c.cur_length; ++i){
        fprintf(stream, "%i. ", i + 1);
        Out(c.cont[i], stream);
    }
    BubbleSort(c);
    fprintf(stream, "\n\n\nAfter bubble sort:\n");
    for (int i = 0; i < c.cur_length; ++i){
        fprintf(stream, "%i. ", i + 1);
        Out(c.cont[i], stream);
    }
}

void BubbleSort(container &c){
    bool flag = true;
    for (int i = 0; (i < c.cur_length) && flag; ++i){
        flag = false;
        for (int j = 0; j < c.cur_length - i - 1; ++j){
            if (MaxDistance(c.cont[j]) > MaxDistance(c.cont[j + 1])){
                auto v = c.cont[j];
                c.cont[j] = c.cont[j + 1];
                c.cont[j + 1] = v;
                flag = true;
            }
        }
    }
}
