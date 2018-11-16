//
// Created by Guillaume LAROYENNE on 15/11/18.
//

#include "TestAddBiginteger.h"

TestAddBiginteger::TestAddBiginteger(std::string string) : TestCase(string) {

}

void TestAddBiginteger::runTest() {

    biginteger n1 = 1659648673241354468;
    biginteger n2 = 1959648676241354268;

    CPPUNIT_ASSERT(n1 + n2 == n2 + n1);

    CPPUNIT_ASSERT(n1 + n2 == 3619297349482708736);

    n1 += 100;

    CPPUNIT_ASSERT(n1 == 1659648673241354568);
}
