#ifndef HW4_SRC_BUFFER_HPP
#define HW4_SRC_BUFFER_HPP

#include "pthread.h"
#include "semaphore.h"
#include "stdlib.h"

typedef struct __buffer_t
{
    int limit;
    int* list;
    int put_ctr;
    int get_ctr;
    int size;
    pthread_cond_t empty;
    pthread_cond_t full;
    pthread_mutex_t mutex;
    sem_t sem_empty;
    sem_t sem_full;
} buffer_t;

void init(buffer_t* buf, int limit);
void put(buffer_t* buf, int val);
void get(buffer_t* buf, int* val);
void destroy(buffer_t* buf);

#endif
