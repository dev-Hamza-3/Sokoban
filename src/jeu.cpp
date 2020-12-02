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

    SDL_Surface  *caisse = NULL;
    SDL_Rect positionCaisse;
    SDL_Event event;
    caisse = SDL_LoadBMP("img/mur.bmp");
    int continuer = 1, i=0, j=0;

    for (i=0;i<30;i++)
    {
        for(j=0;j<15;j++)
        {
            positionCaisse.x = i * TAILLE;
            positionCaisse.y = j * TAILLE;
            SDL_BlitSurface(caisse, NULL, ecran, &positionCaisse);
        }
    }

    int

    carte* m = NULL;
    m->tab =(char*)malloc(sizeof(char)*TAILLE);
    SDL_Flip(ecran);
    readMap(m,"map1.msmap");


    while (continuer)
{
    SDL_WaitEvent(&event);
    switch(event.type)
    {
        case SDL_QUIT: /* Si c'est un événement de type "Quitter" */
            continuer = 0;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {

                case SDLK_ESCAPE:
                    continuer = 0;
                default:
                break;
            }
    }
}

    SDL_FreeSurface(caisse);

    return;
}
