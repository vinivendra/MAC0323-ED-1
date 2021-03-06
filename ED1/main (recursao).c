#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "Pontos.h"
#define STRINGMAX 80

int linkAroundTheWorld (point *p, cell ***grid, float d);
void insertRandomPointsInGrid (cell ***grid, float d, int n);
int insertUserPointersInGrid (cell ***grid, float d);
point *startingPoint (cell ***grid, int g);
void printDebug (cell ***grid, int g, cell *conectados);

int main (int argc, char **argv) {

    int n = 0;
	int m = 0;
	int s = 0;
	int v = 0;
    float d = 0;
    char *parametro;

    int i = 0;
    int j = 0;
    int x = 0;
    int y = 0;
    int cont = 0;
    float g = 0;
    
    point *firstPoint = malloc(sizeof(point *));
    
    cell ***grid = NULL;
    
    cell *conectados = malloc(sizeof(cell *));
    cell *c = malloc(sizeof(cell *));
    
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
                        
            while (scanf("%d %d", &x, &y) == 1) {
                cell *cab = grid[(int)(x/d +1)][(int)(y/d + 1)];    /*pointeiro para a cabeca da lista do grid na posição em que o novo ponto deve ser inserido*/
                point newPoint;                                     /*allocação de memória para a nova célula e seu respectivo ponto*/
                cell newCell;
                newPoint.x = x;                                     /*insere as informações no novo ponto*/
                newPoint.y = y;
                newPoint.link = 0;
                newCell.point = &newPoint;                          /*associa a célula com o ponto*/
                newCell.prox = cab->prox;                           /*insere a célula no começo da respeciva lista do grid*/
                cab->prox = &newCell;
                n++;                                                /*incrementa o n*/
            }
            printf("Pontos gerados.\n");
            
		}
    }
    
    srand(s);               /*Atualiza a seed do random*/
    
    printf("Parametros:\n  n = %d\n  m = %d\n  s = %d\n  d = %f\n  v = %d\n", n, m, s, d, v);   /*Imprime os parâmetros para depuração*/
    
    if (d != 0) {           /*primeira opção*/
        if (grid == NULL && n != 0) {                   /*Se o grid não existir e tivermos N, devemos inicialliza-lo com números aleatórios.*/
            
            printf ("Gerando pontos aleatórios....\n");
            grid = malloc((g+4)*sizeof(cell **));       /*malloc a da 1a dimensao*/
            for (i = 0; i<g+4; i++) {
                grid[i] = malloc((g+4)*sizeof(cell *)); /*malloc da 2a*/
                for (j=0; j<g+4; j++) {                 /*preenche cada espaço com uma célula vazia*/
                    cell *newCell = malloc(sizeof(cell *));
                    newCell->point = NULL;
                    newCell->prox = NULL;
                    grid[i][j] = newCell;
                }
            }
            
            for (i = 0; i < n; i ++) {                  /*coloca valores aleatórios no grid*/
                cell *cab = malloc(sizeof(cell *));                             /*Ponteiro para a cabeça da lista no lugar certo do grid*/
                point *newPoint = malloc(sizeof(point *));                      /*ponto a ser inserido*/
                cell *newCell = malloc(sizeof(cell *));                         /*célula referente a esse ponto*/
                newPoint->x = (rand()*1.0)/RAND_MAX;     /*insere valores no ponto*/
                newPoint->y = (rand()*1.0)/RAND_MAX;
                newPoint->link = 0;
                newCell->point = newPoint;              /*conecta a celula com o ponto*/
                newCell->prox = NULL;
                                
                cab = grid[(int)(newPoint->x/d +2)][(int)(newPoint->y/d +2)];     /*cabeca aponta para o lugar certo*/
                
                newCell->prox = cab->prox;               /*insere a celula criada logo após a cabeça*/
                cab->prox = newCell;
            }
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
        
        printf("Starting point = %f, %f\n", firstPoint->x, firstPoint->y);
        
        cont = 0;
        
        cont = linkAroundTheWorld(firstPoint, grid, d);     /*checa se o grafo é conexo*/
        
        printf (" cont = %d, n = %d\n", cont, n);
                
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

void printDebug (cell ***grid, int g, cell *conectados) {

    int i, j;
    cell *c = malloc(sizeof(cell *));
    printf("PrintDebug:\n\nPontos que estao no grid:\n");
    for (i = 0; i < g+4; i ++) {
        for (j = 0; j < g+4; j ++) {
            for (c = grid[i][j]; c->prox != NULL; c = c->prox) {
                printf ("Point %d: x=%f, y=%f\n", c->prox->point->link, c->prox->point->x, c->prox->point->y);
            }
        }
    }
    
    printf("Na lista de conectados:\n");
    for (c = conectados; c!=NULL; c = c->prox) {
         printf ("Point %d: x=%f, y=%f\n", c->point->link, c->point->x, c->point->y);
    }
    printf("\n");
}

int linkAroundTheWorld (point *p, cell ***grid, float d) {
    cell *s = malloc(sizeof(cell *));
    int cont = 0; int i, j;
    
    p->link = 1;
    
    for (i = p->x/d +2 -1; i <= p->x/d +2 +1; i++) {
        for (j = p->y/d +2 -1; j <= p->y/d +2 +1; j++) {
            for (s = grid[i][j]->prox; s != NULL; s = s->prox) {
                if (!s->point->link) {
                    if (((p->x - s->point->x)*(p->x - s->point->x))+((p->y - s->point->y)*(p->y - s->point->y)) <= (d*d)) {
                        s->point->link = 1;
                        cont += linkAroundTheWorld(s->point, grid, d);
                    }
                }
            }
        }
    }
    
    cont ++;
    return cont;
}



int insertUserPointersInGrid (cell ***grid, float d) {
    
    int x = 0; int y = 0; int n = 0;
    
    while (scanf("%d %d", &x, &y) == 1) {
        cell *cab = grid[(int)(x/d +1)][(int)(y/d + 1)];    /*pointeiro para a cabeca da lista do grid na posição em que o novo ponto deve ser inserido*/
        point newPoint;                                     /*allocação de memória para a nova célula e seu respectivo ponto*/
        cell newCell;
        newPoint.x = x;                                     /*insere as informações no novo ponto*/
        newPoint.y = y;
        newPoint.link = 0;
        newCell.point = &newPoint;                          /*associa a célula com o ponto*/
        newCell.prox = cab->prox;                           /*insere a célula no começo da respeciva lista do grid*/
        cab->prox = &newCell;
        n++;                                                /*incrementa o n, valor que será retornado no fim da função*/
    }
    printf("Pontos gerados.\n");
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




