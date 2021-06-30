#include <iostream>

using namespace std;

class KMP{

private:
    const int MAX = 1e5;
    int * base;

public:

    KMP(){
        base = new int[ MAX ];
    }

    explicit KMP( int max_pattern_size ){
        base = new int[ max_pattern_size ];
    }



    void prep( string & pattern ){
        base[ 0 ] = -1;
        int i = 1, j = 0;
        while( i < pattern.size() ){
            while( pattern[ i ] == pattern[ j ]){
                base[ i ] = j;
                i++;
                j++;
            }
            base[ i++ ] = j;
            j = 0;
        }
    }

    int find( string & patt, string & text ){
        int i = 0, j = 0, cont = 0;

        while( i < text.size() ){
            while( text[ i ] == patt[ j ] ){
                if( j == patt.size() - 1 ){
                    cont ++;
                }
                i++; j++;
            }

            i -= base[ j ];
            j = 0;
        }
        return cont;
    }

};
