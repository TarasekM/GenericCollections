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
        testLastIndexOfMaxRange();
        testLastIndexInRangeOf();
        testRemoveAt();
        testRemoveRange();
        testRemoveAll();
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
        try {
            list.getAt(10);
        }catch (std::string &Exception){
            //TODO should make Exception class
            assert(Exception == "Index out of bounds");
        }

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
        assert(list.lastIndexOf(third_person) == -1);
    }

    void testLastIndexOfMaxRange(){
        resetList();
        list.add(first_person);
        assert(list.lastIndexOf(first_person, 1) == 0);
        assert(list.lastIndexOf(third_person) == -1);
        assert(list.lastIndexOf(first_person, 10) == -1);
    }

    void testLastIndexInRangeOf(){
        resetList();
        list.add(third_person);
        list.add(first_person);
        list.add(first_person);
        assert(list.lastIndexInRangeOf(first_person, 2, 4) == 4);
        assert(list.lastIndexInRangeOf(first_person, 0, 2) == 0);
        assert(list.lastIndexInRangeOf(first_person, 10, 15) == -1);
        assert(list.lastIndexInRangeOf(first_person, 1, 2) == -1);
        assert(list.lastIndexInRangeOf(first_person, 3, 2) == -1);
    }

    void testRemoveAt(){
        resetList();
        list.add(first_person);
        list.removeAt(0);
        assert(list.length() == 2);
        assert(list.indexOf(second_person) == 0);
        assert(list.indexOf(first_person) == 1);
    }

    void testRemoveRange(){
        resetList();
        list.add(third_person);
        list.removeRange(0, 1);
        assert(list.length() == 1);
        assert(list.indexOf(first_person) == -1);
        assert(list.indexOf(second_person) == -1);
        assert(list.indexOf(third_person) == 0);
    }

    void testRemoveAll(){
        resetList();
        list.add(first_person);
        list.removeAll(first_person);
        assert(list.length() == 1);
        assert(list.indexOf(first_person) == -1);
        assert(list.indexOf(second_person) == 0);
    }

    void resetList(){
        list.clear();
        list.add(first_person);
        list.add(second_person);
    }

};
#endif //QUEUE_LIST_TEST_H
