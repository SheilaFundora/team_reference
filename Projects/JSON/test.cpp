#include <bits/stdc++.h>
#include "json.h"

using namespace std;

void file_str_load( string path, string & str ){
    ifstream ifs;
    ifs.open( path.c_str(), ios_base::in );

    string line;
    while( getline( ifs, line ))
        str+=line;

}


int main(){

    auto start = chrono::system_clock::now();
    string json_str;

    file_str_load( "../Input/json_short.json", json_str );

    json json_file( json_str );

    try {

        cout <<json_file[ "required" ] <<'\n';
        cout <<json_file[ "properties" ][ "mimeType" ][ "type" ];

    }catch ( not_found_except & e ){
        cout <<e.what();
    }catch ( incompatible_node_type & e ){
        cout <<e.what();
    }catch ( index_out_of_range & e){
        cout <<e.what();
    }

    cout <<"\nTime: " <<( chrono::system_clock::now() - start).count()/1e9;

    return 0;
}