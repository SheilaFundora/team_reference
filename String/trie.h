#include <iostream>
using namespace std;

struct node{
    char act;
    node* child[256];

    node(){
        act = 0;
        for( node*& it: child ) it = nullptr;
    }

    explicit node( char c ){
        this->act = c;
        for( node*& it: child ) it = nullptr;
    }

} * root = new node( '&' );

void add_string( string & cad, node *& act_node, int pos ){
    if( pos == cad.size() )return;

    if( act_node->child[ cad[ pos ] ] != nullptr ){
        add_string(
                cad,
                act_node->child[cad[ pos ]],
                pos + 1
                );
    }else{
        auto * new_node = new node( cad[ pos ] );
        act_node->child[ cad[ pos ] ] = new_node;

        add_string( cad, new_node, pos + 1 );
    }
}

bool search_string( string& pat, node*& act_node, int pos ){
    if( pos == pat.size() )return true;

    if( act_node->child[ pat[ pos ] ] != nullptr ){
        return search_string(
                pat,
                act_node->child[ pat[ pos ] ],
                pos + 1
                );
    }else{
        return false;
    }
}

//region main_test
/*

#include <bits/stdc++.h>
#include "String/trie.h"

using namespace std;

int main(){
    //auto start = chrono::system_clock::now();

    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );

    freopen( "../Input/trie.in", "r", stdin );

    string cad;

    while( cin >> cad ){
        add_string( cad, root, 0 );
    }

    string pat = "erel";
    cout <<search_string( pat, root, 0 );



    //cout <<"\nTime: " <<( chrono::system_clock::now() - start).count()/1e9;
    return 0;
}*/
//endregion


