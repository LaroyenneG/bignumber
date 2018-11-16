//
// Created by Guillaume LAROYENNE on 29/10/18.
//

#include <iostream>
#include "biginteger.h"


namespace bignumber {

    /*
     * Definition : [ 1 2 3 4 5 0 0 0 ] -
     */

    const unsigned long long biginteger::BASE = 65535;


    biginteger::biginteger() : table(new unsigned short[1]), size(1), sign(true) {
        table[0] = 0;
    }

    biginteger::biginteger(const std::string &value) : biginteger() {
        exit(-1);
    }

    biginteger::biginteger(const biginteger &number) : table(nullptr), size(0) {

        const unsigned int n_length = number.length();

        alloc(n_length);

        for (unsigned int i = 0; i < n_length; ++i) {
            table[i] = number[i];
        }

        sign = number.sign;
    }


    biginteger::biginteger(long long n) : size(0), table(nullptr) {

        if (n < 0) {
            sign = false;
            n = -n;
        } else {
            sign = true;
        }

        alloc(10);

        int i = 0;
        while (n > 0) {
            table[i] = static_cast<unsigned short>(n % BASE);
            n /= BASE;
            i++;
        }
    }

    biginteger::~biginteger() {
        delete[] table;
    }


    void biginteger::alloc(unsigned int n) {

        delete[] table;

        size = n;

        table = new unsigned short[n];

        for (unsigned int i = 0; i < n; ++i) {
            table[i] = 0;
        }
    }

    void biginteger::realloc(unsigned int n) {

        auto *ntable = new unsigned short[n];
        for (int i = 0; i < n; ++i) {
            ntable[i] = 0;
        }

        for (int i = 0; i < n && i < size; ++i) {
            ntable[i] = table[i];
        }

        delete[] table;

        table = ntable;
        size = n;
    }

    std::string biginteger::to_string() const {

        std::string string;

        if (!sign) {
            string += '-';
        }

        const unsigned int l = length();

        for (long i = l - 1; i >= 0; --i) {

            string += std::to_string(table[i]);

            if (i - 1 >= 0) {
                string += ' ';
            }
        }

        return string;
    }


    biginteger biginteger::simple_add(const biginteger &n1, const biginteger &n2) {

        biginteger result = 0;

        const unsigned int n1_length = n1.length();
        const unsigned int n2_length = n2.length();

        result.realloc((n1_length > n2_length) ? n1_length + 1 : n2_length + 1);

        for (int i = 0; i < n1_length; ++i) {
            result[i] = n1[i];
        }

        for (int i = 0; i < n2_length; ++i) {

            bool flag = false;

            int j = i;

            do {

                unsigned long long a = result[j];
                auto b = static_cast<unsigned long long int>((flag) ? 1 : n2[j]);

                unsigned long long n = a + b;

                flag = n >= BASE;

                result[j] = static_cast<unsigned short>(n % BASE);

                j++;

            } while (flag);
        }

        return result;
    }

    biginteger biginteger::simple_sub(const biginteger &n1, const biginteger &n2) {


        biginteger result = 0;

        const unsigned int n1_length = n1.length();
        const unsigned int n2_length = n2.length();

        result.realloc(n1_length);

        for (int i = 0; i < n1_length; ++i) {
            result[i] = n1[i];
        }

        for (int i = 0; i < n2_length; ++i) {

            int j = i;

            bool flag = false;

            do {

                unsigned long long a = result[j];
                auto b = static_cast<unsigned long long int>((flag) ? 1 : n2[j]);

                unsigned long long n;
                if (a < b) {
                    n = BASE - (b - a);
                    flag = true;
                } else {
                    n = a - b;
                    flag = false;
                }

                result[j] = static_cast<unsigned short>(n % BASE);

                j++;

            } while (flag);
        }

        return result;
    }

    biginteger biginteger::simple_mult(const biginteger &n1, const biginteger &n2) {

        const unsigned int n1_length = n1.length();
        const unsigned int n2_length = n2.length();

        biginteger result = 0;

        for (int i = 0; i < n2_length; ++i) {

            biginteger adder = 0;

            adder.realloc(n1_length + n2_length);

            unsigned long long r = 0;

            for (int j = 0; j < n1_length; ++j) {

                unsigned long long n = n1[j] * n2[i] + r;

                adder[j + i] = static_cast<unsigned short>(n % BASE);

                r = n / BASE;
            }

            adder[adder.length()] = static_cast<unsigned short>(r);

            result = simple_add(adder, result);
        }


        return result;
    }

    bool biginteger::simple_is_sup(const biginteger &n1, const biginteger &n2) {


        const unsigned int n1_length = n1.length();
        const unsigned int n2_length = n2.length();

        if (n1_length > n2_length) {
            return true;
        }

        if (n1_length < n2_length) {
            return false;
        }

        for (unsigned int i = n1_length - 1; i >= 0; --i) {

            if (n1[i] > n2[i]) {
                return true;
            }
            if (n1[i] < n2[i]) {
                return false;
            }
        }

        return false;
    }

    bool biginteger::simple_is_inf(const biginteger &n1, const biginteger &n2) {

        const unsigned int n1_length = n1.length();
        const unsigned int n2_length = n2.length();


        if (n1_length < n2_length) {
            return true;
        }

        if (n1_length > n2_length) {
            return false;
        }


        for (unsigned int i = n1_length - 1; i >= 0; --i) {

            if (n1[i] < n2[i]) {
                return true;
            }
            if (n1[i] > n2[i]) {
                return false;
            }
        }

        return false;

    }

