#include "LButton.hpp"

LButton::LButton()
{
    mPosition.x = 0;
    mPosition.y = 0;

    mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
}

void LButton::setPosition ( int x , int y )
{
    mPosition.x = x;
    mPosition.y = y;
}

void LButton::handleEvent ( SDL_Event* e , int button_type )
{
    //If mouse event happened
    if ( e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP )
    {
        //Get mouse position
        int x , int y;

        //check button type
        int BUTTON_WIDTH , BUTTON_HEIGHT;
        if ( button_type == MENU_BUTTON )
        {
            BUTTON_WIDTH = MENU_BUTTON_WIDTH;
            BUTTON_HEIGHT = MENU_BUTTON_HEIGHT;
        }
        else if ( button_type == INGAME_BUTTON )
        {
            BUTTON_WIDTH = INGAME_BUTTON_WIDTH;
            BUTTON_HEIGHT = INGAME_BUTTON_HEIGHT;
        }
        else if ( button_type == UI_BUTTON )
        {
            BUTTON_WIDTH = UI_BUTTON_WIDTH;
            BUTTON_HEIGHT = UI_BUTTON_HEIGHT;
        }

        SDL_GetMouseState ( &x , &y );

        //check if mouse is in button
        bool inside = true;

        //Mouse is left of the button
        if( x < mPosition.x )
        {
            inside = false;
        }
        //Mouse is right of the button
        else if( x > mPosition.x + BUTTON_WIDTH )
        {
            inside = false;
        }
        //Mouse above the button
        else if( y < mPosition.y )
        {
            inside = false;
        }
        //Mouse below the button
        else if( y > mPosition.y + BUTTON_HEIGHT )
        {
            inside = false;
        }

        //Mouse is outside button
        if( !inside )
        {
            mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
        }
        //Mouse is inside button
        else
        {
            //Set mouse over sprite
            switch( e->type )
            {
                case SDL_MOUSEMOTION:
                mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
                break;

                case SDL_MOUSEBUTTONDOWN:
                mCurrentSprite = BUTTON_SPRITE_MOUSE_DOWN;
                break;

                case SDL_MOUSEBUTTONUP:
                mCurrentSprite = BUTTON_SPRITE_MOUSE_UP;
                break;
            }
        }
    }
}

void LButton::render( LTexture gButtonTexture , SDL_Rect gSpriteClips[ TOTAL_BUTTON ] )
{
    gButtonTexture.render( mPosition.x , mPosition.y , &gSpriteClips[ mCurrentSprite ] );
}
