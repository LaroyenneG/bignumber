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


    biginteger n3 = -19481984554315465;
    biginteger n4 = -18481984554315465;


    CPPUNIT_ASSERT(n3 <= n4);
    CPPUNIT_ASSERT(n3 < n4);
    CPPUNIT_ASSERT(n4 > n3);
    CPPUNIT_ASSERT(n4 >= n3);
    CPPUNIT_ASSERT(n2 >= n3);
    CPPUNIT_ASSERT(n3 < n2);


    biginteger n5 = 1659648673241354468;
    biginteger n6 = 1959648676241354268;
    CPPUNIT_ASSERT(n5 <= n6);
    CPPUNIT_ASSERT(n5 < n6);
    CPPUNIT_ASSERT(!(n5 >= n6));
    CPPUNIT_ASSERT(!(n5 > n6));
}
