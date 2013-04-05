#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "Pontos.h"
#define STRINGMAX 80

<<<<<<< HEAD
int linkAroundTheWorld (point *p, cell ***grid, float d);
void insertRandomPointsInGrid (cell ***grid, float d, int n);
int insertUserPointersInGrid (cell ***grid, float d);
point *startingPoint (cell ***grid, int g);
void printDebug (cell ***grid, int g, cell *conectados);
aresta *mergeSort (aresta *arestas, int size);
aresta *merge (aresta* a, int n, aresta* b, int m);
int eSuficiente (float d, cell *desconectados, int n);
=======
int linkAround (point *p, cell ***grid, float d);
void insertRandomPointsInGrid (cell ***grid, float d, int n);
int insertUserPointersInGrid (cell ***grid, float d);
point *startingPoint (cell ***grid, int g);
>>>>>>> de9c824639d0356015dd38f2fb055154dc8f90c8

int main (int argc, char **argv) {

    int n = 0;
	int m = 0;
	int s = 0;
	int v = 0;
    float d = 0;
    char *parametro;

    int i = 0;
    int j = 0;
<<<<<<< HEAD
    int x = 0;
    int y = 0;
    int cont = 0;
    int g = 0;
    float dTemp = 0;
    float dMax = 0;

    point *firstPoint;

    cell ***grid = NULL;

    cell *c;
    cell *celula;

    cell *aux;
    cell *aux2;

    aresta *arestas = NULL;

    cell *conectados = malloc(sizeof(cell));
    cell *desconectados = malloc(sizeof(cell));
    cell *tail = malloc(sizeof(cell));
    desconectados->next = tail;
    tail->prev = desconectados;
    tail->point = NULL;

=======
    int cont = 0;
    float g = 0;
    
    point *firstPoint;
    
    cell ***grid = NULL;

>>>>>>> de9c824639d0356015dd38f2fb055154dc8f90c8
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
<<<<<<< HEAD
            g = 1.0/d+1;
=======
            g = 1.0/d;
>>>>>>> de9c824639d0356015dd38f2fb055154dc8f90c8
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
<<<<<<< HEAD

=======
            
>>>>>>> de9c824639d0356015dd38f2fb055154dc8f90c8
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
<<<<<<< HEAD

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

    if (d > 0 && m == 1) {

        printf ("Segunda forma.\n");


        printf ("Criando o grid....\n");
        grid = malloc((g+2)*sizeof(cell **));       /*malloc a da 1a dimensao*/
        for (i = 0; i<g+2; i++) {
            grid[i] = malloc((g+2)*sizeof(cell *)); /*malloc da 2a*/
            for (j=0; j<g+2; j++) {                 /*preenche cada espaço com uma célula vazia*/
                cell *newCell = malloc(sizeof(cell));
                newCell->point = NULL;
                newCell->prox = NULL;
                newCell->next = NULL;
                grid[i][j] = newCell;
            }
        }

        printf ("Grid criado.\nGerando pontos aleatórios....\n");

        for (i = 0; i < n; i ++) {                  /*coloca valores aleatórios no grid*/
            cell *cab = malloc(sizeof(cell *));                             /*Ponteiro para a cabeça da lista no lugar certo do grid*/
            point *newPoint = malloc(sizeof(point));                      /*ponto a ser inserido*/
            cell *newCell = malloc(sizeof(cell));                         /*célula referente a esse ponto*/
            newPoint->x = (rand()*1.0)/RAND_MAX;     /*insere valores no ponto*/
            newPoint->y = (rand()*1.0)/RAND_MAX;
            newPoint->link = 0;
            newPoint->n = 0;
            newCell->point = newPoint;              /*conecta a celula com o ponto*/
            newCell->prox = NULL;
            newCell->next = NULL;

            cab = grid[(int)(newPoint->x/d +1)][(int)(newPoint->y/d +1)];     /*cabeca aponta para o lugar certo*/

            newCell->prox = cab->prox;               /*insere a celula criada logo após a cabeça do grid*/
            cab->prox = newCell;

            newCell->next = desconectados->next;     /*insere a celula criada logo após a cabeça da lista de desconectados*/
            desconectados->next = newCell;
            newCell->next->prev = newCell;
            newCell->prev = desconectados;

        }
        printf("Pontos aleatórios gerados.\n");

        c = NULL;
        cont = 0;

        if (v == 1) {
            for (c = desconectados; c->next != NULL; c = c->next) {
                printf ("Point %d:    x=%f, y=%f\n", ++cont, c->next->point->x, c->next->point->y);
=======
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
>>>>>>> de9c824639d0356015dd38f2fb055154dc8f90c8
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
<<<<<<< HEAD

        aux = desconectados->next;
        if (aux == NULL) {
            printf("Houve um erro ao pegar um ponto arbitrário do grafo em que começar o algoritmo.\n");
            return 0;
        }

        desconectados->next = aux->next; /*Tira o primeiro ponto da desconectados e poe na conectados*/
        aux->next->prev = desconectados;

        aux->next = conectados->next;
        conectados->next = aux;

        aux->point->link = 1;


        aux = NULL;
        c = NULL;
        cont = n-1;
        dTemp = 0;
        dMax = 0;

        for (celula = conectados->next; celula != NULL; celula = celula->next) { /*Estoura as bolhas*/
            for (i = celula->point->x/d +1 -1; i <= celula->point->x/d +1 +1; i++) {
                for (j = celula->point->y/d +1 -1; j <= celula->point->y/d +1 +1; j++) {
                    for (c = grid[i][j]; c->prox != NULL;c = c->prox) {
                        dTemp = sqrt(((celula->point->x - c->prox->point->x)*(celula->point->x - c->prox->point->x)) + ((celula->point->y - c->prox->point->y)*(celula->point->y - c->prox->point->y)));
                        if (dTemp <= d && c->prox->point->link == 0) {


                            if (dTemp > dMax) {
                                dMax = dTemp;
                            }

                            /*Remove c->prox do desconectados e coloca ela no conectados*/
                            cont --;

                            c->prox->point->link = 1;
                            aux = c->prox;

                            aux->prev->next = aux->next;    /*tira da desconectados*/
                            aux->next->prev = aux->prev;

                            if (celula->next == NULL) {/*poe na conectados, logo depois da celula sendo analisada no momento*/
                                celula->next = aux;
                                aux->next = NULL;
                            }
                            else {
                                aux2 = celula->next;
                                celula->next = aux;
                                aux->next = aux2;
                            }
                        }
                    }
                }
            }

            if (cont == 0) break;

        }

        if (cont == 0) printf("O grafo eh conexo para o d escolhido.\n");
        else printf("Ainda existem %d pontos desconectados.\n", cont);

        printf("dMax = %f\n", dMax);

        if (cont < 0) {
            printf("Houve um erro na implementação do algoritmo. (erro 1)\n");
            return 0;
        }

        int k = 1;
        int vermelha = 0;
        dMax = d;
        int h = 1;
        aresta *aAux;
        int f = 0;

        arestas = NULL;

        for (celula = desconectados->next; celula->next != NULL;) { /*monta lista de arestas*/
            for (i = celula->point->x/d +1 -k; i <= celula->point->x/d +1 +k; i++) {
                if (i<=0 || i>=g+2) continue;
                for (j = celula->point->y/d +1 -k; j <= celula->point->y/d +1 +k; j++) {
                    if (j<=0 || j>=g+2) continue;

                    for (c = grid[i][j]->prox; c != NULL;c = c->prox) {

                        if (c->point->n == h) continue;
                        dTemp = sqrt(((celula->point->x - c->point->x)*(celula->point->x - c->point->x)) + ((celula->point->y - c->point->y)*(celula->point->y - c->point->y)));
                        if (dTemp <= dMax && dTemp != 0) {

                            aresta *newAresta = malloc(sizeof(aresta));
                            newAresta->d = dTemp;

                            aAux = arestas;
                            arestas = newAresta;
                            newAresta->prox = aAux;
                            f++;
                            if (c->point->link == 1) {
                                vermelha = 1;
                            }
                            c->point->n = h;
                        }
                    }
                }
            }
            if (vermelha == 0 && k < g+2) {
                k++;
                dMax += d;
            }
            else {
                vermelha = 0;
                k = 1;
                h++;
                dMax = d;
                celula = celula->next;
            }
        }

        aAux = arestas;
        f = 0;
        while (aAux != NULL) {
            aAux = aAux->prox;
            f++;
        }

        printf("f = %d\n", f);

        arestas = mergeSort(arestas, f);

        int esq = 0;
        int dir = 0;
        int meio = 0;
        int result = 0;
        for (aAux = arestas; aAux->prox != NULL; aAux = aAux->prox) {
            dir++;
        }
        aAux = arestas;

        float *array = malloc((dir+1)*sizeof(float));
        for (i = 0; i<=dir; i++) {
            array[i]=aAux->d;
            aAux = aAux->prox;
        }

        for (aux = desconectados->next; aux->next->point != NULL; aux = aux->next);
        aux->next = conectados->next;

        while (dir != esq) {
            meio = (dir + esq)/2;

            if(array[meio] != 0)
                result = eSuficiente (array[meio], desconectados, n);
            else result = 0;

            if (result == 1) {
                dir = meio;
            }
            else {
                if (esq == meio)
                    esq = dir;
                else
                    esq = meio;
            }
        }

        result = eSuficiente (array[esq], desconectados, n);

        if (result == 1) {
            printf("\nA resposta eh d = %f;\n", array[esq]);
        }
        else {
            printf("Por favor, estime um d maior.\n");
        }


=======
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
>>>>>>> de9c824639d0356015dd38f2fb055154dc8f90c8
    }
    return cont ++;
}

<<<<<<< HEAD
    else if (d > 0) {           /*primeira opção*/

        if (grid == NULL && n != 0) {                   /*Se o grid não existir e tivermos N, devemos inicialliza-lo com números aleatórios.*/

            printf ("Gerando pontos aleatórios....\n");
            grid = malloc((g+2)*sizeof(cell **));       /*malloc a da 1a dimensao*/
            for (i = 0; i<g+2; i++) {
                grid[i] = malloc((g+2)*sizeof(cell *)); /*malloc da 2a*/
                for (j=0; j<g+2; j++) {                 /*preenche cada espaço com uma célula vazia*/
                    cell *newCell = malloc(sizeof(cell));
                    newCell->point = NULL;
                    newCell->prox = NULL;
                    newCell->next = NULL;
                    grid[i][j] = newCell;
                }
            }

            for (i = 0; i < n; i ++) {                  /*coloca valores aleatórios no grid*/
                cell *cab = malloc(sizeof(cell *));                             /*Ponteiro para a cabeça da lista no lugar certo do grid*/
                point *newPoint = malloc(sizeof(point));                      /*ponto a ser inserido*/
                cell *newCell = malloc(sizeof(cell));                         /*célula referente a esse ponto*/
                newPoint->x = (rand()*1.0)/RAND_MAX;     /*insere valores no ponto*/
                newPoint->y = (rand()*1.0)/RAND_MAX;
                newPoint->link = i;
                newCell->point = newPoint;              /*conecta a celula com o ponto*/
                newCell->prox = NULL;
                newCell->next = NULL;

                cab = grid[(int)(newPoint->x/d +1)][(int)(newPoint->y/d +1)];     /*cabeca aponta para o lugar certo*/

                newCell->prox = cab->prox;               /*insere a celula criada logo após a cabeça*/
                cab->prox = newCell;
            }
        }

        else if (n == 0) {
            printf ("Houve um erro no cálculo no número de pontos ou ele não foi fornecido, apesar de ser necessário.\n");
            return 0;
        }

        c = NULL; cont = 0;
        if (v == 1)
            for (i = 0; i < g+2; i ++)
                for (j = 0; j < g+2; j ++)
                    for (c = grid[i][j]; c->prox != NULL; c = c->prox)
                        printf ("Point %d at grid[%d][%d]:\n    x=%f, y=%f\n", cont++, i, j, c->prox->point->x, c->prox->point->y);

        firstPoint = startingPoint(grid, g);
        if (firstPoint == NULL) {
            printf("Houve um erro ao pegar um ponto arbitrário do grafo em que começar o algoritmo.\n");
            return 0;
        }

        c = NULL;
        conectados->prox = NULL;
        conectados->point = firstPoint;

        cont = n;

        while (conectados != NULL) {
            for (i = conectados->point->x/d +1 -1; i <= conectados->point->x/d +1 +1; i++) {
                for (j = conectados->point->y/d +1 -1; j <= conectados->point->y/d +1 +1; j++) {
                    for (c = grid[i][j]; c->prox != NULL;) {

                        if (((conectados->point->x-c->prox->point->x)*(conectados->point->x-c->prox->point->x)) + ((conectados->point->y-c->prox->point->y)*(conectados->point->y-c->prox->point->y)) <= d*d) {

                            /*Remove c->prox do grid e coloca ela no conectados*/
                            cont --;

                            aux = c->prox;
                            c->prox = aux->prox;

                            if (conectados == NULL) {
                                conectados = aux;
                                aux->prox = NULL;
                            }
                            else {
                                aux2 = conectados->prox;
                                conectados->prox = aux;
                                aux->prox = aux2;
                            }

                        }
                        else {
                            c = c->prox;
                        }

                    }
                }
            }

            if (cont == 0) break;

            if (conectados != NULL) {
                /*Remove uma celula do conectados*/
                cell *aux3 = malloc(sizeof(cell *));
                aux3 = conectados;
                conectados = conectados->prox;
                free(aux3);
            }

        }



        /*cont = linkAroundTheWorld(firstPoint, grid, d);       checa se o grafo é conexo*/

        if (cont == 0) {
            printf("O grafo é conexo!!\n");
            return 0;
        }
        else if (cont > 0) {
            printf("O grafo não é conexo.\n");
            return 0;
        }
        else {
            printf("Houve um erro na implementação do algoritmo. (erro 1)\n");
            return 0;
        }

    }
=======
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
>>>>>>> de9c824639d0356015dd38f2fb055154dc8f90c8

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

int eSuficiente (float d, cell *desconectados, int n) {

     int g = 1.0/d + 1;
     int cont = 0;
     int i = 0;
     int j = 0;
     cell *c;
     cell *aux;
     cell *aux2;
     cell *conectados = malloc(sizeof(cell));
     cell ***grid;
     point *firstPoint;

     c = desconectados->next;

            printf ("...");
            grid = malloc((g+2)*sizeof(cell **));       /*malloc a da 1a dimensao*/
            for (i = 0; i<g+2; i++) {
                grid[i] = malloc((g+2)*sizeof(cell *)); /*malloc da 2a*/
                for (j=0; j<g+2; j++) {                 /*preenche cada espaço com uma célula vazia*/
                    cell *newCell = malloc(sizeof(cell));
                    newCell->point = NULL;
                    newCell->prox = NULL;
                    newCell->next = NULL;
                    grid[i][j] = newCell;
                }
            }

            for (i = 0; i < n && c!=NULL; i ++) {                  /*coloca valores aleatórios no grid*/
                cell *cab = malloc(sizeof(cell *));                             /*Ponteiro para a cabeça da lista no lugar certo do grid*/
                point *newPoint = malloc(sizeof(point));                      /*ponto a ser inserido*/
                cell *newCell = malloc(sizeof(cell));                         /*célula referente a esse ponto*/
                newPoint->x = c->point->x;     /*insere valores no ponto*/
                newPoint->y = c->point->y;
                newCell->point = newPoint;              /*conecta a celula com o ponto*/
                newCell->prox = NULL;
                newCell->next = NULL;

                cab = grid[(int)(newPoint->x/d +1)][(int)(newPoint->y/d +1)];     /*cabeca aponta para o lugar certo*/

                newCell->prox = cab->prox;               /*insere a celula criada logo após a cabeça*/
                cab->prox = newCell;

                c = c->next;
            }


        firstPoint = startingPoint(grid, g);
        if (firstPoint == NULL) {
            printf("Houve um erro ao pegar um ponto arbitrário do grafo em que começar o algoritmo.\n");
            return 0;
        }

        c = NULL;
        conectados->prox = NULL;
        conectados->point = firstPoint;

        cont = n;

        while (conectados != NULL) {
            for (i = conectados->point->x/d +1 -1; i <= conectados->point->x/d +1 +1; i++) {
                for (j = conectados->point->y/d +1 -1; j <= conectados->point->y/d +1 +1; j++) {
                    for (c = grid[i][j]; c->prox != NULL;) {

                        if (((conectados->point->x-c->prox->point->x)*(conectados->point->x-c->prox->point->x)) + ((conectados->point->y-c->prox->point->y)*(conectados->point->y-c->prox->point->y)) <= d*d) {

                            /*Remove c->prox do grid e coloca ela no conectados*/
                            cont --;

                            aux = c->prox;
                            c->prox = aux->prox;

                            if (conectados == NULL) {
                                conectados = aux;
                                aux->prox = NULL;
                            }
                            else {
                                aux2 = conectados->prox;
                                conectados->prox = aux;
                                aux->prox = aux2;
                            }

                        }
                        else {
                            c = c->prox;
                        }

                    }
                }
            }

            if (cont == 0) break;

            if (conectados != NULL) {
                /*Remove uma celula do conectados*/
                cell *aux3 = malloc(sizeof(cell *));
                aux3 = conectados;
                conectados = conectados->prox;
                free(aux3);
            }
        }

        if (cont == 0) return 1;
     return 0;
}

aresta *mergeSort (aresta *arestas, int size) {

    if (size == 1)
        return arestas;

    aresta *a;
    aresta *b;
    int n = 1;
    int m = 0;

    for (a = arestas; n < size/2; n++, a = a->prox) {
    }

    b = a->prox;
    a->prox = NULL;
    m = size - n;
    a = arestas;

    b = mergeSort(b, m);
    a = mergeSort(a, n);

    return merge (a, n, b, m);
}

aresta *merge (aresta* a, int n, aresta* b, int m) {

    aresta *aux;
    aresta *result = malloc(sizeof(aresta));
    aresta *e;

    result->prox = NULL;
    e = result;

    while (n != 0 && m != 0) {
        if (a->d <= b->d) {
            aux = a->prox;
            e->prox = a;
            e = e->prox;
            e->prox = NULL;
            a = aux;
            n--;
        }
        else {
            aux = b->prox;
            e->prox = b;
            e = e->prox;
            e->prox = NULL;
            b = aux;
            m--;
        }
    }

    if (n==0) e->prox = b;
    else e->prox = a;

    e = result->prox;
    n=0;
    while (e->prox!=NULL) {
        n++;
        e = e->prox;
    }

    e = result->prox;
    free(result);

    return e;
}

void printDebug (cell ***grid, int g, cell *conectados) {

    int i, j;
    cell *c = malloc(sizeof(cell *));
    printf("PrintDebug:\n\nPontos que estao no grid:\n");
    for (i = 0; i < g+2; i ++) {
        for (j = 0; j < g+2; j ++) {
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

    for (i = p->x/d +1 -1; i <= p->x/d +1 +1; i++) {
        for (j = p->y/d +1 -1; j <= p->y/d +1 +1; j++) {
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





