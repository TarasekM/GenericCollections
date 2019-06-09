#ifndef QUEUE_QUEUE_NODE_H
#define QUEUE_QUEUE_NODE_H

#include <iostream>
#include "node.h"
template <typename T> class QueueNode;

template <typename T>
class QueueNode{
private:
    Node <T> *head;
    Node <T> *tail;
    int size{};
    int maxSize{};
public:
    QueueNode() = default;

    explicit QueueNode(int n){
        head = new Node <T>(-1);
        tail = new Node <T>(-1);
        maxSize = n;
        size = 0;
    }

    bool isEmpty(){ return size == 0; }

    int enqueue(T item){
        if (size >= maxSize){
            return -1;
        }
        auto *newNode = new Node<T>(item);
        newNode->setNext(new Node<T>(-1));
        if (size == 0){
            head = newNode;
            tail = newNode;
        }else{
            tail->setNext(newNode);
            newNode->setPrevious(tail);
            tail = newNode;
        }
        size++;
        return 1;
    }

    int dequeue(){
        if (isEmpty()){
            return -1;
        }
        int item = head -> getItem();
        head = head ->getNext();
        size--;
        return item;
    }

    Node <T> *getHead(){ return head; }
    Node <T> *getTail(){ return tail; }
    int getSize(){ return size; }

    void showItems(){
        Node <T> *node = head;
        while(node->getItem() != -1){
            std::cout << node->getItem() << " ";
            node = node->getNext();
        }
        std::cout << std::endl;
    }

};

#endif //QUEUE_QUEUE_NODE_H
