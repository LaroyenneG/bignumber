//
// Created by Guillaume LAROYENNE on 01/10/2018.
//

#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

#include "TestAddBiginteger.h"
#include "TestSubBiginteger.h"
#include "TestCompBiginteger.h"
#include "TestNegBiginteger.h"

int main(int argc, char **argv) {

    CppUnit::TextTestRunner runner;


    runner.addTest(new TestCompBiginteger("Biginteger < > fonction test"));
    runner.addTest(new TestNegBiginteger("Biginteger neg fonction test"));
    runner.addTest(new TestAddBiginteger("Biginteger + fonction test"));
    runner.addTest(new TestSubBiginteger("Biginteger - fonction test"));

    runner.run();

    return 0;
}
