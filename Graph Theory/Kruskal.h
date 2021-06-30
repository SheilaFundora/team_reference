#include <vector>
#include <algorithm>
#include "../Data Structure/Disjoint Set.h"

using namespace std;

struct edge{
    int u, v, w;
    bool operator <( edge & other ){
        return w == other.w;
    }
};

vector< edge > edges;

int kruskal( int n ){

    sort( edges.begin(), edges.end() );

    int sum = 0;

    union_find disjoin_set( n + 5 );

    int cont = 0, i = 0;
    while( cont < n - 1 ){
        if( disjoin_set.join( edges[ i ].u, edges[ i ].v ) ){
            sum += edges[ i ].w;
            cont++;
        }
        i++;
    }

    return sum;
}

//region main
/*
#include <bits/stdc++.h>

#include "Graph Theory/Kruskal.h"

using namespace std;

int main(){
    auto start = chrono::system_clock::now();

    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );

    freopen( "../Input/kruskal.in", "r", stdin );

    int n, m;

    cin >>n >>m;

    while( m-- ){
        int u, v, w;
        cin >>u >>v >>w;
        edges.push_back( { u, v, w } );
    }

    cout <<kruskal( n );


    cout <<"\nTime: " <<( chrono::system_clock::now() - start).count()/1e9;
    return 0;
}
*/
//endregion

