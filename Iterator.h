#ifndef QUEUE_ITERATOR_H
#define QUEUE_ITERATOR_H

template <typename T> class Iterator;
template <typename T>

class Iterator{
protected:
    T *items;
    int size = 0;
    int currentPos = -1;

    Iterator<T> *get(){
        return this;
    }

public:
    Iterator<T>(){
        items = new T[0];
    }

    ~Iterator<T>(){
        delete [] items;
    }

    T current(){
        return items[currentPos];
    }

    bool moveNext(){
        currentPos++;
        if (currentPos >= size){
            currentPos = size - 1;
            return false;
        }
        return true;
    }

    void reset(){
        currentPos = -1;
    }
};
#endif //QUEUE_ITERATOR_H
