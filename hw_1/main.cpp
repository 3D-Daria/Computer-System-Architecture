#include <stdio.h>
#include <cstdlib> // для функций rand() и srand()
#include <ctime>   // для функции time()
#include <cstring>
#include "container.h"


void errMessage1() {
    printf("incorrect command line!\n"
            "  Waited:\n"
            "     command -f infile outfile\n"
            "  Or:\n"
            "     command -n number outfile\n");
}

void errMessage2() {
    printf("incorrect qualifier value!\n"
            "  Waited:\n"
            "     command -f infile outfile\n"
            "  Or:\n"
            "     command -n number outfile\n");
}


int main(int argc, char* argv[]) {
    if (argc != 4){
        errMessage1();
        return 1;
    }

    printf("Start\n");
    container c;
    auto timer = clock();

    if(!strcmp(argv[1], "-f")) {
        In(c, argv[2]);
    }
    else if(!strcmp(argv[1], "-n")) {
        auto size = atoi(argv[2]);
        if((size < 1) || (size > 10000)) {
            printf("incorrect number of figures = %i. Set 0 < number <= 10000\n", size);
            return 3;
        }
        // системные часы в качестве инициализатора
        srand(static_cast<unsigned int>(time(0)));
        // Заполнение контейнера генератором случайных чисел
        InRnd(c, size);
    }
    else {
        errMessage2();
        return 2;
    }


    Out(c, argv[3]);
    Clear(c);
    timer = clock() - timer;
    printf("Consumed time: %lf seconds\n", timer * 1.0 / CLOCKS_PER_SEC);
    printf("Stop");

    return 0;
}
