#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;


class sqrt_root{
private:
    vector< int > blocks;
    vector< int > arr;
    int k;

    void fill_blocks(){
        int sum = 0;

        for( int i = 1; i <= arr.size(); i ++ ){

            sum += arr[ i - 1 ];

            if( i % k == 0){
                blocks.push_back( sum );
                sum = 0;
            }
        }
    }

public:

    explicit sqrt_root( vector< int > & v ){
        k = int( sqrt( double( v.size() ) ) );
        arr = v;
        fill_blocks();
    }

    void update( int index, int val ){
        blocks[ index / k ] += val - arr[ index ];
        arr[ index ] = val;
    }

    int query( int left, int right ){
        //if the indexes are in the same block
        //or there is no block between them
        int sum = 0;

        if( ( right / k == left / k ) || abs( ( right/k ) - ( left / k ) ) == 1 ){
            for( int i = left; i <= right; i++ ){
                sum += arr[ i ];
            }
            return sum;
        }

        for( int i = left; i % k != 0; i++ )
            sum += arr[ i ];

        int j = right;
        for( ; j % k != 0; j-- )
            sum += arr[ j ];

        //The mod == 0 belongs to the right part;
        sum += arr[ j ];

        for( int i = left/k + ( left % k == 0 ? 0 : 1 ); i < right/k; i++ ){
            sum += blocks[ i ];
        }
        return sum;
    }

    void printBlocks(){
        for( int & it: blocks ){
            cout <<it <<' ';
        }
        cout <<'\n';
    }
};


//region main
/*
#include <bits/stdc++.h>
#include "Data Structure/Square Root.h"

using namespace std;

int main(){
    auto start = chrono::system_clock::now();

    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );

    freopen( "../Input/square_root.in", "r", stdin );

    int n;
    cin >>n;

    vector< int > arr;

    while( n-- ){
        int x;
        cin >>x;
        arr.push_back( x );
    }

    sqrt_root sqrtRoot( arr );

    //Test query
    int i, j;
    while( cin >> i >>j ){

        int sum = 0;
        for( int l = i; l <= j; l++ ){
            sum += arr[ l ];
        }

        cout <<(sqrtRoot.query( i, j ) == sum) <<' ';
    }


//update test
    int i, j;
    while( cin >>i >>j ){
        sqrtRoot.update( i, j );
        sqrtRoot.printBlocks();
    }



cout <<"\nTime: " <<( chrono::system_clock::now() - start).count()/1e9;
return 0;
}
*/

//endregion






