/*====================================================================================================================================
PROJECT NAME: Mario Sokoban.
Developed by: HAMZA ZITOUNI
DEV HAMZA 3 - https://github.com/dev-Hamza-3
Github repository: https://github.com/dev-Hamza-3/Sokoban
======================================================================================================================================*/

#include "../headers/jeu.h"
#include <SDL/SDL.h>
#include <SDL_image.h>
#define TAILLE 34

void readMap(carte* m, char* nomF)
{
    FILE* f = NULL;

    f = fopen(nomF,"r");

    int L= fscanf(f,"%d");
    int H=fscanf(f,"%d");
    char c;
    int i,j;

    for(i=0;i<L;i++)
    {
        for(j=0;j<H;j++)
        {
            //fscanf("c")
        }
    }
}
