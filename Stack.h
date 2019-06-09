#ifndef QUEUE_STACK_H
#define QUEUE_STACK_H
#include "ICollection.h"
template <typename T> class Stack;

template <typename T>
class Stack : protected ICollection<T>{
public:
    Stack<T>() = default;
    ~Stack<T>() = default;

    bool isEmpty(){
        return this->size == 0;
    }

    void push(const T &obj){
        this->add(obj);
    }

    void pop(){
        this-> remove(this-> top());
    }

    T top(){
        return this-> items[this-> size - 1];
    }

};
#endif //QUEUE_STACK_H
