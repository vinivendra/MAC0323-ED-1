#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct point{
    float x;
    float y;
    int link;
<<<<<<< HEAD
    int n;
=======
>>>>>>> de9c824639d0356015dd38f2fb055154dc8f90c8
} point;

typedef struct cell{
    point *point;
<<<<<<< HEAD
    struct cell *prox; /*proximo no grid*/
    struct cell *next; /*proximo na lista de (des)conectados*/
    struct cell *prev; /*anterior na lista de (des)conectados*/
=======
    struct cell *prox;
>>>>>>> de9c824639d0356015dd38f2fb055154dc8f90c8
} cell;

typedef struct distance{
    point *p1;
    point *p2;
    float value;
} distance;

typedef struct aresta{
    cell *c1;
    cell *c2;
    float d;
    struct aresta *prox;
} aresta;

point *initPoint ();

distance *initDistance ();

point *initRandomPoint();

point **initArrayofNRandomPoints (int n);

point **initArrayofNPoints (int n);

distance *initDistanceBetween (point *p1, point *p2);

float distanceBetween (point *p1, point *p2);

float squaredDistanceBetween (point *p1, point *p2);

float square (float value);

int distanceHasPoint (distance *distance, point *p1);

<<<<<<< HEAD
void insertPointInCell (point *point, cell *celula);
=======
void insertPointInCell (point *point, cell *celula);
>>>>>>> de9c824639d0356015dd38f2fb055154dc8f90c8
