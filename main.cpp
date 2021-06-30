#include <bits/stdc++.h>
#include "boost/graph/grid_graph.hpp"

using namespace boost::graph;

using namespace std;

int MAX = 100001;
typedef long long ll;

int main(){


    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );

    auto start =  chrono::system_clock::now();
    freopen( "Input/prob7.in", "r", stdin );


    int N;
    cin >>N;

    int aux = N;


    ll sum = 0;

    int arr[ MAX ];

    for(int & i : arr){
        i = 0;
    }

    int x;
    while( aux-- ){
        cin >>x;
        switch( arr[ x ] ){
            case 0:
                arr[ x ] = 1;
                break;
            case 1:
                arr[ x ] = 2;
            default:
                break;
        }
    }

    for( int i = 0; i < MAX; i++ ){
        if( arr[ i ] == 1 ){
            sum += i;
        }
    }

    cout <<sum <<'\n';

    cout <<"\ntime: " << (chrono::system_clock::now() - start).count()/1e9 << " s";
    return 0;
}
