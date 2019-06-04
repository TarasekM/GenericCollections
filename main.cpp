#include <cstdint>
#include <iostream>
#include <memory>
#include <string>

#include "QueueTest.h"

using namespace std;
int main() {
    QueueTest queueTest = QueueTest(5);
    queueTest.testIsEmpty();
    queueTest.testEnqueue();
    queueTest.testDequeue();
    queueTest.testShow();

    return 0;
}