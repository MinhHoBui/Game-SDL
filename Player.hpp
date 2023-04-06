#pragma once

#include "Global.hpp"
#include "Constants.hpp"
#include "LTexture.hpp"

class Player
{
public:
    //Initialize the variables
    Player();

    //Check if player is on ground
    bool OnGround();

    //Handle the key presses and adjust velocity of player
    void handleEvent ( SDL_Event& e );

    //Player move
    void move();

    //Show the player on the screen
    void render();

    //Get position X
    int getPosX();

    //Get position Y
    int getposY();


private:
    int mPosX, mPosY;

    int status;

    bool ground, jumping , falling;

    int runCounter, jumpCounter, fallCounter;

};
