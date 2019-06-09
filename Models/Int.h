#ifndef QUEUE_INT_H
#define QUEUE_INT_H
class Int{
public:
    Int() = default;
    ~Int() = default;
    int value = 0;

    bool equals(const Int &other){
        return this-> value == other.value;
    }
};
#endif //QUEUE_INT_H
