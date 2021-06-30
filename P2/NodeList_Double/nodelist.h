#include <iostream>
#include <stdexcept>

using namespace std;

typedef unsigned int u_int;

template < class data >
class node{

public:
    node< data > * next;
    node< data > * back;
    data * contenido;

    node( data obj ){
        contenido = new data( obj );
        next = nullptr;
        back = nullptr;
    }
};


template < class data >
class node_list{

private:
    u_int size_t;
    u_int act_position;

    node< data > * first;
    node< data > * end;

    node< data > * it;

    void add_acutal( data & obj ){
        if( it != nullptr ){
            node< data > * new_node = new node< data >( obj );
            new_node->back = it;
            new_node->next = it->next;
            it->next->back = new_node;
            it->next = new_node;
            size_t++;
        }
    }

    void erase_actual(){
        if( it != nullptr ){

            if( it == end ){
                node< data > * n = end;
                end = end->back;
                end->next = nullptr;
                delete n;
                size_t --;

                return;
            } // am at the end of the list

            it->back->next = it->next;
            it->next->back = it->back;

            node< data > * aux = it;

            it = it->back;
            act_position--;
            size_t--;
            delete aux;
        }
    }


    void move_next(){
        if( it->next != nullptr ){
            it = it->next;
            act_position++;
        }
    }
    void move_back(){
        if( it->back != nullptr ){
            it = it->back;
            act_position--;
        }
    }


public:

    node_list(){
        size_t = 0;
        act_position = -1;
        first = nullptr;
        end = nullptr;
        it = nullptr;
    }


    void push_back( data obj ){
        auto * new_node = new node<data> ( obj );

        if( isEmpty() ){
            first = new_node;
            end = new_node;
            it = new_node;
            act_position = 0;
            size_t++;
        }else{
            end->next = new_node;
            new_node->back = end;
            end = new_node;
            size_t++;
        }
    }


    void add( data obj, u_int index ){
        if( index == 0 ){
            auto * new_node = new node< data > ( obj );
            first->back = new_node;
            new_node->next = first;
            first = new_node;
            size_t++;
            act_position++;
            return;
        }

        if( !isEmpty() ) { //la lista no este vacia
            if ( index == size_t - 1 ) { //si el iterador esta al final hacer push_back
                push_back( obj );
            } else if ( index < size_t ) { // si la posicion entra en el rango
                if ( index > act_position ) { // si la pos a adicionar esta por encima del act_pos entonces move_next
                    u_int aux = index - act_position; // calcular la diff para moverme aux veces
                    while ( aux-- ) {
                        move_next();
                    }
                    add_acutal( obj );
                } else {
                    u_int aux = act_position - index; // calcular la diff para moverme aux veces
                    while ( aux-- ) {
                        move_back();
                    }
                    add_acutal( obj );
                }
            }else{ //pos esta fuera del rango de la lista.
                throw out_of_range("out of bound");
            }
        }
    }


    void erase( u_int index ){
        if( index == 0 && !isEmpty() ){
            node< data > * n = first;
            first = first->next;
            delete n;
            size_t--;
            //reiniciar el iterador evitar problemas
            act_position = 1;
            it = first;

            return;
        }

        if( index < size_t && index >= 0 ) {// si esta la index dentro del rango
            int aux = abs( index - act_position ) + 1; //cant de movimientos dentro de la lista

            if( index < act_position ){
                while ( aux -- ){
                    move_back(); //metodo privado
                }
                erase_actual();
            }else{
                while( aux -- ){
                    move_next(); //metodo privado
                }
                erase_actual();
            }
        }else{
            throw out_of_range("out of bound");
        }
    }


    bool isEmpty(){
        return this->size_t <= 0;
    }


    data operator []( u_int index ){
        u_int  pos = index + 1;
        if( pos >= 1 && pos <= size_t ){
            int aux = max( pos, act_position ) - min( pos, act_position); //cant de movimientos dentro de la lista

            if( pos < act_position ){
                while ( aux -- ){
                    move_back(); //metodo privado
                }
            }else{
                while( aux -- ) {
                    move_next(); //metodo privado
                }
            }
            return *it->contenido;

        } else
            throw out_of_range("out of bound");
    }


    u_int size(){
        return this->size_t;
    }

    void printList( ){
        it = first; act_position = 1;

        if( it != nullptr ){
            cout <<*it->contenido <<' ';
            while( it->next != nullptr ){
                cout <<*it->next->contenido <<' ';
                it = it->next;
            }
        }
        it = first;
        cout <<'\n';
    }

};

