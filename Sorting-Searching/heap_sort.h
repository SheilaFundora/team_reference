
#include <vector>

using namespace std;

vector< int > arr;

void heapfy( int node, int size ){

    int largest = node;
    int left = 2 * node + 1;
    int right = 2 * node + 2;

    if( left < size && arr[ left ] > arr[ largest ] ){
        largest = left;
    }

    if( right < size && arr[ right ] > arr[ largest ] ){
        largest = right;
    }

    if( largest != node ){
        swap( arr[ largest ], arr[ node ] );
        heapfy( largest , size );
    }

}

void heap_sort(){
    for( int i = arr.size()/2 - 1; i > 0; i-- ){
        heapfy( i, arr.size() );
    }
    heapfy( 0, arr.size() );

    for( int i = arr.size() - 1; i >= 0; i-- ){
        swap( arr[ 0 ], arr[ i ] );
        heapfy( 0, i );
    }
}

//region main
/*
#include <bits/stdc++.h>
#include "Sorting-Searching/heap_sort.h"

using namespace std;

int main(){
    auto start = chrono::system_clock::now();

    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );

    freopen( "../Input/heap.in", "r", stdin );

    int x;
    while( cin >> x ){
        arr.push_back( x );
    }

    for( int & it: arr )cout <<it <<' ';
    cout <<'\n';

    heap_sort();

    for( int & it: arr ) cout <<it <<' ';
    cout <<'\n';


    cout <<"\nTime: " <<( chrono::system_clock::now() - start).count()/1e9;
    return 0;
}
*/
//endregion