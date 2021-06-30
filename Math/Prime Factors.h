#include "Sieve of Eratosthine.h"
#include <map>
#include <cmath>

map< int, int > primes_factors;

void prime_factors( int num ){
    primes_factors.clear();

    int pf_index = 0, prime_f = primes[ pf_index ];

    while( prime_f * prime_f < num ){
        while( num % prime_f == 0 ){
            primes_factors[ prime_f ]++;
            num /= prime_f;
        }
        prime_f = primes[ ++pf_index ];
    }

    if( num != 1 ) primes_factors[ num ] ++; //
}

int num_of_divisors( int num ){

    int pf_index = 0, prime_f = primes[ pf_index ];

    int num_of_div = 1;

    while( prime_f * prime_f < num ){
        int exp = 0;
        while( num % prime_f == 0 ){
            exp++;
            num /= prime_f;
        }
        num_of_div *= ( exp + 1 );
        prime_f = primes[ ++pf_index ];
    }

    if( num != 1 ) num_of_div *= 2;

    return num_of_div;
}

ll sum_of_divisors( ll num ){
    ll pf_intdex = 0ll, prime_f = primes[ 0 ];

    ll sum_div = 1ll;

    while( prime_f * prime_f < num ){
        int exp = 0;
        while( num % prime_f == 0 ){
            exp++;
            num /= prime_f;
        }
        sum_div *= (( (ll) pow( (double)prime_f, exp + 1.0 ) - 1 )/ ( prime_f - 1 ));
        prime_f = primes[ ++pf_intdex ];
    }

    if( num != 1 ){
        auto p = pow( double(num) , 2.0 );
        sum_div *= (ll)( ((p) - 1) / ( num - 1));
    }

    return sum_div;
}


int sum_of_div2( int num )