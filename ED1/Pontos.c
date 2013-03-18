#include "Pontos.h"

point *initPoint (){
    point *result = malloc (sizeof(point));
    result->x = result->y = 0.0;
    return result;
}

distance *initDistance (){
    distance *result = malloc (sizeof(distance));
    result->p1 = result->p2 = NULL;
    result->value = 0.0;
    return result;
}

point *initRandomPoint () {
    point *result =  malloc (sizeof(point));
    result->x = rand() / (float)RAND_MAX;
    result->y = rand() / (float)RAND_MAX;
    return result;
}

distance *initDistanceBetween (point *p1, point *p2) {
    distance *result = malloc (sizeof(distance));
    result->p1 = p1;
    result->p2 = p2;
    result->value = distanceBetween (p1, p2);
    return result;
}

float distanceBetween (point *p1, point *p2) {
    return sqrt(square(p1->x-p2->x) + square(p1->y-p2->y));
}

float square (float value) {
    return value*value;
}

int distanceHasPoint (distance *distance, point *p1) {
    if (distance->p1 == p1) return 1;
    if (distance->p2 == p1) return 1;
    return 0;
}


