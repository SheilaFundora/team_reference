#include <algorithm>

using namespace std;

#ifndef MAX
#define MAX int( 1e3 )
#endif

#ifndef INF
#define INF int( 1<<28 );
#endif

int graph[ MAX ][ MAX ];

void init(){
    for( auto & fil: graph ){
        for( int & it: fil ){
            it = INF;
        }
    }
}


void floyd_warshall( int n ){
    for( int k = 0; k < n; k++ ){
        for( int i = 0; i < n; i++ ){
            for( int j = 0; j < n; j++ ){
                graph[ i ][ j ] = min( graph[ i ][ j ], graph[ i ][ k ] + graph[ j ][ k ] );
            }
        }
    }
}

//region main
/*
#include <bits/stdc++.h>

#include "Graph Theory/Floyd Warshall.h"

using namespace std;

int main(){
    auto start = chrono::system_clock::now();

    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );

    freopen( "../Input/floyd_warshall.in", "r", stdin );

    int n, m;

    cin >>n >>m;

    init();

    while( m-- ){
        int u, v, w;
        cin >>u >>v >>w;
        graph[ u ][ v ] = w;
        graph[ v ][ u ] = w;
    }

    floyd_warshall( n + 5 );

    for( int i = 0; i < 8; i++ ){
        for( int j = 0; j < 8; j++ ){
            if( graph[ i ][ j ] == int( 1<<28 ) ){
                cout <<"I ";
            }else{
                cout <<graph[ i ][ j ] <<' ';
            }
        }
        cout <<'\n';
    }

    cout <<"\nTime: " <<( chrono::system_clock::now() - start).count()/1e9;
    return 0;
}
*/
//endregion