/*====================================================================================================================================
PROJECT NAME: Mario Sokoban.
Developed by: HAMZA ZITOUNI
DEV HAMZA 3 - https://github.com/dev-Hamza-3
Github repository: https://github.com/dev-Hamza-3/Sokoban
======================================================================================================================================*/

#ifndef ZOZOR_H_INCLUDED
#define ZOZOR_H_INCLUDED

void zozorMove();

void zozorMove(){
    SDL_Surface *ecran = NULL, *zozor = NULL;
    SDL_Rect positionZozor;
    SDL_Event event; // Cette variable servira plus tard à gérer les événements
    int continuer = 1;

    SDL_Init(SDL_INIT_VIDEO);
    ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Gestion des événements en SDL", NULL);

    zozor = SDL_LoadBMP("zozor.bmp");

    positionZozor.x = 640 / 2 - zozor->w / 2;
    positionZozor.y = 480 / 2 - zozor->h / 2;
    SDL_SetColorKey(zozor, SDL_SRCCOLORKEY, SDL_MapRGB(zozor->format, 0, 0, 255));
    SDL_BlitSurface(zozor, NULL, ecran, &positionZozor);
    SDL_Flip(ecran);

    SDL_EnableKeyRepeat(10, 10); /* Activation de la répétition des touches */

    while (continuer)
{
    SDL_WaitEvent(&event); /* Récupération de l'événement dans event */
    switch(event.type) /* Test du type d'événement */
    {
        case SDL_QUIT: /* Si c'est un événement de type "Quitter" */
            continuer = 0;
            break;
        case SDL_KEYDOWN: /* Si appui sur une touche */
            switch (event.key.keysym.sym)
            {
                case SDLK_UP:
                    positionZozor.y = positionZozor.y -1;
                    break;

                case SDLK_DOWN:
                    positionZozor.y = positionZozor.y +1;
                    break;

                case SDLK_LEFT:
                    positionZozor.x = positionZozor.x -1;
                    break;

                case SDLK_RIGHT:
                    positionZozor.x = positionZozor.x +1;
                    break;


                case SDLK_ESCAPE: /* Appui sur la touche Echap, on arrête le programme */
                    continuer = 0;
                    break;

                default:
                break;
            }
            break;
    }
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
    SDL_BlitSurface(zozor, NULL, ecran, &positionZozor);
    SDL_Flip(ecran);
}


    SDL_FreeSurface(zozor);
    SDL_Quit();
    return;
}

#endif // ZOZOR_H_INCLUDED
