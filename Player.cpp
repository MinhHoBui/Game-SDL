#include "Player.hpp"

using namespace std;

Player::Player()
{
    mPosX = SCREEN_WIDTH - 700;

    mPosY = GROUND;

    ground = true;

    falling = jumping = false;

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
                    ground = false;
                    jumping = true;
                }
            }
        }
    }
}

void Player::move()
{
    //player jump
    if ( jumping && mPosY >= MAX_HEIGHT )
    {
        mPosY -= JUMP_VEL;
    }

    //if player reaches the max height
    if ( mPosY <= MAX_HEIGHT )
    {
        jumping = false;
        falling = true;
    }

    //player falling
    if ( falling && mPosY < GROUND )
    {
        mPosY += FALL_VEL;
    }

    if ( OnGround() )
    {
        falling = false;
        ground = true;
    }
}

void Player::render()
{
    //render running animation
    if ( ground )
    {
        gRunTexture.render( mPosX , mPosY , &gRunClips[ runCounter / 10 ] );
        runCounter++;
        if ( runCounter / 10 >= RUN_ANIMATION_FRAMES ) runCounter = 0;

    }

    //render jumping animation
    if ( jumping )
    {
        gJumpTexture.render( mPosX , mPosY , &gJumpClips[ jumpCounter / 3 ] );
        jumpCounter++;
        if ( jumpCounter / 3 >= JUMP_ANIMATION_FRAMES ) jumpCounter = 0;
    }

    //render falling animation
    if ( falling )
    {
        gFallTexture.render( mPosX , mPosY , &gFallClips[ fallCounter / 3 ] );
        fallCounter++;
        if ( fallCounter / 3 >= FALL_ANIMATION_FRAMES ) fallCounter = 0;
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
