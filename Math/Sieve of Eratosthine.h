#include <vector>
#include <bitset>

using namespace std;

const int MAX = int( 1e6 );
typedef long long ll;

vector< int > primes;
bitset< MAX > is_prime;

void sieve(){

    is_prime.set();
    is_prime[ 0 ] = is_prime[ 1 ] = false;

    for ( ll i = 2; i < MAX; i++ ){
        if( is_prime[ i ] ){
            for( ll j = i * i; j < MAX; j += i ){
                is_prime[ j ] = false;
            }
            primes.push_back( int( i ) );
        }
    }
}

bool is_Prime( int num){ //works up to  num < last_prime * last_prime
    if( num < MAX ){
        return is_prime[ num ];
    }else{
        for( int & it: primes )
            if( num % it == 0 ){
                return false;
            }
    }
    return  true;
}