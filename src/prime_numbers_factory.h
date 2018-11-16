//
// Created by Guillaume LAROYENNE on 28/10/18.
//

#ifndef ARIDZUKA_PRIME_NUMBERS_FACTORY_H
#define ARIDZUKA_PRIME_NUMBERS_FACTORY_H


#include <vector>
#include <mutex>
#include <iostream>
#include <thread>
#include "biginteger.h"

#define NUMBERS_MAX 100
#define NUMBER_SIZE 19

namespace bignumber {

    class prime_numbers_factory {

    public:
        static prime_numbers_factory *get_instance();

        biginteger random_number() const;

        biginteger get_prime_number() const;

        size_t size() const;

        static bool is_prime(biginteger n);

        static std::string number_to_string(biginteger n);

        static biginteger pow(int a, unsigned int p);

        static biginteger sqrt(biginteger);

    private:
        static prime_numbers_factory *instance;

        void load_prime_numbers();

        void add_prime_number();

        prime_numbers_factory();

        biginteger build_prime_number() const;

        std::vector<biginteger> prime_numbers;

    };
}

#endif //ARIDZUKA_PRIME_NUMBERS_FACTORY_H
