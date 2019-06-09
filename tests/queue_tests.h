#ifndef QUEUE_QUEUE_TESTS_H
#define QUEUE_QUEUE_TESTS_H

#include "../queue.h"
#include "../Models/Person.h"
#include <cassert>

class queue_tests{
private:
    Person first_person = Person("Maciek", "Maciegowski", 25);
    Person second_person = Person("Kamil", "Macieg", 23);
public:

    void run_tests(){
        testIsEmpty();
        testEnqueue();
        testDequeue();
        testFirst();

    }

    void testIsEmpty(){
        Queue<Person> queue = Queue <Person>();
        assert(queue.isEmpty());
    }

    void testEnqueue(){
        Queue<Person> queue = Queue <Person>();
        queue.enqueue(first_person);
        assert(!queue.isEmpty());
    }

    void testDequeue(){
        Queue<Person> queue = Queue <Person>();
        queue.enqueue(first_person);
        queue.enqueue(second_person);
        queue.dequeue();
        assert(queue.first().equals(second_person));
        assert(queue.dequeue().equals(second_person));
    }

    void testFirst(){
        Queue<Person> queue = Queue <Person>();
        queue.enqueue(first_person);
        assert(queue.first().equals(first_person));

    }
};
#endif //QUEUE_QUEUE_TESTS_H
