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
int analizarCaracter(char, int tabla[7][4], int);
void imprimirPalabra(char *,int , int *);
void imprimirMatriz(int matriz[7][4]);

int main(void) {
    char cadena[100];
    int continuar = 0;
    int nroPalabra = 1;
    int i=0;
	int posNuevaPalabra;
    int tablaTransicion[7][4] = {
	{ 1, 6, 6, 1 },
	{ 2, 5, 3, 2 },
	{ 2, 5, 6, 2 },
	{ 6, 6, 6, 4 },
	{ 6, 6, 6, 5 },
	{ 6, 6, 6, 6 },
	{ 6, 6, 6, 6 }
	};
	int estadoInicial = 0;
	int estadoActual=estadoInicial;

  do{
    clean(cadena);
    i=0;
    estadoInicial = 0;
    estadoActual=estadoInicial;
    nroPalabra=1;
    printf("\n ** Ingrese cadena: ");
    scanf("%s", cadena);
    while(!esfdt(cadena[i])) {
        if (estadoActual==estadoInicial){
            posNuevaPalabra = i;
        }
        estadoActual = analizarCaracter(cadena[i],tablaTransicion,estadoActual);
        if(esEstadoFinal(estadoActual)&&((cadena[i+1]=='#')||(cadena[i+1]=='\0'))) {
            imprimirPalabra(cadena,posNuevaPalabra, &nroPalabra);
        }
        i++;
    }
    printf("\n  * Presione:\n -1 Para ingresar otra cadena \n -0 para terminar el proceso\n Opcion:");
    scanf("%d", &continuar);
	}while ( continuar == 1);
}

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

int analizarCaracter(char c, int tabla [7][4], int estadoActual) {
	int res;
	if (esA(c)) {
		res = tabla[estadoActual][0];
	} else if (esF(c)) {
		res = tabla[estadoActual][1];
	} else if (esPunto(c)) {
		res = tabla[estadoActual][2];
	} else if (esB(c)) {
		res = tabla[estadoActual][3];
	} else if (esCentinela(c)) /*volver al estado 0*/ {
		res = 0;
	} else if (esfdt(c)) {
		res = 0;//res = tabla[6][estadoActual];
	} else  {
		res = tabla[6][0];
	}
	return res;
}

void imprimirPalabra(char cadena[100],int posNuevaPalabra, int * nroPalabra){
    char letra;
    int i=0;
    printf("-%d   ",*nroPalabra);
    (*nroPalabra)++;
    for(i=posNuevaPalabra;(cadena[i]!='\0')&&(cadena[i]!='#');i++){
        letra = cadena[i];
        printf("%c",letra);
    }
        printf("\n");
}


void imprimirMatriz(int matriz[7][4]) {
	int i,j;

	for(i = 0; i < 7; i++) {
		for(j = 0; j < 4; j++) {
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
}
