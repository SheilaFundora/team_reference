#include <iostream>
#include <vector>
#include <queue>
#include <stdexcept>

using namespace std;


class Profesor{
private:
    string cargo;
    int facultad;

public:

    explicit Profesor(){
        facultad = 0;
        cargo = "None";
    }

    explicit Profesor( string && cargo, int facultad ){
        this->cargo = cargo;
        this->facultad = facultad;
    }

    string & getCargo(){
        return cargo;
    }

    int getFacultad(){
        return facultad;
    }
};


class node {

private:
    Profesor profesor;
    vector< node > childs;

    int getTotalProferosres( node & n ){
        int total_prof = 0;
        for( node & it: n.childs ){
            if( it.profesor.getCargo() == "Profesor" ){
                total_prof++;
            }
            total_prof += getTotalProferosres( it );
        }
        return total_prof;
    }

    void getDecanos( node n, queue< node > & decano ){

        for( node it: n.childs ){
            if( it.profesor.getCargo() == "Decano" ){
                decano.push( it );
            }
            getDecanos( it, decano );
        }

    }

    vector< Profesor > BFS_GetJeralquia( node n ){
        vector< Profesor > aux;
        queue< node > Q;

        aux.push_back( n.profesor );
        Q.push( n );

        while( !Q.empty() ){
            node front = Q.front();
            Q.pop();

            for( node & it: front.childs ) {
                aux.push_back( it.profesor );
                Q.push( it );
            }
        }
        return  aux;
    }

    string startPrint( node n, int deep ){
        string tab_spaces = "\n";
        if( deep ){
            for( int i = 0; i < deep - 1; i++ ){
                tab_spaces += "\t|";
            }

            tab_spaces += "---";
        }

        tab_spaces += n.getCargo();

        if( n.childs.size() != 0 ){
            for( int i = 0; i < n.childs.size(); i++ ){
                tab_spaces += startPrint( n.childs[ i ], deep + 1 );
            }
        }

        return tab_spaces;
    }

public:
    explicit node( Profesor & profesor1 ){
        this->profesor = profesor1;
    }

    int getTotalProfesores(){
        return getTotalProferosres( *this );
    }

    int getFacultadMayor(){
        queue< node > queue_decanos;                //get all decano on the tree

        if( profesor.getCargo() == "Decano" )       //if the root of the tree is Decano push it
            queue_decanos.push( *this );

        getDecanos( *this, queue_decanos );         //private method which fill queue_decanos with every decano

        int facultad_mayor = 0;
        int mayor_cant_profesores = 0;
        int cant_prof;

        while( !queue_decanos.empty() ){

            node & n = queue_decanos.front();
            queue_decanos.pop();

            cant_prof = getTotalProferosres( n );
            if( cant_prof > mayor_cant_profesores ){
                mayor_cant_profesores = cant_prof;
                facultad_mayor = n.profesor.getFacultad();
            }
        }
        return facultad_mayor;
    }


    vector<Profesor> getJeralquia(){
        return BFS_GetJeralquia( *this );
    }


    void AddProfesor( Profesor p ){
        this->childs.push_back( node( p ) );
    }

    string & getCargo(){
        return profesor.getCargo();
    }

    node & get( int index ){
        if( index < 0 || index >= childs.size() ){
            throw exception();  //I should create one.
        }
        return childs[ index ];
    }

    void printTree(){
        cout <<"Arbol: \n";
        cout << startPrint( *this, 0 );
    }

};

