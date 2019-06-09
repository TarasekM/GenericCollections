#ifndef QUEUE_STACK_TESTS_H
#define QUEUE_STACK_TESTS_H

#include "../Stack.h"
#include "../Models/Int.h"
#include <cassert>

class stack_test{
private:
    Int intObj = Int();
    Int intObj2 = Int();
public:
    void run_tests(){
        intObj2.value = 2;
        testIsEmpty();
        testPush();
        testTop();
        testPop();
    }

    void testIsEmpty(){
        Stack<Int> stack = Stack<Int>();
        assert(stack.isEmpty());
    }

    void testPush(){
        Stack<Int> stack = Stack<Int>();
        stack.push(intObj);
        assert(!stack.isEmpty());
    }

    void testTop(){
        Stack<Int> stack = Stack<Int>();
        stack.push(intObj);
        assert(stack.top().equals(intObj));
        stack.push(intObj2);

    }

    void testPop(){
        Stack<Int> stack = Stack<Int>();
        stack.push(intObj2);
        stack.push(intObj);
        stack.pop();
        assert(stack.top().equals(intObj2));
        stack.pop();
        assert(stack.isEmpty());
    }

};
#endif //QUEUE_STACK_TESTS_H
