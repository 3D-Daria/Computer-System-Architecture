#include "container.h"

Container::Container(int size) {
    len_ = 0;
    size_ = size;
    storage_ = new Vehicle*[size];
}

Container::Container() {
    size_ = 0;
    len_ = 0;
    storage_ = nullptr;
}

Container::~Container() {
    Clear();
    delete[] storage_;
}

void Container::Clear() {
    for (int i = 0; i < len_; ++i){
        delete storage_[i];
    }
    len_ = 0;
}

void Container::In(char *file_name) {
    FILE* stream = fopen(file_name, "r");
    fscanf(stream, "%i", &size_);
    storage_ = new Vehicle*[size_];
    while (!feof(stream)) {
        if ((storage_[len_] = Vehicle::StaticIn(stream)) != nullptr) {
            len_ += 1;
        }
    }
    fclose(stream);
}

void Container::InRnd() {
    while (len_ < size_) {
        if ((storage_[len_] = Vehicle::StaticInRnd()) != nullptr) {
            len_ += 1;
        }
    }
}

void Container::Out(char *file_name) {
    FILE * stream = fopen(file_name, "w");
    fprintf(stream, "Container contains %i elements.\n", len_);
    for (int i = 0; i < len_; ++i) {
        fprintf(stream, "%i. ", i + 1);
        storage_[i]->Out(stream);
    }
    BubbleSort();
    fprintf(stream, "\n\n\nAfter bubble sort:\n");
    for (int i = 0; i < len_; ++i){
        fprintf(stream, "%i. ", i + 1);
        storage_[i]->Out(stream);
    }
    fclose(stream);
}

void Container::BubbleSort() {
    bool changed = true;
    for (int i = 0; (i < len_) && changed; ++i) {
        changed = false;
        for (int j = 0; j < len_ - i - 1; ++j) {
            if (storage_[j]->MaxDistance() > storage_[j + 1]->MaxDistance()) {
                auto v = storage_[j];
                storage_[j] = storage_[j + 1];
                storage_[j + 1] = v;
                changed = true;
            }
        }
    }
}