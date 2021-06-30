#include <bits/stdc++.h>

using namespace std;

const int MAX = int( 1e7 );

struct point{
    int x, y;
};

double dist( const point & p1, const point & p2 ){
    return sqrt( pow( p1.x - p2.x , 2 ) + pow( p1.y - p2.y , 2) );
}

vector< point > v_point;

void sweep_line( int index_point, double & min_dist ){
    int min_x = abs( v_point[ index_point - 1 ].x - int( ceil( min_dist ) ) );

    point & p = v_point[ index_point - 1 ];

    for( int i = index_point; i < v_point.size(); i++ ){
        point act_point = v_point[ i ];
        //out of area
        if( act_point.x < min_x ) break;
        if( act_point.y > p.y + min_dist || act_point.y < p.y - min_dist )continue;

        min_dist = min( min_dist, dist( p, act_point ) );
    }


}

int main(){
    auto start = chrono::system_clock::now();

    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );

    freopen( "../Input/sweep_line_closest_pair.in", "r", stdin );

    int n;
    cin >>n;

    while( n-- ){
        int x, y;
        cin >>x >>y;
        v_point.push_back( { x, y } );
    }

    sort( v_point.begin(), v_point.end(), []( const point & p1, const point & p2 )->bool{
        if( p1.x == p2.x ){
            return p1.y > p2.y;
        }
        return p1.x > p2.x;
    });

    for( point & it: v_point ) cout <<it.x <<' ' <<it.y <<'\n';

    double min_dist = dist( v_point[ 0 ], v_point[ 1 ] );

    for( int i = 0; i < v_point.size() - 1; i++ ){
        sweep_line( i + 1 , min_dist );
    }

    cout <<min_dist;

    cout <<"\nTime: " <<( chrono::system_clock::now() - start).count()/1e9;
    return 0;
}