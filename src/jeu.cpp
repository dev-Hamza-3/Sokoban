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

    SDL_Surface *image = NULL, *caisse = NULL, *mario_bas = NULL, *mur = NULL, *objectif = NULL;
    SDL_Event event;
    SDL_Rect positionImage;
    char c;
    int continuer = 1, i=0, j=0;
    int counter=0;
    caisse = SDL_LoadBMP("img/caisse.bmp");
    mario_bas = SDL_LoadBMP("img/mario_bas.bmp");
    mur = SDL_LoadBMP("img/mur.bmp");
    objectif = SDL_LoadBMP("img/objectif.bmp");

    for (i=0;i<30;i++)
    {
        for(j=0;j<15;j++)
        {
            counter++;
            switch(counter%4)
            {
                case 0:
                    image = caisse;
                    break;
                case 1:
                    image = mur;
                    break;
                case 2:
                    image = objectif;
                    break;
                case 3:
                    image = mario_bas;
                    break;
            }
            positionImage.x = i * TAILLE;
            positionImage.y = j * TAILLE;
            SDL_BlitSurface(image, NULL, ecran, &positionImage);
            SDL_Flip(ecran);
        }
    }
    SDL_Flip(ecran);

}
