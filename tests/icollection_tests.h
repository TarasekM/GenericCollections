#ifndef QUEUE_ICOLLECTION_TESTS_H
#define QUEUE_ICOLLECTION_TESTS_H

#include <iostream>
#include "../ICollection.h"
#include <cassert>
#include "../Person.h"


class ICollectionTest{
private:
    Person first_person = Person("Maciek", "Maciegowski", 25);
    Person second_person = Person("Kamil", "Macieg", 23);

public:

    void run_tests(){
        testAdd();
        testClear();
        testContains();
        testRemove();
        testGetIterator();
    }
    void testAdd(){
        ICollection<Person> items = ICollection<Person>();
        items.add(first_person);

        assert(items.length() == 1);
    }

    void testClear(){
        ICollection<Person> items = ICollection<Person>();
        items.add(first_person);
        items.clear();

        assert(items.length() == 0);
    }

    void testContains(){
        ICollection<Person> people = ICollection<Person>();
        people.add(first_person);

        assert(people.contains(first_person));
        assert(!people.contains(second_person));
    }

    void testRemove(){
        ICollection<Person> people = ICollection<Person>();
        people.add(first_person);
        people.add(second_person);
        people.remove(first_person);

        assert(people.length() == 1);
        assert(!people.contains(first_person));
        assert(people.contains(second_person));

        people.remove(second_person);
        assert(!people.contains(second_person));
        assert(people.length() == 0);
    }

    void testGetIterator(){
        ICollection<Person> people = ICollection<Person>();
        people.add(first_person);
        people.add(second_person);

        Iterator<Person> *iterator = people.getIterator();

        iterator-> moveNext();
        assert(iterator-> current().getName() == first_person.getName());
        iterator-> moveNext();
        assert(iterator-> current().getName() == second_person.getName());
        iterator->reset();
        iterator->moveNext();
        assert(iterator-> current().getName() == first_person.getName());

    }
};
#endif //QUEUE_ICOLLECTION_TESTS_H
