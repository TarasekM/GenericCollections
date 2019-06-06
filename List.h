#ifndef QUEUE_LIST_H
#define QUEUE_LIST_H

#include "ICollection.h"
#include "Iterator.h"

template <typename T> class List;

template <typename T>
class List : public ICollection<T>{
private:
    void addFromCollection(ICollection<T> &collection){
        Iterator<T> *iterator = collection.getIterator();
        while (iterator->moveNext()){
            this-> add(iterator->current());
        }
    }
public:
    List<T>() = default;
    ~List() = default;

    explicit List<T>(ICollection<T> &collection){
        addFromCollection(collection);
    }

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
        return this-> items[i];
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



};
#endif //QUEUE_LIST_H
