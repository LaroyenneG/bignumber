//
// Created by Guillaume LAROYENNE on 29/10/18.
//

#include "biginteger.h"

namespace bignumber {

    /*
     * Definition : [ 1 2 3 4 5 0 0 0 ] -
     */

    const unsigned short biginteger::BASE = static_cast<const unsigned short>(pow(2, sizeof(unsigned short) * 8) - 1);

    biginteger::biginteger() : table(new unsigned short[1]), size(1), sign(true) {
        table[0] = 0;
    }

    biginteger::biginteger(const std::string &value) : biginteger() {
    }


    biginteger::biginteger(const biginteger &number) : biginteger() {

        const unsigned int n_length = number.length();

        realloc(n_length);

        for (unsigned int i = 0; i < n_length; ++i) {
            table[i] = number.table[i];
        }

        sign = number.sign;
    }


    biginteger::biginteger(long long n) : biginteger() {

        if (n < 0) {
            sign = false;
            n = -n;
        }

        realloc(10);

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

        for (long i = length() - 1; i >= 0; --i) {

            string += std::to_string(table[i]);

            if (i + 1 < length()) {
                string += ' ';
            }
        }

        return string;
    }


    biginteger biginteger::simple_add(const biginteger &n1, const biginteger &n2) {

        biginteger result;

        const unsigned int n1_length = n1.length();
        const unsigned int n2_length = n2.length();

        result.realloc((n1_length > n2_length) ? n1_length + 1 : n2_length + 1);

        for (int i = 0; i < n1_length; ++i) {
            result.table[i] = n1.table[i];
        }

        for (int i = 0; i < n2_length; ++i) {

            int j = i;

            long long n = n2.table[i];

            do {

                n += result.table[j];

                result.table[j] = static_cast<unsigned short>(n % BASE);

                n /= BASE;

                j++;

            } while (n > 0);
        }

        return result;
    }

    biginteger biginteger::simple_sub(const biginteger &n1, const biginteger &n2) {

        biginteger result;

        const unsigned int n1_length = n1.length();
        const unsigned int n2_length = n2.length();

        result.realloc((n1_length > n2_length) ? n1_length : n2_length);

        for (int i = 0; i < n1_length; ++i) {
            result.table[i] = n1.table[i];
        }

        for (int i = 0; i < n2_length; ++i) {

            int j = i;

            long long n = n2.table[i];

            do {
                n = result.table[j] - n;

                result.table[j] = static_cast<unsigned short>(n % BASE);

                n /= BASE;

                j++;

            } while (n > 0);
        }

        return result;
    }

    biginteger biginteger::simple_mult(const biginteger &n1, const biginteger &n2) {

        biginteger result;

        if (n1 < n2) {
            for (biginteger i; i < n1; i++) {
                result = simple_add(result, n2);
            }
        } else {
            for (biginteger i; i < n2; i++) {
                result = simple_add(result, n1);
            }
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

        for (unsigned int i = 0; i < n1_length; ++i) {

            if (n1.table[i] > n2.table[i]) {
                return true;
            }
            if (n1.table[i] < n2.table[i]) {
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


        for (unsigned int i = 0; i < n1_length; ++i) {

            if (n1.table[i] < n2.table[i]) {
                return true;
            }
            if (n1.table[i] > n2.table[i]) {
                return false;
            }
        }

        return false;

    }

    bool biginteger::equals(const biginteger &number) const {

        const unsigned int n_length = number.length();
        const unsigned int t_length = length();

        if (sign != number.sign) {
            return false;
        }

        if (t_length != n_length) {
            return false;
        }

        for (int i = 0; i < t_length; ++i) {
            if (table[i] != number.table[i]) {
                return false;
            }
        }

        return true;
    }


    unsigned int biginteger::length() const {

        unsigned int count = 0;

        bool head = true;

        for (long i = size - 1; i >= 0; --i) {

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
     * operators
     */

    biginteger biginteger::operator+(const biginteger &number) const {

        if (sign && !number.sign) {
            return *this - number;
        }

        if (!sign && number.sign) {
            return number - *this;
        }

        if (!sign && !number.sign) {
            return -simple_add(*this, number);
        }

        return simple_add(*this, number);
    }

    biginteger biginteger::operator-(const biginteger &number) const {

        if (sign && !number.sign) {
            return simple_add(*this, number);
        }

        if (!sign && number.sign) {
            return -simple_add(*this, number);
        }

        if (*this < number) {
            return -simple_sub(number, *this);
        }

        return simple_sub(*this, number);
    }

    biginteger biginteger::operator/(const biginteger &number) const {
        return biginteger();
    }

    biginteger biginteger::operator%(const biginteger &number) const {
        return biginteger();
    }

    biginteger biginteger::operator*(const biginteger &number) const {

        biginteger result = simple_mult(*this, number);

        if (sign != number.sign) {
            result.sign = false;
        }

        return result;
    }

    bool biginteger::operator==(const biginteger &number) const {
        return equals(number);
    }

    bool biginteger::operator!=(const biginteger &number) const {
        return !equals(number);
    }

    bool biginteger::operator>(const biginteger &number) const {

        if (sign && !number.sign) {
            return true;
        }

        if (!sign && !number.sign) {
            return simple_is_inf(*this, number);
        }

        return simple_is_sup(*this, number);
    }

    bool biginteger::operator<(const biginteger &number) const {

        if (!sign && number.sign) {
            return true;
        }

        if (!sign && !number.sign) {
            return simple_is_sup(*this, number);
        }

        return simple_is_inf(*this, number);
    }

    bool biginteger::operator<=(const biginteger &number) const {

        if (*this == number) {
            return true;
        }

        return *this < number;
    }

    bool biginteger::operator>=(const biginteger &number) const {

        if (*this == number) {
            return true;
        }

        return *this > number;
    }

    biginteger &biginteger::operator+=(const biginteger &number) {

        *this = *this + number;

        return *this;
    }

    biginteger &biginteger::operator-=(const biginteger &number) {

        *this = *this - number;

        return *this;
    }

    biginteger &biginteger::operator/=(const biginteger &number) {

        *this = *this / number;

        return *this;
    }

    biginteger &biginteger::operator*=(const biginteger &number) {

        *this = *this * number;

        return *this;
    }

    const biginteger biginteger::operator++(int) {

        *this += 1;

        return *this;
    }

    const biginteger biginteger::operator--(int) {

        *this -= 1;

        return *this;
    }

    biginteger &biginteger::operator++() {

        *this += 1;

        return *this;
    }


    biginteger &biginteger::operator--() {

        *this -= 1;

        return *this;
    }

    biginteger &biginteger::operator=(const biginteger &number) {

        realloc(number.length());

        for (unsigned int i = 0; i < number.length(); ++i) {
            table[i] = number.table[i];
        }

        sign = number.sign;

        return *this;
    }

    biginteger &biginteger::operator-() {

        sign = !sign;

        return *this;
    }
}