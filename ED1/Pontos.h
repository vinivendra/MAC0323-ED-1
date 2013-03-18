#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    float x;
    float y;
} point;

typedef struct {
    point *p1;
    point *p2;
    float value;
} distance;

point *initPoint ();

distance *initDistance ();

point *initRandomPoint();

distance *initDistanceBetween (point *p1, point *p2);

float distanceBetween (point *p1, point *p2);

float square (float value);

int distanceHasPoint (distance *distance, point *p1);



