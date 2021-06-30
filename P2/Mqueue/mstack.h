
#include <iostream>

template < class data_type >
class stack_node{
public:
    stack_node< data_type > * next;
    stack_node< data_type > * back;
    data_type * actual;

    stack_node( data_type obj ){
        this->next = nullptr;
        this->back = nullptr;
        auto * dt = new data_type( obj );
        this->actual = dt;
    }

    stack_node(){
        next = nullptr;
        back = nullptr;
        actual = nullptr;
    }
};

template < class data_type >
class mstack{
private:
    stack_node< data_type > * start;
    stack_node< data_type > * end;
    int size;

public:

    mstack(){
        end = nullptr;
        start = nullptr;
        size = 0;
    }

    void push( data_type obj ){
        if( this->size == 0 ){
            end = new stack_node< data_type >( obj );
            size++;

        }else{

            auto * nn = new stack_node< data_type >( obj );
            end->next = nn;
            nn->back = end;
            end = nn;
            size++;

        }
    }

    data_type top(){
        return *this->end->actual;
    }

    bool empty(){
        return this->size == 0;
    }

    void pop(){
        if( empty() ){
            return;
        }else{
            auto *& nn = end;
            end = nn->back;
            if( end != nullptr && end->next != nullptr ){
                delete end->next;
            }

            size--;
        }
    }

};