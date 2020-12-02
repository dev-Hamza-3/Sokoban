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
#define TAILLE 34

typedef struct
{
    int L,H;
    char tab[TAILLE][TAILLE];
} carte;

void readMap(carte* m, char* nomF);

void draw(int x, int y, char c, SDL_Surface* ecran);

void funDraw(SDL_Surface* ecran, int x, int y);

char askDraw();

#endif // MAP_H_INCLUDED
