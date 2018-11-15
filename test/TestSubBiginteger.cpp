//
// Created by Guillaume LAROYENNE on 15/11/18.
//

#include "TestSubBiginteger.h"

TestSubBiginteger::TestSubBiginteger(std::string string) : TestCase(string) {

}

void TestSubBiginteger::runTest() {

    biginteger n1 = 1659648673241354468;
    biginteger n2 = 1959648676241354268;


    CPPUNIT_ASSERT(n1 - n2 == -(n2 - n1));

    CPPUNIT_ASSERT(n2 - n1 == 300000002999999800);
}
