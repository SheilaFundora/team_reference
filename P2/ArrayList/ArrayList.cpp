//
// Created by laptop on 18/9/2019.
//
#include <iostream>

#include "ArrayList.h"


int main(){
    ArrayList< int > arrayList;

    arrayList.append( 0 );
    arrayList.append( 1 );
    arrayList.append( 2 );
    arrayList.append( 3 );
    arrayList.append( 1 );

    arrayList.print();

    //arrayList.insert( -1 , 0 );
    //arrayList.insert( -1, 1 );

    //arrayList.exchange( 0, 20 ); //exception
    //arrayList.exchange( 0, 4 );

    arrayList.print();

    //arrayList.invert();

    arrayList.print();

    cout <<"\nFind 3: " <<arrayList.find( 3 ) <<'\n';
    cout <<"Find -5: " <<arrayList.find( - 5 );

    cout <<'\n';

    cout <<"\nEleminar ocurrencias: ";
    cout <<arrayList.eleminar_ocurrencias( 1 ) <<'\n';
    arrayList.print();

}