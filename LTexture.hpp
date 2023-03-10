#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

//Texture wrapper class
class LTexture
{
public:
    //Initialize variables
    LTexture();

    //Deallocate memory
    ~LTexture();

    //Load image at specified path
    bool loadFromFile ( string path );

    //Deallocate texture
    void free();

    //Set color modulation
    void setColor ( Uint8 red , Uint8 green , Uint8 blue );

    //Set blending
    void setBlendMode ( SDL_BlendMode blending );

    //Set alpha modulation
    void setAlpha ( Uint8 alpha );

    //Render texture at given point
    void render ( int x ,int y , SDL_Rect* clip = NULL , double angle = 0.0 , SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );

    //Get image dimensions
    int getWidth();
    int getHeight();
private:
    //The actual hardware texture
    SDL_Texture* mTexture;

    //Image dimensions
    int mWidth, mHeight;
};
