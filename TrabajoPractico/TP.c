#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*MI ER: ER [0-9]+F|[0-9]\.[01]{2} Centinela: #*/

void clean(char *);
int esCentinela(char);
int esA(char);
int esB(char);
int esPunto(char);
int esF(char);
int esfdt(char);
int esEstadoFinal(int);
int analizarCaracter(char, int tabla[7][5], int);
void imprimirPalabra(char *,int );

int esfdt(char c) {
	if (c == '\0'){
       return 1;
	}
    return 0;
}


void clean( char *cadena ){
	int i;
	for( i=0; i<strlen(cadena);i++){
			cadena[i]='\0';
	}
}

int esCentinela(char c) {
    if (c == '#')
		return 1;
	else
		return 0;
}

int esA(char c) { /*2,3,4,5,6,7,8,9*/
    switch(c)
    {
        case '2':
            return 1;
            break;
        case '3':
            return 1;
            break;
        case '4':
            return 1;
            break;
        case '5':
            return 1;
            break;
        case '6':
            return 1;
            break;
        case '7':
            return 1;
            break;
        case '8':
            return 1;
            break;
        case '9':
            return 1;
            break;
        default:
            return 0;
        }
}

int esB(char c){
    switch(c)
    {
       case '0':
            return 1;
            break;
        case '1':
            return 1;
            break;
        default:
            return 0;
    }
}

int esPunto(char c) {
   if (c == '.')
		return 1;
	else
		return 0;
}

int esF(char c) {
   if (c == 'F')
		return 1;
	else
		return 0;
}

int esEstadoFinal(int estadoActual){
	if (estadoActual == 5){
	return 1;
	}
     return 0;
}

int analizarCaracter(char c, int tabla [7][5], int estadoActual) {
	int res;
	if (esA(c)) {
		res = tabla[estadoActual][1];
	} else if (esF(c)) {
		res = tabla[estadoActual][2];
	} else if (esPunto(c)) {
		res = tabla[estadoActual][3];
	} else if (esB(c)) {
		res = tabla[estadoActual][4];
	} else if (esCentinela(c)) /*volver al estado 0*/ {
		res = 0;
	} else if (esfdt(c)) {
		res = tabla[estadoActual][6];
	} else  { /*no es nada*/
		res = tabla[estadoActual][6];
	}
	return res;
}


void imprimirPalabra(char cadena[100],int posNuevaPalabra){
    char letra;
    int i=0;
    for(i=posNuevaPalabra;(cadena[i]!='\0')&&(cadena[i]!='#');i++){
        letra = cadena[i];
        printf("%c",letra);
    }
        printf("\n");
}

int main(void) {
    char cadena[100];
    int continuar = 0;
    int tablaTransicion[7][5] = {
	{ 0, 1, 8, 8, 1 },
	{ 1, 2, 5, 3, 2 },
	{ 2, 2, 5, 8, 2 },
	{ 3, 8, 8, 8, 4 },
	{ 4, 8, 8, 8, 5 },
	{ 5, 8, 8, 8, 8 },
	{ 8, 8, 8, 8, 8 }
	};
	int posNuevaPalabra;
	int estadoInicial = tablaTransicion[0][0];
	int estadoActual=0;
    int i=0;
  do{
    clean(cadena);
    i=0;
    estadoInicial = tablaTransicion[0][0];
    estadoActual=0;
    printf("\n ** Ingrese cadena: ");
    scanf("%s", cadena);
   // estadoActual = estadoInicial;
    while(!esfdt(cadena[i])) {
        if (estadoActual==estadoInicial){
            posNuevaPalabra = i;
        }
        estadoActual = analizarCaracter(cadena[i],tablaTransicion,estadoActual);
        if (esEstadoFinal(estadoActual)){
            imprimirPalabra(cadena,posNuevaPalabra);
        }
        i++;
    }

    printf("\n\n  * Presione:\n -1 Para ingresar otra cadena \n -0 para terminar el proceso\n Opcion:");
    scanf("%d", &continuar);
	}while ( continuar == 1);
}

