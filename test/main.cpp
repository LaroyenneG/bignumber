//
// Created by Guillaume LAROYENNE on 01/10/2018.
//

#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

#include "TestAddBiginteger.h"
#include "TestSubBiginteger.h"

int main(int argc, char **argv) {

    CppUnit::TextTestRunner runner;

    runner.addTest(new TestAddBiginteger("Biginteger add fonction test"));
    runner.addTest(new TestSubBiginteger("Biginteger sub fonction test"));

    runner.run();

    return 0;
}
