#include "LTexture.hpp"

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

bool LTexture::loadFromRenderedText ( string textureText , SDL_Color textColor )
{
    //Get rid of preexisting texture
    free();

    //Render text surface
    SDL_Surface* textSurface = TTF_RenderText_Solid( gFont, textureText.c_str(), textColor );
    if( textSurface == NULL )
    {
        cout << "Unable to render text surface!" << TTF_GetError() << endl;
    }
    else
    {
        //Create texture from surface pixels
        mTexture = SDL_CreateTextureFromSurface( gRenderer, textSurface );
        if( mTexture == NULL )
        {
            cout << "Unable to create texture from rendered text!" << SDL_GetError() << endl;
        }
        else
        {
            //Get image dimensions
            mWidth = textSurface->w;
            mHeight = textSurface->h;
        }

        //Get rid of old surface
        SDL_FreeSurface( textSurface );
    }

    //Return success
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


void LTexture::render( int x , int y , SDL_Rect* clip )
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
    SDL_RenderCopy ( gRenderer , mTexture , clip , &renderQuad );
}

int LTexture::getWidth()
{
    return mWidth;
}

int LTexture::getHeight()
{
    return mHeight;
}
