#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "Pontos.h"

#define STRINGMAX 80

int linkAround (point *p, cell ***grid, float d);
void insertRandomPointsInGrid (cell ***grid, float d, int n);
int insertUserPointersInGrid (cell ***grid, float d);
point *startingPoint (cell ***grid, int g);

int main (int argc, char **argv) {

    int n = 0;
	int m = 0;
	int s = 0;
	int v = 0;
    float d = 0;
    char *parametro;

    int i = 0;
    int j = 0;
    int cont = 0;
    float g = 0;
    
    point *firstPoint;
    
    cell ***grid = NULL;

	printf("Bem vindos ao programa do vini limdo =3\n");

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
            g = 1.0/d;
        }
        else if (parametro[1] == 'v') {
            v = 1;
        }
        else if (parametro[1] == 'V') {
            v = 2;
        }
		else if (parametro[1] == 'C') {
            if (d == 0) {
                printf ("Erro; falta o d.\n");
                return 0; /*Sair bonitinho*/
            }
            
            printf ("Por favor, digite os pontos desejados e pressione ctrl+d no final.\n");
            grid = malloc((g+2)*sizeof(cell **));
            for (i = 0; i<g+2; i++) {
                grid[i] = malloc((g+2)*sizeof(cell *));
                for (j=0; j<g+2; j++) {
                    cell newCell;
                    newCell.point = NULL;
                    newCell.prox = NULL;
                    grid[i][j] = &newCell;
                }
            }
            n = insertUserPointersInGrid(grid, d);
		}
    }
    
    /*Atualiza a seed do random*/
    srand(s);
    
    /*Imprime os parâmetros para depuração*/
    printf("Parametros:\n  n = %d\n  m = %d\n  s = %d\n  d = %f\n  v = %d\n", n, m, s, d, v);
    
    if (d != 0) { /*primeira opção*/
        if (grid == NULL && n != 0) {
            printf ("Gerando pontos aleatórios....\n");
            grid = malloc((g+2)*sizeof(cell **));
            for (i = 0; i<g+2; i++) {
                grid[i] = malloc((g+2)*sizeof(cell *));
                for (j=0; j<g+2; j++) {
                    cell newCell;
                    newCell.point = NULL;
                    newCell.prox = NULL;
                    grid[i][j] = &newCell;
                }
            }
            insertRandomPointsInGrid (grid, d, n);
        }
        else if (n == 0) {
            printf ("Houve um erro no cálculo no número de pontos ou ele não foi fornecido, apesar de ser necessário.\n");
            return 0;
        }
        
        firstPoint = startingPoint(grid, g);
        if (firstPoint == NULL) {
            printf("Houve um erro ao pegar um ponto arbitrário do grafo em que começar o algoritmo.\n");
            return 0;
        }
        
        cont = linkAround(firstPoint, grid, d);
        
        if (cont == n) {
            printf("O grafo é conexo!!\n");
            return 0;
        }
        else if (cont < n) {
            printf("O grafo não é conexo.\n");
            return 0;
        }
        else {
            printf("Houve um erro na implementação do algoritmo. (erro 1)\n");
            return 0;
        }
        
    }
    
    
    return 0;
}

int linkAround (point *p, cell ***grid, float d) {
    p->link = 1;
    cell *s;
    int cont = 0; int i, j;
    for (i = p->x/d +1 -1; i <= p->x/d +1 +1; i++) {
        for (j = p->y/d +1 -1; j <= p->y/d +1 +1; j++) {
            for (s = grid[i][j]; s->prox != NULL; s = s->prox) {
                if (s->prox->point->link==0 && squaredDistanceBetween(p, s->prox->point) <= (d*d)) {
                    s->prox->point->link = 1;
                    cont = linkAround(s->prox->point, grid, d);
                }
            }
        }
    }
    return cont ++;
}

void insertRandomPointsInGrid (cell ***grid, float d, int n) {
    int i = 0;
    for (i = 0; i < n; i ++) {
        cell *cab;
        point newPoint;
        cell newCell;
        newPoint.x = (rand()*1.0)/RAND_MAX;
        newPoint.y = (rand()*1.0)/RAND_MAX;
        newPoint.link = 0;
        newCell.point = &newPoint;
        cab = grid[(int)(newPoint.x/d +1)][(int)(newPoint.y/d +1)];
        newCell.prox = cab->prox;
        cab->prox = &newCell;
    }
}

int insertUserPointersInGrid (cell ***grid, float d) {
    
    int x = 0; int y = 0; int n = 0;
    while (scanf("%d %d", &x, &y) != EOF) {
        cell *cab = grid[(int)(x/d +1)][(int)(y/d + 1)]; /*pointeiro para a cabeca da lista do grid na posição em que o novo ponto deve ser inserido*/
        point newPoint;/*allocação de memória para a nova célula e seu respectivo ponto*/
        cell newCell;
        newPoint.x = x;/*insere as informações no novo ponto*/
        newPoint.y = y;
        newPoint.link = 0;
        newCell.point = &newPoint;/*Associa a célula com o ponto*/
        newCell.prox = cab->prox;/*insere a célula no começo da respeciva lista do grid*/
        cab->prox = &newCell;
        n++;/*Incrementa o n, valor que será retornado no fim da função*/
    }
    return n;
}

point *startingPoint (cell ***grid, int g) {
    int i, j;
    for (i = 1; i < g+2; i ++) {
        for (j = 1; j < g+2; j++) {
            if (grid[i][j]->prox != NULL) {
                return grid[i][j]->prox->point;
            }
        }
    }
    return NULL;
}




