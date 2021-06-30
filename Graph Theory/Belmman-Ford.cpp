#include <bits/stdc++.h>

using namespace std;

const int MAX = int( 1e3 );
#define INF int( 1e6 );

struct  edge{
    int u, v, w;
};

vector< edge > edges;
int dist[ MAX ];

void bellman_ford( int source, int max_node ){

    for( int & it: dist ) it = INF;

    dist[ source ] = 0;

    for( int fase = 0; fase < max_node; fase ++ ){
        for( edge & it: edges ){
            dist[ it.v ] = min( dist[ it.v ], dist[ it.u ] + it.w  );
        }
    }
}

int main(){
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );

    auto start = chrono::system_clock::now();

    freopen("../Input/bellman.in", "r", stdin );

    int u, v, w;
    while( cin >> u >>v >>w ){
        edges.push_back( { u, v, w } );
    }

    bellman_ford( 1, 5 );


    for( int i = 1; i < 6; i++ )cout <<dist[ i ] <<' ';

    cout <<'\n';

    cout <<"time: " <<( chrono::system_clock::now() - start ).count()/1e9;

    return  0;
}

