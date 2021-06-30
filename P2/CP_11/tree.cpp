#include <iostream>

#include "node.h"


int main(){
    Profesor rector( "Rector", 0 );

    node ArbolGeneral( rector );

    ArbolGeneral.AddProfesor( Profesor( "Decano", 1 ) );
    ArbolGeneral.AddProfesor( Profesor( "Decano", 2 ) );

    //decano 1
    ArbolGeneral.get( 0 ).AddProfesor( Profesor( "JDCB", 1 ) );
    ArbolGeneral.get( 0 ).AddProfesor( Profesor( "JDCSH", 1 ) );

    ArbolGeneral.get( 0 ).get( 0 ).AddProfesor( Profesor( "Profesor", 1 ) );
    ArbolGeneral.get( 0 ).get( 0 ).AddProfesor( Profesor( "Profesor", 1 ) );
    ArbolGeneral.get( 0 ).get( 0 ).AddProfesor( Profesor( "Profesor", 1 ) );

    ArbolGeneral.get( 0 ).get( 1 ).AddProfesor( Profesor( "Profesor", 1 ) );

    //decano 2
    ArbolGeneral.get( 1 ).AddProfesor( Profesor( "JDCB", 1 ) );
    ArbolGeneral.get( 1 ).AddProfesor( Profesor( "JDTP", 1 ) );
    ArbolGeneral.get( 1 ).AddProfesor( Profesor( "JDCSH", 1 ) );

    ArbolGeneral.get( 1 ).get( 0 ).AddProfesor( Profesor( "Profesor", 1 ) );
    ArbolGeneral.get( 1 ).get( 0 ).AddProfesor( Profesor( "Profesor", 1 ) );

    ArbolGeneral.get( 1 ).get( 1 ).AddProfesor( Profesor( "Profesor", 1 ) );

    ArbolGeneral.get( 1 ).get( 2 ).AddProfesor( Profesor( "Profesor", 1 ) );
    ArbolGeneral.get( 1 ).get( 2 ).AddProfesor( Profesor( "Profesor", 1 ) );
    //end

    
    //Expexed output: 9
    cout <<"Cantidad Total Profesores:" << ArbolGeneral.getTotalProfesores() <<'\n';

    //Expected output: 2
    cout <<"Faculatad Mayor Profesores: " <<ArbolGeneral.getFacultadMayor() <<'\n';

    cout <<'\n';

    ArbolGeneral.printTree();

    return 0;
}