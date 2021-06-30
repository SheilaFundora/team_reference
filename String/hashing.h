
#include <iostream>
#include <cmath>

using namespace std;
typedef unsigned long long ull;

const ull base = 37ull;

ull hashing( string & cad ){
    int j = cad.size();

    ull hash = 0ull;

    for(char i : cad){
        hash += ('a' - i) * pow( base, j-- );
    }

    return hash;
}