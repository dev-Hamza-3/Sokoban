/*====================================================================================================================================
PROJECT NAME: Mario Sokoban.
Developed by: HAMZA ZITOUNI
DEV HAMZA 3 - https://github.com/dev-Hamza-3
Github repository: https://github.com/dev-Hamza-3/Sokoban
======================================================================================================================================*/

#include "../headers/jeu.h"
#include <SDL/SDL.h>
#include <SDL_image.h>

void play(SDL_Surface* ecran)
{

    SDL_Surface  *caisse = NULL;
    SDL_Rect positionCaisse;
    SDL_Event event;
    int continuer = 1;

    caisse = SDL_LoadBMP("img/caisse.bmp");
    SDL_BlitSurface(caisse, NULL, ecran, &positionCaisse);
    SDL_Flip(ecran);
    while (continuer)
{
    SDL_WaitEvent(&event);
}



    return;
}
