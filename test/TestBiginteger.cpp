//
// Created by Guillaume LAROYENNE on 29/10/18.
//
#include <iostream>
#include "TestBiginteger.h"


void simpleTest() {

    biginteger n1 = 10;
    biginteger n2 = 5;

    CPPUNIT_ASSERT(n1.length() == 1);

    CPPUNIT_ASSERT(n1 == 10);
    CPPUNIT_ASSERT(n2 == 5);
    CPPUNIT_ASSERT(-n2 == -5);

    CPPUNIT_ASSERT(n1 + n2 == 15);
    CPPUNIT_ASSERT(n2 + n1 == 15);

    CPPUNIT_ASSERT(n1 - n2 == 5);
    CPPUNIT_ASSERT(n2 - n1 == -5);
}


TestBignumber::TestBignumber(std::string string) : TestCase(string) {

}


void TestBignumber::runTest() {

    simpleTest();
}
