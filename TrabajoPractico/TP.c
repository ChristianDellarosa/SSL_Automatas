#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clean( char *);

int main(void) {
    char cadena[100];
    int continuar = 0;
  do{
    clean(cadena);
    printf("\n ** Ingrese cadena: ");
    scanf("%s", cadena);
    printf("\nLa cadena ingresada es: %s\n",cadena);

    printf("\n\n  * Presione:\n -1 Para ingresar otra cadena \n -0 para terminar el proceso\n Opcion:");
    scanf("%d", &continuar);
	}while ( continuar == 1);
}

void clean( char *cadena ){
    int i;
	for( i=0; i<sizeof(cadena);i++){
		cadena[i]='\0';
	}
}
