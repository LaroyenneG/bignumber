//
// Created by Guillaume LAROYENNE on 15/11/18.
//

#ifndef BIGNUMBER_TESTINFBIGINTEGER_H
#define BIGNUMBER_TESTINFBIGINTEGER_H


#include <cppunit/TestCase.h>
#include "../src/biginteger.h"

using namespace bignumber;

class TestCompBiginteger : public CppUnit::TestCase {

public:
    explicit TestCompBiginteger(std::string string);

    void runTest() override;
};


#endif //BIGNUMBER_TESTINFBIGINTEGER_H
