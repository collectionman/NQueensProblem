#include <iostream>

class NQueens {
public:
    NQueens( void ) {
        for ( int i = 0 ; i < WIDTH ; i++ ) {
            for ( int j = 0 ; j < HEIGTH ; j++ ) {
                chessboard[ i ][ j ] = false ;
            }
        }
    }

    void print( void ) {
        static int solutions = 0 ;
        for ( int i = 0 ; i < WIDTH ; i++ ) {
            for ( int j = 0 ; j < HEIGTH ; j++ ) {
                std::cout << chessboard[ i ][ j ] << ' ' ;
            }
            std::cout << std::endl ;
        }
        solutions++ ;
        std::cout << "Solucion numero " << solutions << std::endl ;
        std::cout << std::endl ;
    }

    void backtracking( int step ) {
        for ( int i = 0 ; i < WIDTH ; i++ ) {
            if ( acceptable( i, step ) ) {
                chessboard[ i ][ step ] = true ;
                if ( step == WIDTH - 1 ) {
                    print();
                } else {
                    backtracking( step + 1 ) ;
                }
                chessboard[ i ][ step ] = 0 ;
            }
        }
    }

private:
    enum { WIDTH = 6, HEIGTH = WIDTH } ;

    bool chessboard[ WIDTH ][ HEIGTH ] ;

    bool acceptable( int i, int step ) {
        // rows
        for ( int j = 0 ; j <= i ; j++ ) {
            if ( chessboard[ j ][ step ] == true ) { // ya hay una reina en la misma fila
                return false ;
            }
        }

        // columns
        for ( int j = 0 ; j <= step ; j++ ) {
            if ( chessboard[ i ][ j ] == true ) { // ya hay una reina en la misma columna
                return false ;
            }
        }

        // left diagonal
        int h = i ;
        for ( int j = step ; j >= 0 && h >= 0 ; j-- ) { // ya hay una reina en la misma d.izquierda
            if ( chessboard[ h ][ j ] == true ) {
                return false ;
            }
            h-- ;
        }

        // right diagonal
        h = i ;
        for ( int j = step ; j >= 0 && h < WIDTH ; j-- ) { // ya hay una reina en la misma d.derecha
            if ( chessboard[ h ][ j ] == true ) {
                return false ;
            }
            h++ ;
        }

        return true ; // no hay una reina en ninguna de esas direcciones
    }
} ;

int main()
{
    NQueens* problem = new NQueens() ;

    problem -> print() ;
    problem -> backtracking( 0 ) ;

    return 0;
}
