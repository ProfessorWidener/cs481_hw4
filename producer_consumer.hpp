#ifndef HW4_SRC_PRODUCER_CONSUMER_HPP
#define HW4_SRC_PRODUCER_CONSUMER_HPP

#include "buffer.hpp"
#include "pthread.h"

typedef struct __data_t
{
    buffer_t* buf;
    int val;
} data_t;

void* producer_thread(void* args);
void* consumer_thread(void* args);

#endif
