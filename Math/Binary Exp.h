#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll binpow_mod( ll a, ll b, ll m ){
    ll res = 1ll;
    while( b > 0 ){
        if( b & 1 )
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

ll binpow( ll a, ll b ){
    ll res = 1ll;
    while( b > 0 ){
        if( b & 1 )
            res = res * a; // res = res * a % m
        a = a * a; // a = a * a % m
        b >>= 1;
    }
    return res;
}

