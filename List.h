#ifndef QUEUE_LIST_H
#define QUEUE_LIST_H

#include <cassert>
#include <iostream>
#include "ICollection.h"
#include "Iterator.h"
#include "Stack.h"


template <typename T> class List;

template <typename T>
class List : public ICollection<T>{
private:
    const std::string IndexOutOfBoundsException = "Index out of bounds";

    void addFromCollection(ICollection<T> &collection){
        Iterator<T> *iterator = collection.getIterator();
        while (iterator->moveNext()){
            this-> add(iterator->current());
        }
    }
public:
    List<T>() = default;
    explicit List<T>(ICollection<T> &collection){
        addFromCollection(collection);
    }
    ~List() = default;


    void addCollection(ICollection<T> &collection){
        addFromCollection(collection);
    }

    void setAt(int i, const T &obj){
        if ( i > this-> size || i < 0){
            return;
        }
        this-> items[i] = obj;
    }

    T getAt(int i){
        if (i >= this-> size){
            throw IndexOutOfBoundsException;
        }
        return this-> items[i];
    }

    void removeAll(const T &obj){
        while(this-> contains(obj)){
            this-> remove(obj);
        }
    }

    void removeAt(int i){
        if (i >= this-> size || i < 0) return;
        const T obj = this-> getAt(i);
        this-> remove(obj);
    }

    void removeRange(int min, int max){
        if (min > max) return;
        for (int i = min; i <= max; i++){
            this-> removeAt(min);
        }
    }

    int indexOf(const T &obj){
        for (int i = 0; i < this-> size; i++){
            if (this-> items[i].equals(obj)){
                return i;
            }
        }
        return -1;
    }

    int lastIndexOf(const T &obj){
        int index = -1;
        for (int i = 0; i < this-> size; i++){
            if (this-> items[i].equals(obj)){
                index = i;
            }
        }
        return index;
    }

    int lastIndexOf(const T &obj, int max){
        int index = -1;
        if (max >= this-> size) return index;

        for (int i = 0; i <= max; i++){
            if (this-> items[i].equals(obj)){
                index = i;
            }
        }
        return index;
    }

    int lastIndexInRangeOf(const T &obj, int min, int max){
        int index = -1;
        if (max >= this-> size) return index;
        if (min > max) return index;

        for (int i = min; i <= max; i++){
            if (this-> items[i].equals(obj)){
                index = i;
            }
        }
        return index;
    }

};
#endif //QUEUE_LIST_H
