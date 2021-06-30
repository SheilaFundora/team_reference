#include <bits/stdc++.h>

using namespace std;

const int MAX = int( 5e2 + 5 );
#define  INF int( 1e6 )

int floyd[MAX][MAX];

void init( ){
    for( int i = 0; i < MAX; i++ )
        for( int j = 0; j < MAX; j ++ )
            floyd[i][j] = (i == j ? 0 : INF);
}

void floyd_warshal( int max_node ) {
    for ( int k = 0; k < max_node; k++ )
        for ( int i = 0; i < max_node; i++ )
            for ( int j = 0; j < max_node; j++ )
                floyd[ i ][ j ] = min( floyd[ i ][ j ], floyd[ i ][ k ] + floyd[ j ][ k ] );
}

void print_mat( int mat[][505] ){
    for( int i = 0; i < 10; i++ )
        for( int j =0 ; j < 10; j++ ){
            cout <<mat[ i ][ j ];
        }
}

int main(){
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );

    auto start = chrono::system_clock::now();

    freopen( "../Input/floyd_warshall.in", "r", stdin );

    int n, m;

    //cin >>n >>m;

    init();

    int u, v, w;
    while( cin >>u >>v >>w ){
        floyd[ u ][ v ] = w;
        floyd[ v ][ u ] = w;
    }

    floyd_warshal( MAX );

    cout <<floyd[ 7 ][ 266 ];



    cout <<"\ntime: " << (chrono::system_clock::now() - start).count()/1e9 << " s";
    return 0;
}