/*====================================================================================================================================
PROJECT NAME: Mario Sokoban.
Developed by: HAMZA ZITOUNI
DEV HAMZA 3 - https://github.com/dev-Hamza-3
Github repository: https://github.com/dev-Hamza-3/Sokoban
======================================================================================================================================*/

#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int L,H;
    char** tab;
} carte;

void readMap(carte* m, char* nomF);

#endif // MAP_H_INCLUDED
