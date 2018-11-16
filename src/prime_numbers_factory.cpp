//
// Created by Guillaume LAROYENNE on 28/10/18.
//


#include "prime_numbers_factory.h"

namespace bignumber {

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

        if (n % 2 == 0 || ((n > 11) && (n % 3 == 0 || n % 5 == 0 || n % 7 == 0 || n % 11 == 0))) {
            return false;
        }

        const auto i_max = sqrt(n);

        for (biginteger i = 3; i <= i_max; i += 2) {
            if (n % i == 0) {
                return false;
            }
        }

        return true;
    }

    biginteger prime_numbers_factory::random_number() const {

        static char digits[] = {3, 5, 7, 9};

        auto n = static_cast<biginteger>(digits[rand() % (sizeof(digits) / sizeof(char))]);

        const auto size = NUMBER_SIZE - 1;

        for (int p = 1; p < size; ++p) {
            n += pow(10, static_cast<unsigned int>(p)) * static_cast<biginteger>((rand() % 10));
        }

        n += pow(10, size) * static_cast<biginteger>((rand() % 9) + 1);

        return n;
    }

    std::string prime_numbers_factory::number_to_string(biginteger n) {

        std::string string;
        string.reserve(NUMBER_SIZE);

        while (n > 0) {
            // string.insert(string.begin(), static_cast<char>('0' + (n % 10)));
            n /= 10;
        }

        return string;
    }

    biginteger prime_numbers_factory::pow(int a, unsigned int p) {

        auto n = static_cast<biginteger>(a);

        for (int i = 1; i < p; ++i) {
            n *= a;
        }

        return n;
    }

    biginteger prime_numbers_factory::sqrt(biginteger n) {

        biginteger x = n;
        biginteger y = 1;

        while (x > y) {
            x = (x + y) / 2;
            y = n / x;
        }

        return x;
    }

    biginteger prime_numbers_factory::build_prime_number() const {

        biginteger n = random_number();

        while (!is_prime(n)) {

            if (n + 2 > n) {
                n += 2;
            } else {
                n = random_number();
            }
        }

        return n;
    }


    void prime_numbers_factory::load_prime_numbers() {

        prime_numbers.clear();

        while (prime_numbers.size() < NUMBERS_MAX) {

            std::thread t1([this]() {
                this->add_prime_number();
            });

            std::thread t2([this]() {
                this->add_prime_number();
            });

            std::thread t3([this]() {
                this->add_prime_number();
            });

            std::thread t4([this]() {
                this->add_prime_number();
            });

            std::thread t5([this]() {
                this->add_prime_number();
            });

            std::thread t6([this]() {
                this->add_prime_number();
            });

            std::thread t7([this]() {
                this->add_prime_number();
            });

            std::thread t8([this]() {
                this->add_prime_number();
            });


            t1.join();
            t2.join();
            t3.join();
            t4.join();
            t5.join();
            t6.join();
            t7.join();
            t8.join();
        }
    }

    biginteger prime_numbers_factory::get_prime_number() const {

        if (prime_numbers.empty()) {
            return 0;
        }

        return prime_numbers[rand() % prime_numbers.size()];
    }

    size_t prime_numbers_factory::size() const {
        return prime_numbers.size();
    }

    void prime_numbers_factory::add_prime_number() {

        static std::mutex mutex;

        biginteger n = build_prime_number();

        mutex.lock();

        prime_numbers.push_back(n);

        mutex.unlock();
    }
}


