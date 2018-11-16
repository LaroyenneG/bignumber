//
// Created by Guillaume LAROYENNE on 28/10/18.
//


#include "prime_numbers_factory.h"

namespace bignumber {

    const biginteger prime_numbers_factory::PRIME_NUMBERS[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47,
                                                               53, 59, 61, 67, 71};

    prime_numbers_factory *prime_numbers_factory::instance = nullptr;

    prime_numbers_factory::prime_numbers_factory() {

        prime_numbers.reserve(NUMBERS_MAX);

        srand(static_cast<unsigned int>(time(nullptr)));

        load_prime_numbers();
    }

    prime_numbers_factory *prime_numbers_factory::get_instance() {

        static std::mutex mutex;

        mutex.lock();

        if (instance == nullptr) {
            instance = new prime_numbers_factory();
        }

        mutex.unlock();

        return instance;
    }


    bool prime_numbers_factory::is_prime(biginteger n) {

        for (const biginteger &p : PRIME_NUMBERS) {
            if (n % p == 0) {
                return false;
            }
        }

        const auto i_max = biginteger::sqrt(n);

        for (biginteger i = PRIME_NUMBERS[PRIME_NUMBERS_SIZE - 1] + 2; i <= i_max; i += 2) {
            if (n % i == 0) {
                return false;
            }
        }

        return true;
    }

    biginteger prime_numbers_factory::random_number() const {

        static const char digits[] = {'3', '5', '7', '9'};

        std::string number;

        number.reserve(NUMBER_DIGITS_SIZE);

        const auto size = NUMBER_DIGITS_SIZE;

        for (int i = 1; i < size; ++i) {
            number += std::to_string(random() % 10);
        }

        number += digits[random() % 4];

        return biginteger(number);
    }

    biginteger prime_numbers_factory::build_prime_number() const {

        biginteger n = random_number();

        while (!is_prime(n)) {
            n += 2;
        }

        return n;
    }


    void prime_numbers_factory::load_prime_numbers() {

        prime_numbers.clear();

        auto **threads = new std::thread *[NUMBERS_MAX];

        for (int i = 0; i < NUMBERS_MAX; i++) {

            threads[i] = new std::thread([this]() {
                this->add_prime_number();
            });
        }

        for (int i = 0; i < NUMBERS_MAX; ++i) {
            threads[i]->join();
        }

        delete[] threads;
    }

    biginteger prime_numbers_factory::get_prime_number() const {

        if (prime_numbers.empty()) {
            return 0;
        }

        return prime_numbers[random() % prime_numbers.size()];
    }

    size_t prime_numbers_factory::size() const {
        return prime_numbers.size();
    }

    void prime_numbers_factory::add_prime_number() {

        static std::mutex mutex;

        biginteger n = build_prime_number();

        mutex.lock();

        prime_numbers.push_back(n);

        std::cout << prime_numbers.size() << std::endl;

        mutex.unlock();
    }
}


