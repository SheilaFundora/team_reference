#include <iostream>
#include <exception>
#include <stdexcept>
#include <deque>

using namespace std;

template < class T >
class max_heap{

private:
    vector< T > arr;

    void heapfy( int index_root, unsigned int size ){

        int largest = index_root;
        int left = 2 * index_root + 1;
        int right = 2 * index_root + 2;

        if( left < size && arr[ left ] > arr[ largest ] )
            largest = left;

        if( right < size && arr[ right ] > arr[ largest ] )
            largest = right;

        if( index_root != largest ){
            swap( arr[ index_root ], arr[ largest ] );
            heapfy( largest, size );
        }
    }

    bool is_sorted;

    void make_heap(){
        for( int i = arr.size() / 2; i >= 0; i-- ){
            heapfy( i, arr.size() );
        }
    }

    void fix(){
        this->reverse_arr();
        make_heap();
    }


public:
    max_heap(){
        is_sorted = false;
    }

    max_heap( vector< T > & list ):max_heap(){
        arr = list;
        this->make_heap();

        if( !arr.empty() )
            swap( arr[ 0 ], arr.back() );

    }

    //O( log( n ) )
    void push( T obj ){
        if( is_sorted ) fix();

        if( !arr.empty() )
            swap( arr[ 0 ], arr.back() );

        arr.push_back( obj );

        for( int i = ( arr.size() - 1 ) / 2; i > 0; i/=2 ){
            heapfy( i , arr.size() );
        }

        heapfy( 0, arr.size() );

        swap( arr[ 0 ], arr.back() );
    }

    //O( 1 )
    T top(){
        if( is_sorted ) fix();

        if(  arr.empty() ){
            throw exception();
        }
        return arr.back();
    }

    //O( log( n ) )
    void pop(){

        if( is_sorted ) fix();

        if(  arr.empty() ){
            throw exception();
        }
        arr.pop_back();

        heapfy( 0 );
        if( !arr.empty() )
            swap( arr[ 0 ], arr.back() );
    }

    void sort( ){

        if( !is_sorted ){
            swap( arr[ 0 ], arr.back() );

            for( int i = arr.size() - 1; i >= 0; i-- ) {
                swap( arr[ 0 ], arr[ i ] );
                heapfy( 0, i );
            }
        }

        is_sorted = true;
    }

    void reverse_arr(){
        reverse( arr.begin(), arr.end() );
    }

    //for Debug
    void printArr(){
        for( T & it: arr ){
            cout <<it <<' ';
        }
        cout <<'\n';
    }

};

//region main
/*
#include <bits/stdc++.h>
#include "Sorting-Searching/max_heap.h"

using namespace std;

int main(){
    auto start = chrono::system_clock::now();

    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );

    freopen( "../Input/heap.in", "r", stdin );

    vector< int > v;

    int x;
    max_heap< int > pq;
    while( cin >> x ){
        pq.push( x );
    }


    pq.printArr();

    cout <<pq.top() <<'\n';

//    pq.pop();

//    pq.printArr();

    pq.push( 6 );

    pq.sort();

    pq.printArr();



    cout <<"\nTime: " <<( chrono::system_clock::now() - start).count()/1e9;
    return 0;
}

*/
//endregion