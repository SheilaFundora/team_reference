#include <bits/stdc++.h>
#include "nodelist.h"

using namespace std;

int main( ){

    node_list< int > nodeList;

    //adding elements;
    for( int i = 0; i < 8; i++ ){
        nodeList.push_back( i );
    }

    //testing method print list
    cout <<"Testing method print list: ";
    nodeList.printList();

    // testing the get operation
    cout <<"\nTesting the get operation: ";
    cout <<nodeList[ 0 ] <<' ' <<nodeList[ 1 ] <<' ' <<nodeList[ 2 ] <<' ' <<nodeList[ 7 ] <<' ' <<nodeList[ 0 ] <<'\n';


    cout <<"\nTesting add method: \n\t";
    nodeList.add( -2, 0 ); // add in the begining
    nodeList.printList();

    cout <<'\t';
    nodeList.add( -1, 0 ); //add in the begining
    nodeList.printList();

    cout <<'\t';
    nodeList.add( 5, 2 ); //add in the middle
    nodeList.printList();

    //add to the end
    cout <<'\t';
    nodeList.add( -15, nodeList.size() - 1 );
    nodeList.printList();

    cout <<"\nTesting erase method: ";
    //nodeList.erase( 0 );
    //nodeList.erase( 1 );
    nodeList.erase( 11 ); //erase at the end;
    //nodeList.erase( 0 );
    nodeList.printList();


    return 0;
}
