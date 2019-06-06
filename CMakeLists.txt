cmake_minimum_required(VERSION 3.12)
project(Queue)

set(CMAKE_CXX_STANDARD 14)

add_executable(Queue tests/run_tests.cpp queue.h node.h tests/queue_tests.h ICollection.h tests/icollection_tests.h Person.cpp Person.h Iterator.h List.h tests/list_test.h)