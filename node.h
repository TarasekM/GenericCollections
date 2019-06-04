#ifndef QUEUE_NODE_H
#define QUEUE_NODE_H

template <typename T> class Node;

template <typename T>
class Node{
private:
    T item;
    Node *next;
    Node *previous;
public:
    explicit Node(T item){
        this-> item = item;
    }

    T getItem(){ return item; }
    Node *getNext(){ return next; }
    Node *getPrevious(){ return previous; }

    void setItem(T item){ this-> item = item; }
    void setNext(Node *next){ this-> next = next; }
    void setPrevious(Node *previous){ this-> previous = previous; }

};

#endif //QUEUE_NODE_H
