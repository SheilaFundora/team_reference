

typedef long long ll;

class Matrix{

private:
    ll ** mat;
    int row, col;

public:

    Matrix(){
        mat = new ll*[ 0 ];
        mat[ 0 ] = new ll[ 0 ];

        row = 0;
        col = 0;
    }

    Matrix( int row, int col ){
        this->row = row;
        this->col = col;

        mat = new ll*[ row ];

        for( int i = 0; i < row; i++ ){
            mat[ i ] = new ll[ col ];
        }
    }

    Matrix( int row, int col, ll inital_value ){
        this->row = row;
        this->col = col;

        mat = new ll*[ row ];

        for( int i = 0; i < row; i++ ){
            mat[ i ] = new ll[ col ];
        }

        for( int i = 0; i < row; i++ ){
            for( int j = 0; j < col; j++ ){
                mat[ i ][ j ] = inital_value;
            }
        }
    }

    Matrix( Matrix & mat2 ){
        this->row = mat2.get_row();
        this->col = mat2.get_col();

        mat = new ll*[ row ];
        for( int i = 0; i < row; i++ )
            mat[ i ] = new ll[ col ];

        for( int i = 0; i < row; i++ )
            for( int j = 0; j < col; j++ ){
                this->mat[ i ][ j ] = mat2.get( i , j );
            }
    }

    void sum( Matrix & mat2 ){
        for( int i = 0; i < mat2.get_row(); i++ ){
            for( int j = 0; j < mat2.get_col(); j++ ){
                mat[ i ][ j ] += mat2.get( i , j );
            }
        }
    }

    void mult( Matrix & mat2 ){

        Matrix aux( row, mat2.get_col(), 0ll );

        for( int i = 0; i < row; i++ ){
            for( int j = 0; j < mat2.get_col(); j++ ){
                for( int k = 0; k < mat2.get_col(); k++ ){
                    aux.set( i, j , aux.get( i , j ) + ( mat[ i ][ k ] * mat2.get( k, j ) ) );
                }
            }
        }

        this->col = mat2.get_col();

        for( int i = 0; i < row; i++ ){
            for( int j = 0; j < col; j++ ){
                this->mat[ i ][ j ] = aux.get( i , j );
            }
        }
    }

    void power( int exp ){
        Matrix mat_a = *this;

        while( exp > 0 ){
            if( exp & 1 )
                this->mult( mat_a );
            mat_a.mult( mat_a );
            exp >>= 1;
        }

    }

    int get_row(){
        return this->row;
    }

    int get_col(){
        return this->col;
    }

    void set( int i , int j , ll val ){
        this->mat[ i ][ j ] = val;
    }

    ll get( int i, int j ){
        return this->mat[ i ][ j ];
    }

    void reset( ll default_value ){
        for( int i = 0; i < row; i++ )
            for( int j = 0; j < col; j++ ){
                mat[ i ][ j ] = default_value;
            }
    }

    ~Matrix(){
        for( int i = 0; i < row; i++ ){
            delete [] mat[ i ];
        }
        delete [] mat;
    }
};