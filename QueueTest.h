#ifndef QUEUE_QUEUETEST_H
#define QUEUE_QUEUETEST_H

#include "queue.h"
#include <cassert>

class QueueTest{
    int n;
public:
    explicit QueueTest(int n){ this -> n  = n; }

    void testIsEmpty(){
        auto *queue = new Queue <int>(n);
        assert(queue->isEmpty());
    }

    void testEnqueue(){
        auto *queue = new Queue <int>(n);
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
        auto *queue = new Queue <int>(n);
        queue-> enqueue(5);
        queue-> enqueue(1);
        assert(queue-> dequeue() == 5);
        assert(queue->getHead()->getItem() == 1);
        assert(queue->getTail()->getItem() == 1);
        assert(queue->getSize() == 1);
    }

    void testShow(){
        auto *queue = new Queue <int>(n);
        queue-> enqueue(5);
        queue-> enqueue(1);
        queue-> enqueue(2);
        queue-> showItems();
        assert(queue-> getHead()->getItem() == 5);
        assert(queue-> getTail()->getItem() == 2);
    }
};
#endif //QUEUE_QUEUETEST_H
