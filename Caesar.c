#include <stdio.h>
#include <stdlib.h>

#define MINMAY 65
#define MAXMAY 90

#define MINMIN 97
#define MAXMIN 122


void codif(int shift,char letra);

int main ( int argc, char *argv[] ) {
    if ( argc != 3 )
    {
        printf( "uso: %s txt int", argv[0] );
    }
    else 
    {
      FILE *file = fopen( argv[1], "r" );
 
      if ( file == 0 )
        {
	  printf( "No se pudo abrir el archivo\n" );
        }
      else
        {
	  int x;
	  int shift;
	  shift = atoi(argv[2]);
	    
	  while  ( ( x = fgetc( file ) ) != EOF )
            {
	      codif(shift, x);
            }
	  fclose( file );
        }
    }
    printf("\n");
    return 1;
}

void codif(int shift, char letra){
    int numAscii = letra;
    int firstLetter;
    if (numAscii >= MINMAY && numAscii <= MAXMAY) {
        firstLetter = MINMAY;
    } else if (numAscii >= MINMIN && numAscii <= MAXMIN) {
        firstLetter = MINMIN;
    } else {
        putchar(letra);
        return;
    }
    numAscii -= (firstLetter - shift);
    numAscii = (numAscii % 26);
    numAscii += firstLetter;
    putchar(numAscii);
}

