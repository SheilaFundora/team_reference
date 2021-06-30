#include <utility>
#include <iostream>
#include <ostream>
#include <map>
#include <vector>


#include "json_except.h"

using namespace std;

class json_obj{

public:

    short type:3;

    ~json_obj(){}

    vector< json_obj* > childs;
    map< string, json_obj*> childs_mp;
    string str_node;

    void add_vect( json_obj* son ){
        childs.push_back( son );
    }

    void add_map( string key,  json_obj* son ){
        childs_mp[ key ] = son;
    }

    void add_map( pair< string, json_obj*> pii ){
        childs_mp.insert( pii );
    }

    json_obj( short type ){
        this->type = type;
    }

    json_obj operator []( string key ){
        if( this->type != 0 ){
            throw incompatible_node_type();
        }else{
            if( childs_mp.count( key ) ){
                return *childs_mp[ key ];
            }else{
                throw not_found_except();
            }
        }
    }

    json_obj operator []( int pos ){
        if( this->type != 1 ) {
            throw incompatible_node_type();
        } else{
            if( pos >= childs.size() ){
                throw index_out_of_range();
            }

            return *childs[ pos ];

        }
    }


    friend ostream& operator <<( ostream& c, json_obj jsonObj ){
        switch( jsonObj.type ){
            case 0:
                c <<"Map Node";
                break;
            case 1:
                c <<"Array Node";
                break;
            case 2:
                c <<jsonObj.str_node;
        }
        return c;
    }

    void print(){
        switch( type ){
            case 0:
                cout <<"Map Node";
                break;
            case 1:
                cout <<"Array Node";
                break;
            case 2:
                cout <<str_node;
        }
    }

};


class json{

private:
    bool _is_loaded;

    json_obj * load( string & json, int pos ){

        while( pos < json.size() ){
            switch ( json[ pos++ ] ){
                case '{':
                    return read_dict( json, pos );
                case '[':
                    return read_array( json, pos );
                case '"':
                    return read_string( json, pos ); //pos -1 porque si no no lee el caracter "
                                                            //lo cual es necesario para read_string
            }
        }
    }

    json_obj * read_dict( string & json_str, int pos ){
        auto * dict = new json_obj( 0 );

        int remain = 1;

        string attr;

        while( remain ){
            attr.push_back( json_str[ pos ] );
            switch ( json_str[ pos ] ){
                case '[':
                case '{':
                    remain++;
                    break;
                case ']':
                case '}':
                    remain--;
                    break;
                case ',':
                    if( remain == 1 ){
                        attr.pop_back();
                        dict->add_map( read_dict_fild( attr ) );
                        attr.clear();
                    }
                    break;
            }
            pos++;
        }
        if( !attr.empty() ){
            attr.pop_back();
            dict->add_map( read_dict_fild( attr ) );
            attr.clear();
        }

        return dict;
    }

    json_obj * read_array( string & json_str, int pos ){
        auto * arr = new json_obj( 1 );

        int remain = 1;

        string attr;

        while( remain ){
            attr.push_back( json_str[ pos ] );
            switch ( json_str[ pos ] ){
                case '{':
                case '[':
                    remain++;
                    break;
                case '}':
                case ']':
                    remain--;
                    break;
                case ',':
                    if( remain == 1 ){
                        attr.pop_back();
                        arr->add_vect( load( attr, 0 ) );
                        attr.clear();
                    }
                    break;
            }
            pos++;
        }

        if( !attr.empty() ){
            attr.pop_back();
            arr->add_vect( load( attr, 0 ) );
        }
        return arr;
    }

    pair< string, json_obj* > read_dict_fild( string & attr ){
        string key;
        int mark = 2;
        int i = 0;
        for( ; i < attr.size() && mark; i++ ){
            if( attr[ i ] == '"')
                mark--;
            else if( mark == 1 ){
                key.push_back( attr[ i ] );
            }
        }

        pair< string, json_obj* > pii;
        pii.first = key;
        pii.second = load( attr, i + 1 );

        return pii;
    }

    json_obj * read_string( string & json_str, int pos ){
        string key;
        int mark = 2;
        int i = pos - 1;
        for( ; i < json_str.size() && mark; i++ ){
            if( json_str[ i ] == '"')
                mark--;
            else if( mark == 1 ){
                key.push_back( json_str[ i ] );
            }
        }
        auto * ret =  new json_obj( 2 ); //string

        ret->str_node = key;

        return ret;
    }

public:
    explicit json( string & json_str ){
        root = load( json_str , 0 );
        _is_loaded = true;
    }

    json_obj * root;

    json_obj operator []( int idx ){
        try {
            return this->root->operator[]( idx );
        }catch ( index_out_of_range & e ){
            throw e;
        }
    }

    json_obj operator []( string key){
        try {
            return this->root->operator[]( key );

        }catch ( not_found_except & e ){
            throw e;
        }catch ( incompatible_node_type & e ) {
            throw e;
        }
    }

    friend ostream& operator <<( ostream & cout, json JSON){
        cout <<JSON.root;
        return cout;
    }

    friend ostream& operator <<( ostream & cout, json * JSON){
        cout <<*JSON->root;
        return cout;
    }

};

