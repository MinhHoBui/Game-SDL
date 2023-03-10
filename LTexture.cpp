#include "LTexture.hpp"
#include "Global.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

LTexture::LTexture()
{
    //Initialize
    mTexture = NULL;
    mWidth = 0;
    mHeight = 0;
}

LTexture::~LTexture()
{
    //Deallocate
    free();
}

bool LTexture::loadFromFile ( string path )
{
    //Get rid of preexisting texture
    free();

    //The final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load ( path.c_str() );
    if ( loadedSurface == NULL )
    {
        cout << "Unable to load image!" << IMG_GetError() << endl;
    }
    else
    {
        //Set color key image
        SDL_SetColorKey ( loadedSurface , SDL_TRUE , SDL_MapRGB ( loadedSurface->format , 0 , 0xFF , 0xFF ) );

        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface ( gRenderer , loadedSurface );
        if ( newTexture == NULL )
        {
            cout << "Unable to create texture from surface!" << SDL_GetError() << endl;
        }
        else
        {
            //Get image dimensions
            mWidth = loadedSurface->w;
            mHeight = loadedSurface->h;
        }

        //Free surface
        SDL_FreeSurface ( loadedSurface );
    }
    //Return success
    mTexture = newTexture;
    return mTexture != NULL;
}

void LTexture::free()
{
    //Free texture resource
    if ( mTexture != NULL )
    {
        SDL_DestroyTexture ( mTexture );
        mTexture = NULL;
        mWidth = 0;
        mHeight = 0;
    }
}

void LTexture::setColor( Uint8 red , Uint8 green , Uint8 blue )
{
    //Set coloring RGB
    SDL_SetTextureColorMod ( mTexture , red , green , blue );
}

void LTexture::setBlendMode( SDL_BlendMode blending )
{
    //Modulate blend factor
    SDL_SetTextureBlendMode ( mTexture , blending );
}

void LTexture::setAlpha( Uint8 alpha )
{
    //Modulate alpha factor
    SDL_SetTextureAlphaMod ( mTexture , alpha );
}

void LTexture::render( int x , int y , SDL_Rect* clip , double angle , SDL_Point* center , SDL_RendererFlip flip )
{
    //Set rendering space and render it to screen
    SDL_Rect renderQuad = { x , y , mWidth , mHeight };

    //Set clip rendering dimensions
    if ( clip != NULL )
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }

    //Render it to the screen
    SDL_RenderCopyEx ( gRenderer , mTexture , clip , &renderQuad , angle , center , flip );
}

int LTexture::getWidth()
{
    return mWidth;
}

int LTexture::getHeight()
{
    return mHeight;
}
