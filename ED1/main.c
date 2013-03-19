#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "Pontos.h"

#define STRINGMAX 80

int main (int argc, char **argv) {

    int n = 0;
	int m = 0;
	int s = 0;
	int v = 0;
    float d = 0;
    char *parametro;

    int i = 0;
    int j = 0;

    srand(s);

    point **array = NULL;

	printf("Bem vindo ao programa do vini limdo =3\n");

    for (i = 1; i < argc; i ++) { /*For para ler os parametros*/
        parametro = argv[i];
        if (parametro[1] == 'N') { /*Segurar essa linha contra acessos de chars alem da palavra do parametro*/
            n = atoi(&parametro[2]);
        }
        else if (parametro[1] == 'M') {
            m = atoi(&parametro[2]);
        }
        else if (parametro[1] == 's') {
            s = atoi(&parametro[2]);
        }
        else if (parametro[1] == 'd') {
            d = atof(&parametro[2]);
        }
        else if (parametro[1] == 'v') {
            v = 1;
        }
        else if (parametro[1] == 'V') {
            v = 2;
        }
		else if (parametro[1] == 'C') {
			if (n == 0) return 0; /*Dar exit bonitinho*/
            array = initArrayofNPoints(n);
			printf("Por favor entre os valores dos pontos.\n");
			for (j = 0; j < n; j++) {
				scanf("%f %f", &array[j]->x, &array[j]->y);
			}
		}
    }

    printf("Parametros:\n  n = %d\n  m = %d\n  s = %d\n  d = %f\n  v = %d\n", n, m, s, d, v);

    if (n != 0 && d != 0) {
        if (array == NULL) array = initArrayofNRandomPoints(n);
        if (v == 1) {
			printf ("\nPontos:\n\n");
            for (i = 0; i < n; i ++) {
                printf ("Ponto %i = (%f, %f);\n", i, array[i]->x, array[i]->y);
            }
        }
    }

    if (n != 0 && m != 0 && d == 0) {
        printf("Vou calcular a media de %d densidades para conjuntos de %d pontos aleatorios.\n", m, n);
    }



    return 0;
}



