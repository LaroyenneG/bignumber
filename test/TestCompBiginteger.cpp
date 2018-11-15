//
// Created by Guillaume LAROYENNE on 15/11/18.
//

#include "TestCompBiginteger.h"

TestCompBiginteger::TestCompBiginteger(std::string string) : TestCase(string) {

}

void TestCompBiginteger::runTest() {

    biginteger n1 = 19481984554315465;
    biginteger n2 = 18481984554315465;

    CPPUNIT_ASSERT(n1 >= n2);
    CPPUNIT_ASSERT(n1 > n2);
    CPPUNIT_ASSERT(n2 <= n1);
    CPPUNIT_ASSERT(n2 < n1);
    CPPUNIT_ASSERT(n1 <= n1);
    CPPUNIT_ASSERT(n1 >= n1);

    CPPUNIT_ASSERT(!(n1 <= n2));
    CPPUNIT_ASSERT(!(n1 < n2));
    CPPUNIT_ASSERT(!(n2 >= n1));
    CPPUNIT_ASSERT(!(n2 > n1));

    CPPUNIT_ASSERT(n1 == n1);
    CPPUNIT_ASSERT(!(n1 != n1));
    CPPUNIT_ASSERT(n2 != n1);
    CPPUNIT_ASSERT(n1 != n2);
    CPPUNIT_ASSERT(!(n1 == n2));
}
