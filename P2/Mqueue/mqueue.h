
#include "mstack.h"

template< class data >
class node{
public:
    node<data> * next;
    data * actual;

    node( data obj){
        this->actual = new data( obj );
        this->next = nullptr;
    }
};


template < class data >
class mqueue{

private:
    node< data > * front;
    node< data > * back;
    int size;

public:

    mqueue(){
        size = 0;
        front = nullptr;
        back = nullptr;
    }

    ~mqueue(){

    }

    void push( data obj ){
        if( empty() ){
            auto * n = new node< data >( obj );
            front = n;
            back = n;
        }else{
            auto * n = new node< data >( obj );
            back->next = n;
            back = n;
        }
        size ++;
    }

    data get_front(){
        return *this->front->actual;
    }

    data get_back(){
        return *this->back->actual;
    }

    void pop( ){
        if( !empty() ){
            auto *& n = front;
            front = front->next;
            delete front;
            size --;
        }
    }

    bool empty(){
        return size == 0;
    }

};