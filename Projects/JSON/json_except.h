#include <exception>

using namespace std;


class not_found_except: exception{
public:
    const char * what(){
        return "attr value not found";
    }
};


class incompatible_node_type: exception{
public:
    const char * what(){
        return "not a map node you can't use [ \"key\" ]";
    }
};


class index_out_of_range: exception{
public:
    const char * what(){
        return "index out of range";
    }
};