//
// Created by Guillaume LAROYENNE on 15/11/18.
//

#include "TestSubBiginteger.h"

TestSubBiginteger::TestSubBiginteger(std::string string) : TestCase(string) {

}

void TestSubBiginteger::runTest() {


    biginteger b1 = 1659648673241354468;
    biginteger b2 = 1959648676241354268;


    CPPUNIT_ASSERT(b1 - b2 == -(b2 - b1));

    CPPUNIT_ASSERT(b2 - b1 == 300000002999999800);
}
