#include "LTexture.hpp"
#include "Global.hpp"
#include "UTIL.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

bool init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if ( SDL_Init ( SDL_INIT_VIDEO ) < 0 )
    {
        cout << "Could not initialize SDL!" << SDL_GetError() << endl;
        success = false;
    }
    else
    {
        //Set filtering texture to linear
        if ( !SDL_SetHint ( SDL_HINT_RENDER_SCALE_QUALITY , "1" ) )
        {
            cout << "Warning: Linear filtering texture not enabled!" << endl;
        }

        //Create window
        gWindow = SDL_CreateWindow ( "Game v1.0" , SDL_WINDOWPOS_UNDEFINED , SDL_WINDOWPOS_UNDEFINED , SCREEN_WIDTH , SCREEN_HEIGHT , SDL_WINDOW_SHOWN );
        if ( gWindow == NULL )
        {
            cout << "Could not create window!" << endl;
            success = false;
        }
        else
        {
            //Create renderer from window
            gRenderer = SDL_CreateRenderer ( gWindow , -1 , SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
            if ( gRenderer == NULL )
            {
                cout << "Could not create renderer!" << endl;
                success = false;
            }
            else
            {
                //Set renderer color
                SDL_SetRenderDrawColor ( gRenderer , 0xFF , 0xFF , 0xFF , 0xFF );

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if ( !( IMG_Init ( imgFlags ) && imgFlags ) )
                {
                    cout << "Could not initialize SDL image!" << IMG_GetError() << endl;
                    success = false;
                }
            }
        }
    }

    return success;
}

bool loadMedia()
{
    //Loading success flag
    bool success = true;

    //Load player texture
    if ( !gPlayerTexture.loadFromFile ( ) )
    {
        cout << "Unable to load player texture!" << endl;
        success = false;
    }

    //Load background texture
    if ( !gBGTexture.loadFromFile ( ) )
    {
        cout << "Unable to load background image!" << endl;
        success = false;
    }

    return success;
}

void close()
{
    //Free texture resource
    gBGTexture.free();
    gPlayerTexture.free();

    //Destroy window
    SDL_DestroyWindow ( gWindow );
    SDL_DestroyRenderer ( gRenderer );
    gWindow = NULL;
    gRenderer = NULL;

    //Quit SDL
    IMG_Quit();
    SDL_Quit();
}
