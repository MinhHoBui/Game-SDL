#pragma once

#include "Global.hpp"
#include "Constants.hpp"

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

    //Creates image from font string
    bool loadFromRenderedText( string textureText, SDL_Color textColor );

    //Deallocate texture
    void free();

    //Render texture at given point
    void render ( int x ,int y , SDL_Rect* clip = NULL );

    //Get image dimensions
    int getWidth();
    int getHeight();
private:
    //The actual hardware texture
    SDL_Texture* mTexture;

    //Image dimensions
    int mWidth, mHeight;
};
