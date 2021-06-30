#include <bits/stdc++.h>
#include "mstack.h"

using namespace std;

int main(){

    freopen( "Input/que.in", "r", stdin );

    int t = 4;

    mstack< int > ms;
    while ( t-- ){
        int s;
        cin >>s;
        ms.push( s );
    }

    while( !ms.empty() ){
        cout <<ms.top() <<'\n';
        ms.pop();
    }

}