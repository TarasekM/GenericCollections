#ifndef QUEUE_ICOLLECTION_H
#define QUEUE_ICOLLECTION_H

#include "Iterator.h"
template <typename T> class ICollection;
template <typename T>
class ICollection : public Iterator<T>{

private:
    // T must implement basic constructor
    void resize(int newSize) {

        T *pts = new T [ newSize ];
        int minSize = ( newSize > this-> size ? this-> size : newSize ) ;

        for ( int i = 0; i < minSize ; i ++)
            pts [ i ] = this-> items[ i ];
        delete [] this-> items ;
        this-> size = newSize ;
        this-> items = pts ;
    }

public:

    using Iterator<T>::Iterator;
    ~ICollection<T>() = default;

    void add(T item) {
        resize(this-> size + 1);
        this-> items[this-> size -1] = item;
    }

    void clear() {
        resize(0);
    }

    /*
     * Requires function item.equals()
     * */

    bool contains(const T &item) {
        for (int i = 0; i < this-> size; i++){
            if (this-> items[i].equals(item)){
                return true;
            }
        }
        return false;
    }

    /*
      * Requires function item.equals()
      * */

    void remove(const T &item){
        if (this-> size == 0)
            return;

        int pos = 0;
        for (int i = 0; i < this-> size; i++){
            if (this-> items[i].equals(item)){
                break;
            }
            pos++;
        }

        for ( int i = pos ; i < this-> size - 1; i ++) {
            this-> items[i] = this-> items[i + 1];
        }

        resize(this-> size - 1);

    }

    int length() {
        return this-> size;
    }

public:
    Iterator<T> *getIterator(){
        return this-> get();
    };

    
};
#endif //QUEUE_ICOLLECTION_H
