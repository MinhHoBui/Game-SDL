#pragma once

#include "Constants.hpp"
#include "LTexture.hpp"
#include "Global.hpp"

using namespace std;

//the mouse button
class LButton
{
public:
    //Initialize internal variables
    LButton();

    //Set top left positions
    void setPosition ( int x , int y );

    //Handle mouse event
    void handleEvent ( SDL_Event* e , int button_type );

    //Show button sprite
    void render( LTexture gButtonTexture , SDL_Rect gSpriteClips[ TOTAL_BUTTON ] );

private:
    //Top left positions
    SDL_Point mPosition;

    //Currently used global sprite
    LButtonSprite mCurrentSprite;
};
