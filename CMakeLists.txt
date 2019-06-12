cmake_minimum_required(VERSION 3.12)
project(Queue)

set(CMAKE_CXX_STANDARD 14)

add_executable(Queue tests/run_tests.cpp queue_node.h node.h tests/queue_node_tests.h ICollection.h tests/icollection_tests.h Models/Person.cpp Models/Person.h Iterator.h List.h tests/list_test.h Stack.h tests/stack_tests.h Models/Int.h queue.h tests/queue_tests.h linked_list.h tests/linked_list_test.h)