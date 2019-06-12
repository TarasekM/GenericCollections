#ifndef QUEUE_LINKED_LIST_H
#define QUEUE_LINKED_LIST_H

#include "node.h"
template <typename T> class LinkedList;

template <typename T>
class LinkedList{
protected:
    Node<T> *head;
    Node<T> *tail;
    int size;

public:

    LinkedList(){
        head = new Node<T>(new T);
        tail = new Node<T>(new T);
        size = 0;
    }

    ~LinkedList(){
        delete [] head;
    }

    Node <T> *getHead(){ return head; }

    Node <T> *getTail(){ return tail; }

    bool isEmpty(){
        return size == 0;
    }

    int length(){
        return size;
    }

    void addFirst(T *obj){
        auto *newNode = new Node<T>(obj);
        newNode-> setPrevious(new Node<T>(new T));
        if(this-> isEmpty()){
            head = newNode;
            tail = newNode;
        } else{
            head-> setPrevious(newNode);
            newNode-> setNext(head);
            head = newNode;
        }
        size++;
    }

    void addLast(T *obj){
        auto *newNode = new Node<T>(obj);
        newNode-> setNext(new Node<T>(new T));
        if(this-> isEmpty()){
            head = newNode;
            tail = newNode;
        } else{
            tail-> setNext(newNode);
            newNode-> setPrevious(tail);
            tail = newNode;
        }
        size++;
    }

    void remove(T *item){
        if (this-> isEmpty())
            return;
        Node<T> *node = head;
        int pos = 0;
        while(pos < size && !node->getItem()-> equals(item)){
            node = node-> getNext();
            pos++;
        }

        if(pos == size)
            return;

        if(size == 1){
            this-> clear();
            return;
        }

        if(node-> getPrevious()-> getItem()-> equals(new T)){
            head-> getNext()-> setPrevious(head-> getPrevious());
            head-> getPrevious()-> setNext(head->getNext());
            head = head-> getNext();
            size--;
            return;
        }

        if(node-> getNext()-> getItem()-> equals(new T)){
            tail-> getPrevious()-> setNext(tail-> getNext());
            tail-> getNext()-> setNext(tail->getPrevious());
            tail = tail-> getPrevious();
            size--;
            return;
        }

        node-> getPrevious()->setNext(node-> getNext());
        node-> getNext()-> setPrevious(node-> getPrevious());

        size--;
    }

    T *removeFirst(){

        if(this-> isEmpty()){
            return new T;
        }

        if(size == 1){
            this-> clear();
            return head->getItem();
        }

        T *item = head->getItem();
        head->getNext()->setPrevious(head->getPrevious());
        head = head->getNext();
        size--;
        return item;
    }

    void removeLast(){
        if(this-> isEmpty()){
            return;
        }

        if(size == 1){
            this-> clear();
            return;
        }

        tail->getPrevious()->setNext(tail->getNext());
        tail = tail->getPrevious();
        size--;
    }

    Node<T> *find(T *item){

        if (this-> isEmpty())
            return new Node<T>(new T);

        Node<T> *node = head;

        int pos = 0;
        while(pos < size && !node->getItem()-> equals(item)){
            node = node-> getNext();
            pos++;
        }

        if(pos == size)
            return new Node<T>(new T);

        return node;
    }

    void clear(){
        head = new Node<T>(new T);
        tail = new Node<T>(new T);
        this-> size = 0;
    }
};

#endif //QUEUE_LINKED_LIST_H
