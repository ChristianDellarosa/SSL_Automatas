#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int esCU(char c) {
	int res;
	switch (c) {
	case '0':
		res = 1;
		break;
	case '1':
		res = 1;
		break;
	default:
		res = 0;
	}
	return res;
}
int esP(char c) {
	if (c == '.')
		return 1;
	else
		return 0;
}
int esCN(char c) {
	int res;
	switch (c) {
	case '2':
		res = 1;
		break;
	case '3':
		res = 1;
		break;
	case '4':
		res = 1;
		break;
	case '5':
		res = 1;
		break;
	case '6':
		res = 1;
		break;
	case '7':
		res = 1;
		break;
	case '8':
		res = 1;
		break;
	case '9':
		res = 1;
		break;
	default:
		res = 0;
	}
	return res;
}
int esB(char c) {

	if (c == 'B')
		return 1;
	else
		return 0;
}
int esCentinela(char c) {
	if (c == '#')
		return 1;
	else
		return 0;
}
int esfdt(char c){
	if (c == '\0')
	return 1;
	else return 0;
}

void imprimirPalabra(char cadena[100],int inicio, int fin){
    char letra;
    while (inicio<=fin)
    {
        letra = cadena[inicio];
        printf("%c",letra);
        inicio=inicio+1;
    }
        printf("\n");

}

int analizarCaracter(char c, int matriz[9][8], int estadoActual) {
	int res;
	if (esCU(c)) {
		res = matriz[estadoActual][1];
	} else if (esP(c)) {
		res = matriz[estadoActual][2];
	} else if (esCN(c)) {
		res = matriz[estadoActual][3];
	} else if (esB(c)) {
		res = matriz[estadoActual][4];
	} else if (esCentinela(c)) {
		res = matriz[estadoActual][5];
	} else if (esfdt(c)) {
		res = matriz[estadoActual][7];
	} else  {
		res = matriz[estadoActual][6];
	}
	return res;
}

int esEstadoFinal(int estadoActual){
	if (estadoActual == 7 || estadoActual == 8)
	return 1;
	else return 0;
}

int pepe(void) {
    /*
    ER [01]\.[0-9]?|[01]*B Centinela: #
	char CeroUno[2] = { '0', '1' };
	char Punto[1] = { '.' };
	char CeroNueve[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	char Be[1] = { 'B' };
	char centinela = { '#' };
	*/
	int matriz[9][8] = {
	{ 0, 1, 5, 5, 2, 0, 5, 6 },
	{ 1, 3, 4, 5, 2, 0, 5, 6 },
	{ 2, 5, 5, 5, 5, 7, 5, 8 },
	{ 3, 3, 5, 5, 2, 0, 5, 6 },
	{ 4, 2, 5,2, 5, 7, 5, 8 },
	{ 5, 5, 5, 5, 5, 0, 5, 6 },
	{ 6 },                      // fdt
	{ 7, 1,	5, 5, 2, 0, 5, 6 }, // estado final
	{ 8 } };                    // estado final
    int estadoInicial = matriz[0][0];
	int estadoActual;
    int fdt = matriz[6][0];
    int continuar = 1;
    int nuevaPalabra;
    int finPalabra ;
    int numeroLista = 1;

    do{

	char cadena[100];
	printf("Ingrese cadena: ");
	scanf("%s", cadena);

	int i=0;
		while (!esfdt(cadena[i])) {
		estadoActual = estadoInicial;
		while (!esEstadoFinal(estadoActual) && estadoActual != fdt) {
            if (estadoActual==estadoInicial){
                nuevaPalabra = i;
            }
			estadoActual = analizarCaracter(cadena[i],matriz,estadoActual);
            finPalabra = i-1;
			i=i+1;
		}
		if (esEstadoFinal(estadoActual)){
            printf("%i.- ",numeroLista);
            imprimirPalabra(cadena,nuevaPalabra,finPalabra);
            numeroLista=numeroLista+1;
	 }
	}
    printf("Presione 1 para ingresar otra cadena. Presione 2 para terminar el proceso \n");
    scanf("%i", &continuar);
	}while ( continuar == 1);
	return 0;
}
