#include <vector>

using namespace std;

const int MAX = int( 1e6 );

vector< int > arr;

struct node{
    int min, max, sum;
    int L, R;
    node * right, * left;

    int lazy;

    node( int L , int R ){
        this->L = L;
        this->R = R;
        this->lazy = this->min = this->max = this->sum = 0;
        this->right = this->left = nullptr;
    }

    void calc_lazy(){
        if( lazy != 0 ){
            this->sum += ( R - L == 0 ? 1 : R - L )*lazy;
            this->max += lazy;
            this->min += lazy;

            if( right != nullptr ){
                right->lazy += lazy;
                left->lazy += lazy;
            }
            lazy = 0;
        }
    }
} * root;

void built( node *& n ){
    if( n->L == n->R ){
        n->min = n->max = n->sum = arr[ n->L ];
    }else{
        int mid = ( n->R + n->L ) >>1;

        n->left = new node( n->L, mid );
        n->right = new node( mid + 1, n->R );

        built( n->left );
        built( n->right );

        n->sum = n->right->sum + n->left->sum;
        n->max = max( n->right->max , n->left->max );
        n->min = min( n->left->min, n->right->min );
    }
}

int query( node *& n, int i, int j ){
    if( n->L > j || n->R < i ){
        return 0;
        //it depends ( min = 9999, max = 0 , sum = 0 );
    }

    if( n->L >= i && n->R <= j ){
        return n->sum; //it depends( min, max, sum )
    }

    int query_right = query( n->right, i, j );
    int query_left = query( n->left, i , j );

    return query_right + query_left; //sum case;
    //return min( query_left, query_right );
    //return max( query_left, query_right );
}

void update( node *& n, int index, int val ){

    if( index > n->R || index < n->L ) {
        return;
    }

    if( n->L == n->R ){
        if( n->R == index ){
            n->sum = val;
            n->max = val;
            n->min = val;
        }
        return;
    }

    update( n->left, index, val );
    update( n->right, index, val );

//    n->max = max( n->right->max , n->left->max );
    n->sum = n->right->sum + n->left->sum;
//    n->min = min( n->left->min, n->right->min );
}

void update_lazy( node *& n, int i, int j, int val ){
    n->calc_lazy();

    if( n->L > j || n->R < i )
        return;

    if( n->L >= i && n->R <= j ){

        n->sum += ( n->R - n->L == 0 ? 1 : n->R - n->L )*val;
        n->max += val;
        n->min += val;

        if( n->right != nullptr ){
            n->right->lazy += val;
            n->left->lazy += val;
        }
        return;
    }

    if( n->left != nullptr ){
        update_lazy( n->left, i, j, val );
        update_lazy( n->right, i, j, val );

        n->sum = n->right->sum + n->left->sum;
        n->max = max( n->right->max , n->left->max );
        n->min = min( n->left->min, n->right->min );
    }
}

//same as before but with n->calc_lazy();
int query_lazy( node *& n, int i , int j ){
    n->calc_lazy();
    if( n->L > j || n->R < i ){
        return 0;
        //it depends ( min = 9999, max = 0 , sum = 0 );
    }

    if( n->L >= i && n->R <= j ){
        return n->sum; //it depends( min, max, sum )
    }

    int query_right = query( n->right, i, j );
    int query_left = query( n->left, i , j );

    return query_right + query_left; //sum case;
    //return min( query_left, query_right );
    //return max( query_left, query_right );
}

//Persistent Segment Tree
vector< node* > versions;

void update_persistent( node *& previous, node *& new_version, int pos, int val ){
    if( pos > previous->R || pos < previous->L ) return;

    int mid = ( previous->L + previous->R )>>1;

    if( previous->L == previous->R ){
        if( pos == previous->L ){
            new_version->min = val;
            new_version->max = val;
            new_version->sum = val;
        }
        return;
    }

    if( pos <= mid ){
        new_version->right = previous->right;

        new_version->left =  new node( previous->L, mid );

        update_persistent( previous->left, new_version->left, pos, val );

    }else{
        new_version ->left = previous->left;

        new_version->right = new node( mid + 1, previous->R );

        update_persistent( previous->right, new_version->right, pos, val );
    }

    new_version->sum = new_version ->left ->sum + new_version ->right ->sum;
    new_version->max = max( new_version ->left ->max, new_version ->right ->max );
    new_version->min = min( new_version ->left ->min, new_version ->right ->min );

}


void printArr( node*& n ){
    //n->calc_lazy(); //with lazy

    if( n->left == nullptr || n->right == nullptr ){
        cout <<n->sum <<' ';
        if( n->L == arr.size() - 1 )
            cout <<'\n';
        return;
    }else{
        printArr( n->left );
        printArr( n->right );
    }
}

//region main

//test_persistent
/*
#include <bits/stdc++.h>
#include "Data Structure/Segment Tree.h"

using namespace std;

int main(){
    auto start = chrono::system_clock::now();

    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );

    freopen( "../Input/segment_tree.in", "r", stdin );

    int n;
    cin >>n;

    while( n-- ){
        int x;
        cin >>x;
        arr.push_back( x );
    }

    root = new node( 0, arr.size() - 1 );

    versions.push_back( root );
    built( versions[ 0 ] );
    cout <<"Ver: 1\n";
    printArr( versions[ 0 ] );


    int pos, val, k;
    while( cin >>pos >>val >>k ){
        versions.push_back( new node( 0, arr.size()- 1 ) );
        update_persistent( ( versions.size() < 3) ? versions[ 0 ] : versions[ versions.size() - 2 ] , versions.back(), pos, val );

        cout <<"Ver: " << versions.size() <<"  Update: "  <<pos <<" -> " <<val <<'\n';
        cout <<"Sum : " <<query( versions.back(), 0, arr.size() ) <<'\n';
        printArr( versions.back() );
    }



    cout <<"\nTime: " <<( chrono::system_clock::now() - start).count()/1e9;
    return 0;
}
*/

//endregion