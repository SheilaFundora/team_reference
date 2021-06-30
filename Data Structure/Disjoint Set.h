#include <iostream>

using namespace std;

class union_find{
private:
    const int MAX = int( 1e6 );
    int * parent, * rank;

public:
    explicit union_find( int max ){
        parent = new int[ max ];
        rank = new int[ max ];
        for( int i = 0; i < max; i++ ){
            parent[ i ] = i;
            rank[ i ] = 0;
        }
    }

    union_find(){
        parent = new int[ MAX ];
        rank = new int[ MAX ];
        for( int i = 0; i < MAX; i++ ){
            parent[ i ] = i;
            rank[ i ] = 0;
        }
    }

    int find( int x ){
        return parent[ x ] == x ? x : parent[ x ] = find( parent[ x ] );
    }

    bool join( int x, int y ) {

        x = find( x );
        y = find( y );

        if ( x != y ) {
            if ( rank[ x ] > rank[ y ] ) {
                parent[ y ] = x;
            } else {
                parent[ x ] = y;

                if ( rank[ x ] == rank[ y ] ) {
                    rank[ y ]++;
                }
            }
            return true;
        }
        return false;
    }
};