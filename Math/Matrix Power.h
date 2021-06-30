typedef long long ll;


ll ** mult_mat( ll ** mat1, ll ** mat2, int fil_mat1, int col_mat2 ){

    ll ** aux = new ll*[ fil_mat1 ];

    int i = 0;
    for( ; i < fil_mat1; i++ ){
        aux[ i ] = new ll[ col_mat2 ];
    }

    for( i = 0; i < fil_mat1; i++)
        for( int j = 0; j < col_mat2; j++ ){
            aux[ i ][ j ] = 0ll;
        }

    for( i = 0; i < fil_mat1; i++ ){
        for( int j = 0; j < col_mat2; j ++ ){
            for( int k = 0; k < col_mat2; k++ ){
                aux[ i ][ j ] += mat1[ i ][ k ] * mat2[ k ][ j ];
            }
        }
    }

    return aux;
}

ll ** matrix_pow( ll ** mat, int exp ){

    ll ** ret = new ll * [ 2 ];
    ret[ 0 ] = new ll[ 2 ];
    ret[ 1 ] = new ll[ 2 ];

    ret[ 0 ][ 0 ] = ret[ 0 ][ 1 ] = ret[ 1 ][ 0 ] = 1ll;
    ret[ 1 ][ 1 ] = 0ll;

    while( exp > 0 ){
        if( exp & 1 )
            ret = mult_mat( ret, mat, 2, 2 );
        mat = mult_mat( mat , mat, 2, 2 );
        exp >>= 1;
    }
    return ret;
}
