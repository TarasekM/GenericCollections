#include <cstdint>
#include <iostream>
#include <memory>
#include <string>

#include "queue_node_tests.h"
#include "icollection_tests.h"
#include "list_test.h"
#include "stack_tests.h"
#include "queue_tests.h"

using namespace std;
int main() {
    queue_node_tests queueNodeTests = queue_node_tests(5);
    queueNodeTests.run_tests();


    ICollectionTest iCollectionTest = ICollectionTest();
    iCollectionTest.run_tests();

    list_test listTest = list_test();
    listTest.run_tests();

    stack_test stackTest = stack_test();
    stackTest.run_tests();

    queue_tests queueTests = queue_tests();
    queueTests.run_tests();

    return 0;
}