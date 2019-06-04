#include <cstdint>
#include <iostream>
#include <memory>
#include <string>

#include "QueueTest.h"
#include "icollection_test.h"

using namespace std;
int main() {
    QueueTest queueTest = QueueTest(5);
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