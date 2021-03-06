//
// Created by Guillaume LAROYENNE on 15/11/18.
//

#ifndef BIGNUMBER_TESTADDBIGINTEGER_H
#define BIGNUMBER_TESTADDBIGINTEGER_H

#include "../src/biginteger.h"
#include <cppunit/TestCase.h>

using namespace bignumber;

class TestAddBiginteger : public CppUnit::TestCase {

public:
    explicit TestAddBiginteger(std::string string);

    void runTest() override;
};


#endif //BIGNUMBER_TESTADDBIGINTEGER_H
