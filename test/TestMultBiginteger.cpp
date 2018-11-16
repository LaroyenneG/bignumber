//
// Created by Guillaume LAROYENNE on 16/11/18.
//

#include "TestMultBiginteger.h"

TestMultBiginteger::TestMultBiginteger(std::string string) : CppUnit::TestCase(string) {

}

void TestMultBiginteger::runTest() {

    biginteger n1 = 6846841123;
    biginteger n2 = 468468468;

    CPPUNIT_ASSERT(n1 * n2 == n2 * n1);
    CPPUNIT_ASSERT(n1 * n2 == 3207529171531209564);
}
