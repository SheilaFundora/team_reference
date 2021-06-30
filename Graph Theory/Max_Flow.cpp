#include <bits/stdc++.h>

using namespace std;

const int MAX = int( 1e3 );
const int INF = 999999;

int graph[ MAX ][ MAX ];
bitset< MAX > visited;

vector< int > bfs_tree;

void bfs( int & source, int & sink ){

    visited.reset();
    queue< int > q;
    q.push( source );

    visited[ source ] = true;
    bfs_tree.assign( MAX, -1 );

    while( !q.empty() ){
        int top = q.front();
        q.pop();

        if( top == sink )break;

        for( int v = 0; v < MAX; v++ ){
            if( !visited[ v ] && graph[ top ][ v ] > 0 ){ //if not visited and the weight is biger than 0
                bfs_tree[ v ] = top;
                q.push( v );
                visited[ v ] = true;
            }
        }
    }
}


void procces_path_recur( int & flow, int & source, int act_node, int minFlow ){
    if( act_node == source ){
        flow = minFlow;
        return;
    }else if( bfs_tree[ act_node ] != -1 ){ // if the node has a parent in the bfs_tree;

        procces_path_recur(
                flow,
                source,
                bfs_tree[ act_node ],
                min(
                    minFlow,
                    graph[ bfs_tree[ act_node ] ][ act_node ]
                    )
                );

        graph[ bfs_tree[ act_node ] ][ act_node ] -= flow;
        graph[ act_node ][ bfs_tree[ act_node ] ] += flow;
    }
}

void procces_path_linear( int & flow, int & source ){

    int minF = INF;
    int aux = source;

    while( bfs_tree[ aux ] != -1 ){
        minF = min( minF, graph[ bfs_tree[ aux ]] [ aux ] );
        aux = bfs_tree[ aux ];
    }

    flow = minF;
    aux = source;

    while( bfs_tree[ aux ] != -1 ){
        graph[ bfs_tree[ aux ] ][ aux ] -= flow;
        graph[ aux ][ bfs_tree [ aux ] ] += flow;

        aux = bfs_tree[ aux ];
    }
}


void reset(){
    for(auto & i : graph){
        for(int & j : i){
            j = 0;
        }
    }
}


int main(){

    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );

    freopen( "../Input/max_fow.in", "r", stdin );

    int max_flow = 0;

    int source, sink, n , m;

    cin >>n >>m >>source >>sink;

    reset();

    while( m-- ){
        int u , v , w;
        cin >>u >>v >>w;
        graph[ u ][ v ] = w;
        graph[ v ][ u ] = 0;
    }

    int flow;
    while( true ){
        flow = 0;
        bfs( source, sink );
        procces_path_linear( flow, sink );

        if( flow == INF )
            break;

        max_flow += flow;
    }


    cout <<max_flow;


    return 0;
}