#include "Player.hpp"

using namespace std;

Player::Player()
{
    mPosX = SCREEN_WIDTH - 700;

    mPosY = GROUND;

    status = RUN;

    runCounter = jumpCounter = fallCounter = 0;
}

bool Player::OnGround()
{
    return mPosY == GROUND;
}

void Player::handleEvent ( SDL_Event& e )
{
    if ( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        switch ( e.key.keysym.sym )
        {
        case SDLK_SPACE:
            {
                if ( OnGround() )
                {
                    status = JUMP;
                }
            }
        }
    }
}

void Player::move()
{
    //player jump
    if ( status == JUMP && mPosY >= MAX_HEIGHT )
    {
        mPosY -= JUMP_VEL;
    }

    //if player reaches the max height
    if ( mPosY <= MAX_HEIGHT )
    {
        status = FALL;
    }

    //player falling
    if ( status == FALL && mPosY < GROUND )
    {
        mPosY += FALL_VEL;
    }
}

void Player::render()
{
    //render running animation
    if ( status == RUN )
    {
        gRunTexture.render( mPosX , mPosY , &gRunClips[ runCounter / 10 ] );
        runCounter++;
        if ( runCounter / 10 >= RUN_ANIMATION_FRAMES ) runCounter = 0;

    }

    //render jumping animation
    if ( status == JUMP )
    {
        gJumpTexture.render( mPosX , mPosY , &gJumpClips[ jumpCounter / 3 ] );
        jumpCounter++;
        if ( jumpCounter / 3 >= JUMP_ANIMATION_FRAMES ) jumpCounter = 0;
    }

    //render falling animation
    if ( status == FALL )
    {
        gFallTexture.render( mPosX , mPosY , &gFallClips[ fallingCounter / 3 ] );
        fallingCounter++;
        if ( fallingCounter / 3 >= FALL_ANIMATION_FRAMES ) fallingCounter = 0;
    }
}

int Player::getPosX()
{
    return mPosX;
}

int Player::getposY()
{
    return mPosY;
}
