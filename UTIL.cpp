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

    //Load player running texture
    if ( !gRunTexture.loadFromFile ( "assets/player/_Run.png") )
    {
        cout << "Unable to load player running texture!" << endl;
        success = false;
    }
    else
    {
        for (int i = 0 ; i < RUN_ANIMATION_FRAMES ; i++ )
        {
            gRunClips[ i ] = { i * 120 , 0 , 120 , 80 };
        }
    }

    //Load player jumping texture
    if ( !gJumpTexture.loadFromFile ( "assets/player/_Jump.png") )
    {
        cout << "Unable to load player jumping texture!" << endl;
        success = false;
    }
    else
    {
        for ( int i = 0 ; i < JUMP_ANIMATION_FRAMES ; i++ )
        {
            gJumpClips[ i ] = { i * 120 , 0 , 120 , 80 };
        }
    }

    //Load player falling texture
    if ( !gFallTexture.loadFromFile ( "assets/player/_Fall.png") )
    {
        cout << "Unable to load player falling texture!" << endl;
        success = false;
    }
    else
    {
        for ( int i = 0 ; i < FALL_ANIMATION_FRAMES ; i++ )
        {
            gFallClips[ i ] = { i * 120 , 0 , 120 , 80 };
        }
    }

    return success;
}

void close()
{
    //Free texture resource
    gRunTexture.free();
    gJumpTexture.free();
    gFallTexture.free();

    //Destroy window
    SDL_DestroyWindow ( gWindow );
    SDL_DestroyRenderer ( gRenderer );
    gWindow = NULL;
    gRenderer = NULL;

    //Quit SDL
    IMG_Quit();
    SDL_Quit();
}
