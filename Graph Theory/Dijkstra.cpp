#include <bits/stdc++.h>

using namespace std;

const int MAX = int( 1e3 );
#define INF int( 1e6 );

struct node{
    int v, w;
};

bitset< MAX > visited;
vector< node > graph[ MAX ];
int dist[ MAX ];

int dijkstra( int from, int to ){

    visited.reset();

    auto comp_func = []( const node & n1, const node & n2 )->bool{
        return n1.w > n2.w;
    };
    priority_queue< node, vector<node>, decltype( comp_func ) > pq( comp_func );

    for( int & it: dist ) it = INF;

    pq.push( { from, 0 } );

    while( !pq.empty() ){
        node top = pq.top();
        pq.pop();

        visited[ top.v ] = true;

        for( node & it: graph[ top.v ] )
            if( !visited[ it.v ] )
                if( top.w + it.w < dist[ it.v ] ){
                    dist[ it.v ] = top.w + it.w;
                    pq.push( { it.v, dist[ it.v ]} );
                }
    }
    return dist[ to ];
}

int main(){
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );

    auto start =  chrono::system_clock::now();

    freopen("../Input/floyd_warshall.in", "r", stdin );

    int u, v, w;
    while( cin >> u >>v >>w ){
        graph[ u ].push_back( { v, w });
    }

    cout <<dijkstra( 232, 97 ) <<'\n';
    cout <<dijkstra( 25, 4 ) <<'\n';

    cout <<"\ntime: " << (chrono::system_clock::now() - start).count()/1e9 << " s";

    return  0;
}



