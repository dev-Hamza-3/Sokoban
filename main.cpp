/*====================================================================================================================================
PROJECT NAME: Mario Sokoban.
Developed by: HAMZA ZITOUNI
DEV HAMZA 3 - https://github.com/dev-Hamza-3
Github repository: https://github.com/dev-Hamza-3/Sokoban
======================================================================================================================================*/

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL_image.h>
#include "headers/zozor.h"
#include "headers/jeu.h"


int main(int argc, char *argv[])
{

    SDL_Surface *ecran = NULL, *menu = NULL;
    SDL_Rect positionMenu;
    SDL_Event event; // Cette variable servira plus tard à gérer les événements
    int continuer = 1;

    SDL_Init(SDL_INIT_VIDEO);
    ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Mario Sokoban", NULL);

    menu = SDL_LoadBMP("img/menu.bmp");

    positionMenu.x = 640 / 2 - menu->w / 2;
    positionMenu.y = 480 / 2 - menu->h / 2;
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0,0,0));
    SDL_BlitSurface(menu, NULL, ecran, &positionMenu);
    SDL_Flip(ecran);
    SDL_Flip(ecran);

    SDL_EnableKeyRepeat(10, 10); /* Activation de la répétition des touches */

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
                case SDLK_KP1: // 1 = play
                    play();
                    break;

                case SDLK_KP2: // 2 TO DO
                    continuer = 0;
                    break;

                case SDLK_ESCAPE:
                    continuer = 0;

                default:
                break;
            }
            break;
    }

}


    SDL_FreeSurface(menu);
    SDL_Quit();

    return EXIT_SUCCESS;
}
