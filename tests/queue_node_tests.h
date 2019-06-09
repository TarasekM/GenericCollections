#ifndef QUEUE_QUEUETEST_H
#define QUEUE_QUEUETEST_H

#include "../queue_node.h"
#include <cassert>

class queue_node_tests{
    int n;
public:
    explicit queue_node_tests(int n){ this -> n  = n; }

    void run_tests(){
        testShow();
        testDequeue();
        testEnqueue();
        testIsEmpty();
    }

    void testIsEmpty(){
        auto *queue = new QueueNode <int>(n);
        assert(queue->isEmpty());
    }

    void testEnqueue(){
        auto *queue = new QueueNode <int>(n);
        queue-> enqueue(5);
        assert(queue-> getHead()->getItem() == 5);
        assert(queue-> getTail()->getItem() == 5);
        assert(queue-> getSize() == 1);
        queue-> enqueue(1);
        assert(queue-> getHead() -> getItem() == 5);
        assert(queue-> getTail()->getItem() == 1);
        assert(queue-> getSize() == 2);
        queue-> enqueue(2);
        assert(queue-> getHead() -> getItem() == 5);
        assert(queue-> getHead()-> getNext()-> getItem() == 1);
        assert(queue-> getTail()->getItem() == 2);
        assert(queue-> getSize() == 3);
    }

    void testDequeue(){
        auto *queue = new QueueNode <int>(n);
        queue-> enqueue(5);
        queue-> enqueue(1);
        assert(queue-> dequeue() == 5);
        assert(queue->getHead()->getItem() == 1);
        assert(queue->getTail()->getItem() == 1);
        assert(queue->getSize() == 1);
    }

    void testShow(){
        auto *queue = new QueueNode <int>(n);
        queue-> enqueue(5);
        queue-> enqueue(1);
        queue-> enqueue(2);
        queue-> showItems();

        assert(queue-> getHead()->getItem() == 5);
        assert(queue-> getTail()->getItem() == 2);
    }
};
#endif //QUEUE_QUEUETEST_H
