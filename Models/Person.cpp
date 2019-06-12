#include <utility>

//
// Created by rezkt on 04.06.2019.
//

#include "Person.h"
Person::Person() {
    name = "";
    surname = "";
    age = 0;
}


Person::Person(std::string name, std::string surname, int age) {
    this-> name = std::move(name);
    this-> surname = std::move(surname);
    this-> age = age;
}

bool Person::equals(Person other) {
    return (this-> name == other.getName() &&
            this-> surname == other.getSurname() &&
            this-> age == other.getAge());
}

bool Person::equals(Person *other) {
    return (this-> name == other-> getName() &&
            this-> surname == other-> getSurname() &&
            this-> age == other-> getAge());
}

std::string Person::toString(){
    std::string personAsString = "Name : " + name + " Surname : " + surname + " Age : " + std::to_string(age);
    return personAsString;
}