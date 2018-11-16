//
// Created by Guillaume LAROYENNE on 16/11/18.
//

#ifndef BIGNUMBER_TESTDIVBIGINTEGER_H
#define BIGNUMBER_TESTDIVBIGINTEGER_H


#include <cppunit/TestCase.h>
#include "../src/biginteger.h"

using namespace bignumber;

class TestDivBiginteger : public CppUnit::TestCase {

public:
    explicit TestDivBiginteger(std::string string);

    void runTest() override;
};


#endif //BIGNUMBER_TESTDIVBIGINTEGER_H
