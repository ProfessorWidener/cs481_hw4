// EXPECT_EQ and ASSERT_EQ are macros
// EXPECT_EQ test execution and continues even if there is a failure
// ASSERT_EQ test execution and aborts if there is a failure
// The ASSERT_* variants abort the program execution if an assertion fails 
// while EXPECT_* variants continue with the run.

#include "gtest/gtest.h"
#include "../producer_consumer.hpp"

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}

TEST(TLBTest, TestsIntests)
{
    buffer_t* buf = (buffer_t*)malloc(sizeof(buffer_t));

    init(buf, 5);
    int* return_val;

    pthread_t* threads = (pthread_t*)malloc(sizeof(pthread_t));
    pthread_create(threads, NULL, consumer_thread, buf);
    data_t* data = (data_t*)malloc(sizeof(data_t));
    data->buf = buf;
    data->val = 10;
    put(buf, data->val);
    pthread_cond_signal(&(buf->empty));
    pthread_cond_signal(&(buf->full));
    pthread_join(threads[0], (void**)&return_val);
    ASSERT_EQ(*return_val, data->val);

    destroy(buf);

    free(threads);
    free(data);
    free(buf);
}
