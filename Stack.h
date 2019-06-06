#ifndef QUEUE_STACK_H
#define QUEUE_STACK_H
#include "ICollection.h"
template <typename T> class Stack;

template <typename T>
class Stack : ICollection<T>{
public:
    Stack<T>() = default;
    ~Stack<T>() = default;

    bool isEmpty(){

    }

    void push(const T &obj){

    }

    T pop(const T &obj){

    }

    T top(){

    }

};
#endif //QUEUE_STACK_H
