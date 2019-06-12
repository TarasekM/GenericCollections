#ifndef QUEUE_QUEUETEST_H
#define QUEUE_QUEUETEST_H

#include "../queue_node.h"
#include <cassert>
#include "../Models/Person.h"

class queue_node_tests{
    int n;
    Person *first_person = new Person("Maciek", "Maciegowski", 25);
    Person *second_person = new Person("Kamil", "Macieg", 23);
    Person *third_person = new Person("Pawel","Nowak", 18);
public:
    explicit queue_node_tests(int n){ this -> n  = n; }

    void run_tests(){
//        testShow();
        testDequeue();
        testEnqueue();
        testIsEmpty();
    }

    void testIsEmpty(){
        QueueNode<Person> queue = QueueNode <Person>(n);
        assert(queue.empty());
    }

    void testEnqueue(){
        QueueNode<Person> queue = QueueNode <Person>(n);
        queue.enqueue(first_person);
        assert(queue.getFirst()-> getItem()-> equals(first_person));
        assert(queue.getLast()-> getItem()-> equals(first_person));
        assert(queue.getSize() == 1);
        queue.enqueue(second_person);
        assert(queue.getFirst() -> getItem()-> equals(first_person));
        assert(queue.getLast()-> getItem()-> equals(second_person));
        assert(queue.getSize() == 2);
        queue.enqueue(third_person);
        assert(queue.getFirst() -> getItem()-> equals(first_person));
        assert(queue.getFirst()-> getNext()-> getItem()-> equals(second_person));
        assert(queue.getLast()-> getItem()-> equals(third_person));
        assert(queue.getSize() == 3);
    }

    void testDequeue(){
        QueueNode<Person> queue = QueueNode <Person>(n);
        queue.enqueue(first_person);
        queue.enqueue(second_person);
        assert(queue.dequeue()-> equals(first_person));
        assert(queue.getFirst()-> getItem()-> equals(second_person));
        assert(queue.getLast()-> getItem()-> equals(second_person));
        assert(queue.getSize() == 1);
    }

    void testShow(){
        QueueNode<Person> queue = QueueNode <Person>(n);
        queue.enqueue(first_person);
        queue.enqueue(second_person);
        queue.enqueue(third_person);
        queue.showItems();

        assert(queue.getFirst()->getItem()-> equals(first_person));
        assert(queue.getLast()->getItem()-> equals(third_person));
    }
};
#endif //QUEUE_QUEUETEST_H
