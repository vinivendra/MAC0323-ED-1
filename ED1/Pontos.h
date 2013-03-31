#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct point{
    float x;
    float y;
    int link;
} point;

typedef struct cell{
    point *point;
    struct cell *prox;
} cell;

typedef struct distance{
    point *p1;
    point *p2;
    float value;
} distance;

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

void insertPointInCell (point *point, cell *celula);