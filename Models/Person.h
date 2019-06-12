//
// Created by rezkt on 04.06.2019.
//

#ifndef QUEUE_PERSON_H
#define QUEUE_PERSON_H

#include <iostream>

class Person {
private:
    std::string name;
    std::string surname;
    int age;
public:
    // T need to have constructor without parameters
    Person();
    ~Person() = default;
    Person(std::string name, std::string surname, int age);

    int getAge() const { return age; }
    std::string getName() const { return name; }
    std::string getSurname() const { return surname; }
    // T need to have implemented function equals(obj) for non-Node based generic collections
    bool equals(Person other);
    // T need to have implemented function equals(*obj) for Node based generic collections
    bool equals(Person *other);
    // T need to have implemented function toString to print obj in terminal
    std::string toString();
};


#endif //QUEUE_PERSON_H
