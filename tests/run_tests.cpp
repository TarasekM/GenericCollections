#include <cstdint>
#include <iostream>
#include <memory>
#include <string>

#include "queue_tests.h"
#include "icollection_tests.h"
#include "list_test.h"
#include "stack_tests.h"

using namespace std;
int main() {
    queue_tests queueTest = queue_tests(5);
    queueTest.run_tests();


    ICollectionTest iCollectionTest = ICollectionTest();
    iCollectionTest.run_tests();

    list_test listTest = list_test();
    listTest.run_tests();

    stack_test stackTest = stack_test();
    stackTest.run_tests();

    return 0;
}