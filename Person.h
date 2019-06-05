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
    Person();
    ~Person() = default;
    Person(std::string name, std::string surname, int age);

    int getAge() const { return age; }
    std::string getName() const { return name; }
    std::string getSurname() const { return surname; }

    bool equals(Person other);
};


#endif //QUEUE_PERSON_H
