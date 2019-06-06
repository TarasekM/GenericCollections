#ifndef QUEUE_LIST_TEST_H
#define QUEUE_LIST_TEST_H

#include "../List.h"
#include "../ICollection.h"
#include "../Person.h"
#include <cassert>
#include <iostream>

class list_test{
private:
    Person first_person = Person("Maciek", "Maciegowski", 25);
    Person second_person = Person("Kamil", "Macieg", 23);
    Person third_person = Person("Pawel","Nowak", 18);
    List<Person> list = List<Person>();
public:
    void run_tests(){
        testConstructor();
        testAddCollection();
        testGetAtAndSetAt();
        testIndexOf();
        testLastIndexOf();
    }

    void testConstructor(){
        ICollection<Person> collection = ICollection<Person>();
        collection.add(first_person);
        collection.add(second_person);
        List<Person> list1 = List<Person>(collection);
        List<Person> list2 = List<Person>();
    }

    void testAddCollection(){
        resetList();
        ICollection<Person> collection = ICollection<Person>();
        collection.add(third_person);
        collection.add(first_person);

        list.addCollection(collection);

        assert(list.length() == 4);
        assert(list.lastIndexOf(first_person) == 3);
        assert(list.indexOf(third_person) == 2);
    }

    void testGetAtAndSetAt(){
        resetList();
        list.setAt(0, third_person);
        assert(list.getAt(0).getName() == third_person.getName());

    }

    void testIndexOf(){
        resetList();
        assert(list.indexOf(first_person) == 0);
        assert(list.indexOf(second_person) == 1);

        Person person = Person(first_person.getName(),first_person.getSurname(), first_person.getAge());
        assert(list.indexOf(person) == 0);
        assert(list.indexOf(third_person) == -1);
    }

    void testLastIndexOf(){
        resetList();
        list.add(first_person);
        assert(list.lastIndexOf(first_person) == 2);
    }

    void resetList(){
        list.clear();
        list.add(first_person);
        list.add(second_person);
    }

};
#endif //QUEUE_LIST_TEST_H
