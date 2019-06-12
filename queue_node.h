#ifndef QUEUE_QUEUE_NODE_H
#define QUEUE_QUEUE_NODE_H

#include <iostream>
#include "node.h"
#include "linked_list.h"
template <typename T> class QueueNode;

template <typename T>
class QueueNode : protected LinkedList<T>{
private:
    int maxSize{};
public:
    QueueNode() = default;

    explicit QueueNode(int n) : LinkedList<T>(){
        maxSize = n;
    }

    bool empty(){ return this-> isEmpty(); }

    void enqueue(T *item){
        if (maxSize <= this->length()){
            return;
        }

        this-> addLast(item);
    }

    T *dequeue(){
        return this->removeFirst();
    }

    Node <T> *getFirst(){ return this-> getHead(); }
    Node <T> *getLast(){ return this-> getTail(); }

    int getSize(){ return this-> length(); }

    void showItems(){
        Node <T> *node = this-> getHead();
        while(!node->getItem()-> equals(new T)){
            std::cout << node->getItem()-> toString() << " ";
            node = node->getNext();
            std::cout << std::endl;
        }
    }

};

#endif //QUEUE_QUEUE_NODE_H
