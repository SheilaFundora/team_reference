
const int MAX = 65;

long long pascal[ MAX ][ MAX ];

void prep_pascal(){

    for( int i = 0; i < MAX; i++ ){
        for( int j = 0; j < MAX; j++ ){

            if( i == j ){
                pascal[ i ] [ j ]  = 1;
                j = MAX + 1;// break
            }
            if( j == 0 ) pascal[ i ][ j ] = 1;

            pascal[ i ][ j ] = pascal[ i - 1 ][ j - 1 ] +
                    pascal[ i - 1 ][ j ];
        }
    }
}

//region main
/*
#include <bits/stdc++.h>
#include "Math/Binomial Coefficients.h"
using namespace std;

int main(){
    auto start = chrono::system_clock::now();

    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );

    //freopen( "../Input/trie.in", "r", stdin );

    prep_pascal();

    for( int i = 0; i < 15; i++ ){
        for( int j = 0; j < 15; j++ ){
            if( i == j ){
                cout <<pascal[ i ][ j ] <<'\n';
                break;
            }
            cout <<pascal[ i ][ j ] <<' ';
        }
    }


    cout <<"\nTime: " <<( chrono::system_clock::now() - start).count()/1e9;
    return 0;
}

 */
//endregion