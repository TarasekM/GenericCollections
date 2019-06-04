#ifndef QUEUE_ICOLLECTION_H
#define QUEUE_ICOLLECTION_H

template <typename T> class ICollection;
template <typename T>
class ICollection{

private:
    T *items;
    int size;
    // T must implement basic constructor
    void resize(int newSize) {

        T *pts = new T [ newSize ];
        int minSize = ( newSize > size ? size : newSize ) ;

        for ( int i = 0; i < minSize ; i ++)
            pts [ i ] = items[ i ];
        delete [] items ;
        size = newSize ;
        items = pts ;
    }

public:

    void add(T item) {
        resize(size + 1);
        items[size -1] = item;
    }


    void clear() {
        resize(0);
    }

    /*
     * Requires function item.equals()
     * */

    bool contains(const T &item) {
        for (int i = 0; i < size; i++){
            if (items[i].equals(item)){
                return true;
            }
        }
        return false;
    }

    /*
      * Requires function item.equals()
      * */

    void remove(const T &item){
        if (size == 0)
            return;

        int pos = 0;
        for (int i = 0; i < size; i++){
            if (items[i].equals(item)){
                break;
            }
            pos++;
        }

        for ( int i = pos ; i < size - 1; i ++) {
            items[i] = items[i + 1];
        }

        resize(size - 1);

    }

    int length() {
        return size;
    }

    const T *getIterator(){
        return items;
    };
    
};
#endif //QUEUE_ICOLLECTION_H