    bool biginteger::equals(const biginteger &n) const {

        const unsigned int n_length = n.length();
        const unsigned int t_length = length();

        if (sign != n.sign) {
            return false;
        }

        if (t_length != n_length) {
            return false;
        }

        for (int i = 0; i < t_length; ++i) {
            if (table[i] != n[i]) {
                return false;
            }
        }

        return true;
    }

    biginteger biginteger::simple_div(const biginteger &n1, const biginteger &n2) {

        biginteger a = n1;
        biginteger r = n1;

        biginteger q = 0;

        while (r >= n2) {
            r = a - n2;
            a = r;
            q++;
        }

        return q;
    }

    unsigned int biginteger::length() const {

        unsigned int count = 1;

        bool head = true;

        for (long i = size - 1; i > 0; --i) {

            if (head && table[i] != 0) {
                head = false;
            }

            if (!head) {
                count++;
            }
        }

        return count;
    }

    /*
     * Static tools functions
     */

    biginteger biginteger::sqrt(const biginteger &n) {

        biginteger x = n;
        biginteger y = 1;

        while (x > y) {
            x = (x + y) / 2;
            y = n / x;
        }

        return x;
    }


    biginteger biginteger::pow(const biginteger &n, unsigned long long int p) {

        biginteger x = n;

        biginteger result = 1;

        while (p != 0) {
            if (p % 2 == 0) {
                x *= x;
                p >>= 1;
            } else {
                result *= x;
                p--;
            }
        }

        return n;
    }


    /*
     * Operators
     */

    biginteger biginteger::operator+(const biginteger &n) const {

        if (sign && !n.sign) {
            return *this - n;
        }

        if (!sign && n.sign) {
            return n - *this;
        }

        if (!sign && !n.sign) {
            return -simple_add(*this, n);
        }

        return simple_add(*this, n);
    }

    biginteger biginteger::operator-(const biginteger &n) const {

        if (sign && !n.sign) {
            return simple_add(*this, n);
        }

        if (!sign && n.sign) {
            return -simple_add(*this, n);
        }

        if (*this <= n) {
            return -simple_sub(n, *this);
        }

        return simple_sub(*this, n);
    }

    biginteger biginteger::operator/(const biginteger &n) const {

        biginteger result = simple_div(*this, n);

        result.sign = sign == n.sign;

        return result;
    }

    biginteger biginteger::operator%(const biginteger &n) const {

        biginteger result = *this - n * (*this / n);

        return result;
    }

    biginteger biginteger::operator*(const biginteger &n) const {

        biginteger result = (*this >= n) ? simple_mult(*this, n) : simple_mult(n, *this);

        result.sign = sign == n.sign;

        return result;
    }

    bool biginteger::operator==(const biginteger &n) const {
        return equals(n);
    }

    bool biginteger::operator!=(const biginteger &n) const {
        return !equals(n);
    }

    bool biginteger::operator>(const biginteger &n) const {

        if (sign && !n.sign) {
            return true;
        }

        if (!sign && !n.sign) {
            return simple_is_sup(n, *this);
        }

        return simple_is_sup(*this, n);
    }

    bool biginteger::operator<(const biginteger &n) const {

        if (!sign && n.sign) {
            return true;
        }

        if (!sign && !n.sign) {
            return simple_is_inf(n, *this);
        }

        return simple_is_inf(*this, n);
    }

    bool biginteger::operator<=(const biginteger &n) const {

        if (*this == n) {
            return true;
        }

        return *this < n;
    }

    bool biginteger::operator>=(const biginteger &n) const {

        if (*this == n) {
            return true;
        }

        return *this > n;
    }

    biginteger &biginteger::operator+=(const biginteger &n) {

        *this = *this + n;

        return *this;
    }

    biginteger &biginteger::operator-=(const biginteger &n) {

        *this = *this - n;

        return *this;
    }

    biginteger &biginteger::operator/=(const biginteger &n) {

        *this = *this / n;

        return *this;
    }

    biginteger &biginteger::operator*=(const biginteger &n) {

        *this = *this * n;

        return *this;
    }

    const biginteger biginteger::operator++(int) {

        const biginteger n = *this;

        *this = *this + 1;

        return n;
    }

    const biginteger biginteger::operator--(int) {

        const biginteger n = *this;

        *this -= 1;

        return n;
    }

    biginteger &biginteger::operator++() {

        *this += 1;

        return *this;
    }


    biginteger &biginteger::operator--() {

        *this -= 1;

        return *this;
    }

    biginteger biginteger::operator-() const {

        biginteger n = *this;

        n.sign = !sign;

        return n;
    }

    std::ostream &operator<<(std::ostream &os, const biginteger &n) {

        os << n.to_string();

        return os;
    }

    unsigned short &biginteger::operator[](unsigned int n) const {

        if (n >= size) {
            throw std::out_of_range("invalid digit index");
        }

        return table[n];
    }

    biginteger &biginteger::operator=(const biginteger &n) {

        sign = n.sign;

        alloc(n.length());

        for (int i = 0; i < size; ++i) {
            table[i] = n[i];
        }

        return *this;
    }

    biginteger::operator long long() {

        return 0;
    }
}