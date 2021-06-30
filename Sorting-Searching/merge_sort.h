#include <array>
#include <vector>

using namespace std;

const int MAX = int( 1e3 );

array< int, MAX > aux;
vector< int > arr;

void merge( int L, int mid, int R ){

    int i = L, j = mid + 1;
    int k = L;
    while( i <= mid && j <= R ){
        if( arr[ i ] > arr[ j ] ){
            aux[ k++ ] = arr[ j++ ];
        }else{
            aux[ k++ ] = arr[ i++ ];
        }
    }

    while( i <= mid ){
        aux[ k++ ] = arr[ i++ ];
    }

    while( j <= R ){
        aux[ k++ ] = arr[ j++ ];
    }

    i = L;
    while( i <= R ){
        arr[ i ] = aux[ i ];
        i++;
    }
}

void merge_sort( int L, int R ){
    if( L == R )return;

    int mid = ( L + R )>>1;

    merge_sort( L, mid );
    merge_sort( mid + 1, R );

    merge( L, mid, R );
}

//region main

/*
#include <bits/stdc++.h>
#include "Sorting-Searching/merge_sort.h"

using namespace std;

int main(){
    auto start = chrono::system_clock::now();

    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );

    freopen( "../Input/merge_sort.in", "r", stdin );

    int n;
    cin >>n;

    while( n-- ){
        int x;
        cin >>x;
        arr.push_back( x );
    }

    merge_sort( 0, arr.size() - 1 );

    for( auto & it: arr ){
        cout <<it <<' ';
    }



    cout <<"\nTime: " <<( chrono::system_clock::now() - start).count()/1e9;
    return 0;
}
*/

//endregion