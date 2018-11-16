//
// Created by Guillaume LAROYENNE on 29/10/18.
//

#include "rsa_algo.h"

namespace bignumber {

    rsa_algo::private_key rsa_algo::generate_private_key() {

        prime_numbers_factory *factory = prime_numbers_factory::get_instance();

        private_key pkey;

        pkey.p = factory->get_prime_number();
        pkey.q = factory->get_prime_number();

        return pkey;
    }

    rsa_algo::public_key rsa_algo::generate_public_key(rsa_algo::private_key pkey) {

        prime_numbers_factory *factory = prime_numbers_factory::get_instance();

        public_key key;

        key.n = pkey.p * pkey.q;
        key.e = factory->get_prime_number();

        return key;
    }
}