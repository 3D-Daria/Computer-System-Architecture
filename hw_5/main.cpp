#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

const int queueSize = 10;
const int cust_count = 10;

int queues[2][queueSize];

int fronts[2] = {0, 0}; // read index
int rears[2] = {0, 0}; // write index

sem_t emptys[2]; // semaphores of empty queues
sem_t fulls[2]; // semaphores of full queues

pthread_mutex_t writeM[2];
pthread_mutex_t readM[2];
pthread_mutex_t waitM[cust_count];

unsigned int seed = 101; // initializer for rand

void *Customer(void *param) {
    int index = *((int*)param);
    while (1) {
        int ci = rand() % 2; // cashier index
        pthread_mutex_lock(&waitM[index]);
        pthread_mutex_lock(&writeM[ci]);
        sem_wait(&emptys[ci]);
        queues[ci][rears[ci]] = index;
        rears[ci] = (rears[ci] + 1) % queueSize;
        sem_post(&fulls[ci]);
        printf("Customer %d enters the queue of cashier %d\n", index, ci);
        pthread_mutex_unlock(&writeM[ci]);
        sleep(6);
    }
    return nullptr;
}

void *Cashier(void *param) {
    int ci = *((int*)param);
    int index;
    while (1) {
        sleep(10);
        pthread_mutex_lock(&readM[ci]);
        sem_wait(&fulls[ci]);
        index = queues[ci][fronts[ci]];
        fronts[ci] = (fronts[ci] + 1) % queueSize;
        sem_post(&emptys[ci]);
        printf("Cashier %d serves customer %d\n", ci, index);
        pthread_mutex_unlock(&readM[ci]);
        pthread_mutex_unlock(&waitM[index]);
    }
    return nullptr;
}

int main() {
    srand(seed);
    for (int i = 0; i < 2; ++i) {
        pthread_mutex_init(&writeM[i], nullptr);
        pthread_mutex_init(&readM[i], nullptr);
        sem_init(&emptys[i], 0, queueSize);
        sem_init(&fulls[i], 0, 0);
    }
    for (int i = 0; i < cust_count; ++i) {
        pthread_mutex_init(&waitM[i], nullptr);
    }

    pthread_t threadCus[cust_count];
    int customers[cust_count];
    for (int i = 0; i < cust_count; ++i) {
        customers[i] = i + 1;
        pthread_create(&threadCus[i], nullptr, Customer, (void *)(customers + i));
    }
    pthread_t threadCash[2];
    int cashiers[2];
    for (int i = 0; i < 2; ++i) {
        cashiers[i] = i + 1;
        pthread_create(&threadCash[i], nullptr, Cashier, (void *)(cashiers + i));
    }
    int index = 0;
    Cashier((void *)&index);
    return 0;
}
