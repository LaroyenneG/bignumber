//
// Created by Guillaume LAROYENNE on 28/10/18.
//

#include "TestPrimeFactory.h"

TestPrimeFactory::TestPrimeFactory(std::string string) : TestCase(string) {

}

void TestPrimeFactory::runTest() {

    CPPUNIT_ASSERT(prime_numbers_factory::pow(3, 9) == 19683);
    CPPUNIT_ASSERT(prime_numbers_factory::sqrt(1548948) == 1244);

    CPPUNIT_ASSERT(prime_numbers_factory::number_to_string(1245345698745632145) == "1245345698745632145");
    CPPUNIT_ASSERT(prime_numbers_factory::number_to_string(124534569874563214) == "124534569874563214");


    prime_numbers_factory *factory = prime_numbers_factory::get_instance();

    CPPUNIT_ASSERT(factory != nullptr);
    CPPUNIT_ASSERT(factory->size() >= NUMBERS_MAX);


    CPPUNIT_ASSERT(!prime_numbers_factory::is_prime(2));
    CPPUNIT_ASSERT(!prime_numbers_factory::is_prime(22));
    CPPUNIT_ASSERT(!prime_numbers_factory::is_prime(25));
    CPPUNIT_ASSERT(!prime_numbers_factory::is_prime(6));

    CPPUNIT_ASSERT(prime_numbers_factory::is_prime(3));
    CPPUNIT_ASSERT(prime_numbers_factory::is_prime(5));
    CPPUNIT_ASSERT(prime_numbers_factory::is_prime(7));
    CPPUNIT_ASSERT(prime_numbers_factory::is_prime(11));


    std::vector<std::string> vector;
    vector.reserve(1000);

    int count = 0;

    for (int i = 0; i < 1000; ++i) {
        vector.push_back(prime_numbers_factory::number_to_string(factory->random_number()));
        CPPUNIT_ASSERT(vector[i].size() == NUMBER_SIZE);
    }

    for (int i = 0; i < vector.size(); ++i) {
        for (int j = 0; j < vector.size(); ++j) {
            if (i != j && vector[i] == vector[j]) {
                count++;
            }
        }
    }


    CPPUNIT_ASSERT(count < 10);

    CPPUNIT_ASSERT(prime_numbers_factory::is_prime(factory->get_prime_number()));

    delete factory;
}
