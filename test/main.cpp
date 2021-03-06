//
// Created by Guillaume LAROYENNE on 01/10/2018.
//

#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

#include "TestAddBiginteger.h"
#include "TestCompBiginteger.h"
#include "TestNegBiginteger.h"
#include "TestSubBiginteger.h"
#include "TestMultBiginteger.h"
#include "TestDivBiginteger.h"
#include "TestModBiginteger.h"
#include "TestPrimeFactory.h"

int main(int argc, char **argv) {

    CppUnit::TextTestRunner runner;


    runner.addTest(new TestCompBiginteger("Biginteger < > fonction test"));
    runner.addTest(new TestNegBiginteger("Biginteger neg fonction test"));
    runner.addTest(new TestAddBiginteger("Biginteger + fonction test"));
    runner.addTest(new TestSubBiginteger("Biginteger - fonction test"));
    runner.addTest(new TestMultBiginteger("Biginteger * fonction test"));
    runner.addTest(new TestDivBiginteger("Biginteger / fonction test"));
    runner.addTest(new TestModBiginteger("Biginteger % fonction test"));

    runner.addTest(new TestPrimeFactory("PrimeFactory"));

    runner.run();

    return 0;
}
