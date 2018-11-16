//
// Created by Guillaume LAROYENNE on 16/11/18.
//

#include "TestModBiginteger.h"

TestModBiginteger::TestModBiginteger(std::string string) : TestCase(string) {

}

void TestModBiginteger::runTest() {

    biginteger b1 = 4867610870687686544;
    biginteger b2 = 4864884663459;

    CPPUNIT_ASSERT(b1 % b2 == 1871817149504);
}
