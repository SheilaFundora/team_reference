#include <iostream>
#include <stdexcept>

using namespace std;

template < class data >
class ArrayList {

private:
    data * elementos;
    unsigned  int size_t;

public:
    ArrayList(){
        size_t = 0;
        elementos = new data[ 0 ];
    }

    void insert( data obj, unsigned int index ){
        if( index >= 0 && index < size_t ){
            data * aux = new data[ 0 ];
            int i = 0;
            for( ; i < index; i++ ){
                aux[ i ] = elementos[ i ];
            }

            aux[ i ] = obj;

            for( ; i < size_t; i++ ){
                aux[ i + 1 ] = elementos[ i ];
            }
            elementos = aux;
            size_t++;
        }else
            throw out_of_range("Index out of range");
    }

    void exchange( unsigned int pos1 , unsigned int pos2 ){
        if( pos1 >= 0 && pos2 < size_t && pos2 >= 0 && pos2 < size_t ){
            swap( elementos[ pos1 ], elementos[ pos2 ] );
        } else
            throw out_of_range( "Index out of range");
    }

    void append( data obj ){
        elementos[ size_t ++ ] = obj;
    }


    void invert(){
        //data * aux = new data[ 0 ];
        unsigned int i = 0, j = size_t - 1;
        while( i != j ){
            exchange( i++ , j-- );
        }
    }

    data * operator [ ]( int index ){
        if( index >= 0 && index < size_t ){
            return &elementos[ index ];
        }else
            return nullptr;
    }

    unsigned int eleminar_ocurrencias( data obj ){
        data * aux = new data[ 0 ];

        unsigned  int count = 0;

        unsigned  int j = 0;

        for( unsigned int i = 0; i < size_t; i++ ){
            if( elementos[ i ] == obj ){
                count++;
            }else{
                aux[ j++ ] = elementos[ i ];
            }

        }

        size_t -= count;

        elementos = aux;
        return count;
    }

    int find( data obj ){
        for( int i = 0; i < size_t; i++ ){
            if( obj == elementos[ i ] )
                return i;
        }

        return -1;

    }




    void print(){
        for( int i = 0; i < size_t; i++ ){
            cout <<elementos[ i ] <<' ';
        }
        cout <<'\n';
    }

};