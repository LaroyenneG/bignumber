//
// Created by Guillaume LAROYENNE on 15/11/18.
//

#include "TestNegBiginteger.h"

TestNegBiginteger::TestNegBiginteger(std::string string) : TestCase(string) {

}

void TestNegBiginteger::runTest() {

    biginteger n1 = 19481984554315465;
    biginteger n2 = -19481984554315465;

    CPPUNIT_ASSERT(n1 != -n1);
    CPPUNIT_ASSERT(!(n1 == -n1));
    CPPUNIT_ASSERT(!(n1 == n2));
    CPPUNIT_ASSERT(n1 == -n2);
}
