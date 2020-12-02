/*====================================================================================================================================
PROJECT NAME: Mario Sokoban.
Developed by: HAMZA ZITOUNI
DEV HAMZA 3 - https://github.com/dev-Hamza-3
Github repository: https://github.com/dev-Hamza-3/Sokoban
======================================================================================================================================*/

#include "../headers/jeu.h"
#include "../headers/map.h"
#include <SDL/SDL.h>
#include <SDL_image.h>
#define TAILLE 34

void play(SDL_Surface* ecran)
{

    SDL_Surface  *caisse = NULL, *image = NULL;
    SDL_Event event;
    SDL_Rect positionImage;
    int continuer = 1, i=0, j=0;
    char ask;
    image = SDL_LoadBMP("img/mario_bas.bmp");

    //carte* m = NULL;
    //readMap(m,"maps/map1.msmap");

    for (i=0;i<30;i++)
    {
        for(j=0;j<15;j++)
        {
            positionImage.x = i * TAILLE;
            positionImage.y = j * TAILLE;
            SDL_BlitSurface(image, NULL, ecran, &positionImage);
        }
    }

    SDL_FreeSurface(image);

    return;
}
