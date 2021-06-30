#include <bits/stdc++.h>
#include "mqueue.h"

using namespace std;

int main(){

    freopen( "../Input/que.in", "r", stdin );

    int t = 4;

    mqueue< int > mq;
    while ( t-- ){
        int s;
        cin >>s;
        mq.push( s );
    }

    while( !mq.empty() ){
        cout <<mq.get_front() <<'\n';
        mq.pop();
    }

}