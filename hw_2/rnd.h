#ifndef HW_2_RND_H
#define HW_2_RND_H

#include <cstdlib>
#include <ctime>

class Random {
private:
    int first;
    int last;

public:
    Random(int f, int l) {
        if(f <= l) {
            first = f;
            last = l;
        } else {
            first = l;
            last = f;
        }

        srand(static_cast<unsigned int>(time(0)));
    }

    int Get() {
        return rand() % (last - first + 1) + first;
    }
};

#endif //HW_2_RND_H
