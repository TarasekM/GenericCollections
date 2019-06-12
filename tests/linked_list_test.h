#ifndef QUEUE_LINKED_LIST_TEST_H
#define QUEUE_LINKED_LIST_TEST_H

#include <cassert>
#include <iostream>
#include "../linked_list.h"
#include "../Models/Person.h"

class linked_list_tests{
private:
    Person *first_person = new Person("Maciek", "Maciegowski", 25);
    Person *second_person = new Person("Kamil", "Macieg", 23);
    Person *third_person = new Person("Pawel","Nowak", 18);

    LinkedList<Person> list = LinkedList<Person>();
public:
    void run_tests(){
        testIsEmpty();
        testLength();
        testAddFirst();
        testAddLast();
        testRemove();
        testRemoveFirst();
        testRemoveLast();
        testFind();
    }

    void testIsEmpty(){
        assert(list.isEmpty());
    }

    void testLength(){
        assert(list.length() == 0);
    }

    void testAddFirst(){
        list.clear();
        list.addFirst(first_person);
        assert(list.getHead()-> getItem()-> equals(first_person));
        assert(list.getTail()-> getItem()-> equals(first_person));

        list.addFirst(second_person);
        assert(list.getHead()-> getItem()-> equals(second_person));
        assert(list.getTail()-> getItem()-> equals(first_person));
        assert(list.length() == 2);
    }

    void testAddLast(){
        list.clear();
        list.addLast(first_person);
        assert(list.getHead()-> getItem()-> equals(first_person));
        assert(list.getTail()-> getItem()-> equals(first_person));
        list.addLast(second_person);
        assert(list.getHead()-> getItem()-> equals(first_person));
        assert(list.getTail()-> getItem()-> equals(second_person));
    }

    void testRemove(){
        list.clear();
        list.addFirst(first_person);
        list.addLast(second_person);
        list.addLast(third_person);

        assert(list.length() == 3);
        assert(list.getHead()-> getItem()-> equals(first_person));
        assert(list.getTail()-> getItem()-> equals(third_person));

        list.remove(second_person);

        assert(list.length() == 2);
        assert(list.getHead()-> getItem()-> equals(first_person));
        assert(list.getTail()-> getItem()-> equals(third_person));

        list.remove(first_person);

        assert(list.length() == 1);
        assert(list.getHead()-> getItem()-> equals(third_person));
        assert(list.getTail()-> getItem()-> equals(third_person));

        list.remove(third_person);
        assert(list.length() == 0);
        assert(list.isEmpty());
        assert(list.getHead()-> getItem()-> equals(new Person()));
        assert(list.getTail()-> getItem()-> equals(new Person()));

        list.clear();

        list.addFirst(first_person);
        list.remove(second_person);

        assert(list.getHead()-> getItem()-> equals(first_person));
        assert(list.getTail()-> getItem()-> equals(first_person));

        list.addLast(second_person);
        list.addLast(third_person);

        assert(list.length() == 3);
        assert(list.getHead()-> getItem()-> equals(first_person));
        assert(list.getTail()-> getItem()-> equals(third_person));
    }

    void testRemoveFirst(){
        list.clear();
        list.addFirst(first_person);
        list.addLast(second_person);
        list.addLast(third_person);

        list.removeFirst();
        assert(list.length() == 2);
        assert(list.getHead()-> getItem()-> equals(second_person));
        assert(list.getTail()-> getItem()-> equals(third_person));

        list.removeFirst();
        assert(list.length() == 1);
        assert(list.getHead()-> getItem()-> equals(third_person));
        assert(list.getTail()-> getItem()-> equals(third_person));

        list.removeFirst();
        assert(list.length() == 0);
        assert(list.getHead()-> getItem()-> equals(new Person));
        assert(list.getTail()-> getItem()-> equals(new Person));
        list.removeFirst();
    }

    void testRemoveLast(){
        list.clear();
        list.addFirst(first_person);
        list.addLast(second_person);
        list.addLast(third_person);

        list.removeLast();
        assert(list.length() == 2);
        assert(list.getHead()-> getItem()-> equals(first_person));
        assert(list.getTail()-> getItem()-> equals(second_person));

        list.removeLast();
        assert(list.length() == 1);
        assert(list.getHead()-> getItem()-> equals(first_person));
        assert(list.getTail()-> getItem()-> equals(first_person));

        list.removeLast();
        assert(list.length() == 0);
        assert(list.getHead()-> getItem()-> equals(new Person));
        assert(list.getTail()-> getItem()-> equals(new Person));
        list.removeLast();
    }

    void testFind(){
        list.clear();
        list.addFirst(first_person);
        assert(list.find(first_person)-> getItem()-> equals(first_person));
        Node<Person> *node = list.find(first_person);
        node-> setItem(second_person);
        assert(list.getHead()-> getItem()-> equals(second_person));
        assert(list.getTail()-> getItem()-> equals(second_person));
        assert(list.find(third_person)->getItem()-> equals(new Person));
    }

};

#endif //QUEUE_LINKED_LIST_TEST_H
