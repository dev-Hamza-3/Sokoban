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
    SDL_Event event; // Cette variable servira plus tard � g�rer les �v�nements
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

    SDL_EnableKeyRepeat(10, 10); /* Activation de la r�p�tition des touches */

    while (continuer)
{
    SDL_WaitEvent(&event); /* R�cup�ration de l'�v�nement dans event */
    switch(event.type) /* Test du type d'�v�nement */
    {
        case SDL_QUIT: /* Si c'est un �v�nement de type "Quitter" */
            continuer = 0;
            break;
        case SDL_KEYDOWN: /* Si appui sur une touche */
            switch (event.key.keysym.sym)
            {
                case SDLK_KP1:
                    play();
                    break;

                case SDLK_KP2:
                    continuer = 0;
                    break;

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
