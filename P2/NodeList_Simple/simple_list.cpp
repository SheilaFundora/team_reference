//
// Created by laptop on 25/9/2019.
//

#include <bits/stdc++.h>
#include "simple_list.h"

using namespace std;

int main(){

//    ios_base::sync_with_stdio( 0 );
//    cin.tie( 0 );
//    cout.tie( 0 );

    freopen( "../Input/simple_list.in", "r", stdin );

    int n;
    cin >>n;

    simple_list< int > simpleList;
    while( n-- ){
        int x;
        cin >>x;
        simpleList.push_back( x );
    }

    simpleList.print_list();

//    cout <<"push_back insert( data, 0 ): \n";
//    simpleList.insert( 9, 0 );
//
//    simpleList.print_list();

//    cout <<"insert( data, x ):\n";
//    simpleList.insert( 9, 5 );
//
//    simpleList.print_list();


    cout <<"erase( index ): \n";
    simpleList.erase( 4 );

    simpleList.print_list();
    simpleList.push_back( 9 );

    cout <<simpleList.get( 0 ) <<"\n";

    simpleList.exchange( 0, 2 );
    simpleList.print_list();

    simple_list<int> list2;

    cout <<"\nAppend\n";
    for( int i = -3; i < 0; i++ )list2.push_back( i );

    //simpleList.clear();

    cout <<"\nIntercalar\n";
    simpleList.intercalar( list2 );
    simpleList.print_list();


    return 0;
}