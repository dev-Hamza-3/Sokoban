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
    fscanf(f,"%c");
    char c;
    int i,j;

    for(i=0;i<L;i++)
    {
        for(j=0;j<H;j++)
        {
            if(c='\n')
            {
                i--;
            }
            else
            {
                m->tab[i][j]=fscanf(f,"%c");
            }
        }
    }
}

void draw(int x, int y, char c, SDL_Surface* ecran)
{
    SDL_Surface* image;
    SDL_Rect positionImage;
    switch(c)
    {
        case 'M':
        image = SDL_LoadBMP("img/marios_bas.bmp");
        break;

        case 'C':
        image = SDL_LoadBMP("img/caisse.bmp");
        break;

        case ' ':
        break;

        case 'O':
        image = SDL_LoadBMP("img/objectif.bmp");
        break;

        case 'X':
        image = SDL_LoadBMP("img/mur.bmp");
        break;

        default:
        break;

    }

    positionImage.x = x * TAILLE;
    positionImage.y = y * TAILLE;
    SDL_BlitSurface(image, NULL, ecran, &positionImage);
    SDL_Flip(ecran);
}

void funDraw(SDL_Surface* ecran, int x, int y)
{
    SDL_Event event;
    SDL_Surface* image;
    SDL_Rect positionImage;
    SDL_WaitEvent(&event);
    switch(event.type)
    {
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {

                case SDLK_1:
                    image = SDL_LoadBMP("img/mur.bmp");
                    break;

                case SDLK_2:
                    image = SDL_LoadBMP("img/mario_bas.bmp");
                    break;

                case SDLK_3:
                    image = SDL_LoadBMP("img/caisse.bmp");
                    break;

                case SDLK_4:
                    image = SDL_LoadBMP("img/objectif.bmp");
                    break;

                default:
                break;
            }
    }
    positionImage.x = x * TAILLE;
    positionImage.y = y * TAILLE;
    SDL_BlitSurface(image, NULL, ecran, &positionImage);
    SDL_Flip(ecran);
    SDL_FreeSurface(image);
}

char askDraw()
{
    char c;
    scanf("%c",c);
    return c;
}
