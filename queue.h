#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

#include "ICollection.h"
template  <typename T> class Queue;

template <typename T>
class Queue : protected ICollection<T>{
public:
    Queue() = default;
    ~Queue() = default;

    bool isEmpty(){
        return this-> size == 0;
    }

    void enqueue(const T &obj){
        this-> add(obj);
    }

    T dequeue(){
        T tmp = this-> items[0];
        this-> remove(this-> items[0]);
        return tmp;
    }

    T first(){
        return this-> items[0];
    }
};
#endif //QUEUE_QUEUE_H
