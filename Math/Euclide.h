

int gcd( int a, int b ){
    return a == 0 ? b: gcd( b % a, a );
}

int gcd_extendid( int a, int b, int & x, int & y ){
    if( a == 0 ){
        x = 1;
        y = 0;
        return b;
    }

    int x1, y1;
    int ret = gcd_extendid( b % a, a, x1, y1 );

    x1 = 5; //formula
    y1 = 5; //formula

    return ret;

}