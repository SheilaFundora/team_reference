//
// Created by laptop on 25/9/2019.
//
#include <iostream>
#include <stdexcept>

using namespace std;

#ifndef UNTITLED4_SIMPLE_LIST_H
#define UNTITLED4_SIMPLE_LIST_H

typedef unsigned int ui;

template< class data >
class node{
public:
    node< data > * next;
    data * act;
    node( data & obj ){
        next = nullptr;
        act = new data( obj );
    }
    ~node(){
        delete  act;
    }
};

template< class data >
class simple_list {

private:
    ui size_t;
    node< data > * end;
    node< data > * first;
    node< data > * it;


    void clear( node<data> * nn ){
        while( nn->next != nullptr && size_t ){
            clear( nn->next );
        }
        delete nn;
        size_t--;
    }

public:
    simple_list(){
        end = nullptr;
        first = nullptr;
        it = nullptr;
        size_t = 0;
    }

    void push_back( data obj ){
        if( is_empty() ){
            end = first = new node< data >( obj );
            size_t++;
            return;
        }

        auto * new_node = new node< data >( obj );
        end->next = new_node;
        end = end->next;

        size_t++;
    }

    void push_front( data obj ){
        if( is_empty() ){
            end = first = new node< data >( obj );
            size_t++;
        }else{
            auto * new_node = new node< data >( obj );
            new_node->next = first;
            first = new_node;
            size_t ++;
        }
    }

    void insert( data obj, ui index ){
        if( index >= 0 && index <= size_t ){
            if( index == 0 ){
                push_front( obj );
                return;
            }

            if( index == size_t ){
                push_back( obj );
                return;
            }


            index--;
            it = first;
            while( index-- ) {
                it = it->next;
            }
            auto * aux = it->next;
            auto * new_node = new node< data >( obj );
            new_node->next = aux;
            it->next = new_node;
            size_t++;
        }
        else
            throw out_of_range( "The index to insert is out of range\n");
    }

    void erase( ui index ){
        if( index >= 0 && index < size_t ){
            if( index == 0 ){
                auto * aux = first;
                first = first->next;
                size_t--;
                delete aux;
            }else{
                index--;
                it = first;
                while( index -- ){
                    it = it->next;
                }


                auto * aux = it->next;
                it->next = aux->next;
                delete aux;
                size_t--;

                if( index == size_t - 1 ){
                    end = it;
                }
            }

        }else{
            throw out_of_range( "The index to erase is out of range" );
        }
    }

    ui size(){
        return size_t;
    }

    bool is_empty(){
        return size_t == 0;
    }

    void print_list(){
        if( !is_empty() ){
            it = first;
            while( it != nullptr ){
                cout <<*it->act <<' ';
                it = it->next;
            }
        }
        cout <<'\n';
    }

    data & get( int pos ){
        if( pos >= 1 || pos <= size_t ){
            node< data > * head = first;
            while( pos-- ){
                head = head->next;
            }
            return *head->act;
        }else{
            throw out_of_range( "The index is out of range" );
        }
    }

    void exchange( int pos1, int pos2 ){

        if( pos1 >= 0 && pos1 < size_t && pos2 >= 0 && pos2 < size_t ){

            node< data > * aux1;

            node< data > * head = first;


            while( pos1 -- ){
                head = head->next;
            }
            aux1 = head;

            pos2 = abs( pos1 - pos2 ) - 1;

            while( pos2-- ){
                head = head->next;
            }

            swap( *head->act, *aux1->act );

        }else
            throw out_of_range( "The positions are out of bounds" );

    }

    void clear_all() {
        clear( this->first );
    }

    void intercalar( simple_list< data > & simpleList ){

        node< data > * head = this->first;
        node< data > * new_head = simpleList.first;

        bool flag = true;
        node< data> * aux = nullptr;
        while( head->next != nullptr && new_head->next != nullptr ){
            if( flag ){
                aux = head->next;
                head->next = new_head;
                head = aux;
                flag = !flag;
            }else{
                aux = new_head->next;
                new_head->next = head;
                new_head = aux;
                flag = !flag;
            }
        }
    }

    void append( simple_list< data > & new_list ){
        node<data > * head = first;

        while( head->next != nullptr ){
            head = head->next;
        }

        node< data > * head_new = new_list.first;
        while( head_new ->next != nullptr ){
            head->next = head_new;

            head = head->next;
            head_new = head_new->next;
        }
    }
};




#endif //UNTITLED4_SIMPLE_LIST_H