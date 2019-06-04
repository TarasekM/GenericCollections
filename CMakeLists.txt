cmake_minimum_required(VERSION 3.12)
project(Queue)

set(CMAKE_CXX_STANDARD 14)

add_executable(Queue main.cpp queue.h node.h QueueTest.h ICollection.h icollection_test.h Person.cpp Person.h)