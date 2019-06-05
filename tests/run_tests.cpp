#include <cstdint>
#include <iostream>
#include <memory>
#include <string>

#include "queue_tests.h"
#include "icollection_tests.h"

using namespace std;
int main() {
    queue_tests queueTest = queue_tests(5);
    queueTest.testIsEmpty();
    queueTest.testEnqueue();
    queueTest.testDequeue();
    queueTest.testShow();

    ICollectionTest iCollectionTest = ICollectionTest();
    iCollectionTest.testAdd();
    iCollectionTest.testClear();
    iCollectionTest.testContains();
    iCollectionTest.testRemove();
    iCollectionTest.testGetIterator();
    return 0;
}