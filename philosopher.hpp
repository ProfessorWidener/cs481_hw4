#ifndef HW4_SRC_PHILOSOPHER_HPP
#define HW4_SRC_PHILOSOPHER_HPP

#include <pthread.h>
#include <semaphore.h>

typedef struct __diners_t
{
    sem_t* forks;
    int size;
    pthread_mutex_t mutex;
    int philosopher;
    bool* eat;
} diners_t;

void* philosopher(void* args);
void eat(diners_t* diner);
sem_t& left(diners_t* diner);
sem_t& right(diners_t* diner);

#endif
