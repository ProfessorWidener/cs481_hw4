#include "buffer.hpp"

void init(buffer_t* buf, int limit)
{
    buf->list = new int[limit];
    buf->limit = limit;
    buf->put_ctr = 0;
    buf->get_ctr = 0;
    buf->size = 0;

    pthread_cond_init(&(buf->full), NULL);
    pthread_cond_init(&(buf->empty), NULL);
    pthread_mutex_init(&(buf->mutex), NULL);
    sem_init(&(buf->sem_empty), 0, limit);
    sem_init(&(buf->sem_full), 0, 0);
}

void put(buffer_t* buf, int val)
{
    buf->list[buf->put_ctr] = val;
    buf->put_ctr = (buf->put_ctr+1) % buf->limit;
    buf->size++;
}

void get(buffer_t* buf, int* val_ptr)
{
    *val_ptr = buf->list[buf->get_ctr];
    buf->get_ctr = (buf->get_ctr+1) % buf->limit;
    buf->size--;
}

void destroy(buffer_t* buf)
{
    delete[] buf->list;

    pthread_cond_destroy(&(buf->full));
    pthread_cond_destroy(&(buf->empty));
    pthread_mutex_destroy(&(buf->mutex));
}
