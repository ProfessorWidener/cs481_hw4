include_directories(${hw4_INCDIR})

add_executable(test_producer_consumer_cond test_producer_consumer.cpp)
target_link_libraries(test_producer_consumer_cond hw4_cond googletest )
add_test(TestCondProducerConsumer ./test_producer_consumer_cond)

add_executable(test_producer_consumer_cond2 test_producer_consumer2.cpp)
target_link_libraries(test_producer_consumer_cond2 hw4_cond googletest )
add_test(TestCondProducerConsumer2 ./test_producer_consumer_cond2)

add_executable(test_cond test_cond.cpp)
target_link_libraries(test_cond hw4_cond googletest )
add_test(TestCond ./test_cond)

add_executable(test_producer_consumer_sem test_producer_consumer.cpp)
target_link_libraries(test_producer_consumer_sem hw4_sem googletest )
add_test(TestSemProducerConsumer ./test_producer_consumer_sem)

add_executable(test_producer_consumer_sem2 test_producer_consumer2.cpp)
target_link_libraries(test_producer_consumer_sem2 hw4_sem googletest )
add_test(TestSemProducerConsumer2 ./test_producer_consumer_sem2)

add_executable(test_sem test_sem.cpp)
target_link_libraries(test_sem hw4_sem googletest )
add_test(TestSem ./test_sem)

add_executable(test_philosopher_circ test_philosopher.cpp)
target_link_libraries(test_philosopher_circ hw4_circ googletest )
add_test(TestCircPhilosopher ./test_philosopher_circ)

add_executable(test_philosopher_hold test_philosopher.cpp)
target_link_libraries(test_philosopher_hold hw4_hold googletest )
add_test(TestHoldPhilosopher ./test_philosopher_hold)
