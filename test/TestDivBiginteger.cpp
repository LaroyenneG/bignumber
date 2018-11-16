//
// Created by Guillaume LAROYENNE on 16/11/18.
//

#include "TestDivBiginteger.h"

TestDivBiginteger::TestDivBiginteger(std::string string) : TestCase(string) {
}

void TestDivBiginteger::runTest() {

    biginteger n1 = 6846841123;
    biginteger n2 = 468468468;

    CPPUNIT_ASSERT(n1 / n2 == 14);
}
