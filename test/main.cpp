//
// Created by Guillaume LAROYENNE on 01/10/2018.
//

#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

#include "TestBiginteger.h"

int main(int argc, char **argv) {


    CppUnit::TextTestRunner runner;

    runner.addTest(new TestBignumber("Bignumber class test"));

    runner.run();

    return 0;
}
