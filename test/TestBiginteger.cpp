//
// Created by Guillaume LAROYENNE on 29/10/18.
//

#include <iostream>
#include "TestBiginteger.h"


void simpleSmal() {

    biginteger n1 = 10;
    biginteger n2 = 5;


    CPPUNIT_ASSERT(n1.length() == 1);

    CPPUNIT_ASSERT(n1 == 10);
    CPPUNIT_ASSERT(n2 == 5);
    CPPUNIT_ASSERT(-n2 == -5);

    CPPUNIT_ASSERT(n1 + n2 == 15);
    CPPUNIT_ASSERT(n2 + n1 == 15);

    CPPUNIT_ASSERT(-n2 == -5);

    CPPUNIT_ASSERT(n1 - n2 == 5);

    CPPUNIT_ASSERT(n2 - n1 == -5);
}


void simpleLong() {

    biginteger n1 = 1684684354654341351;
    biginteger n2 = 58786778787887877;

    // CPPUNIT_ASSERT(n1.length() == 4);

    CPPUNIT_ASSERT(n1 == 1684684354654341351);
    CPPUNIT_ASSERT(n2 == 58786778787887877);
    CPPUNIT_ASSERT(-n2 == -58786778787887877);

    CPPUNIT_ASSERT(n1 + n2 == 1743471133442229228);
    CPPUNIT_ASSERT(n2 + n1 == 1743471133442229228);

    CPPUNIT_ASSERT(-n2 == -58786778787887877);

    CPPUNIT_ASSERT(n1 - n2 == 1625897575866453474);

    CPPUNIT_ASSERT(n2 - n1 == -1625897575866453474);
}


TestBignumber::TestBignumber(std::string string) : TestCase(string) {

}


void TestBignumber::runTest() {

    //simpleSmal();

    simpleLong();
}
