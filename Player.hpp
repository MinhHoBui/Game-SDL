#pragma once

#include "Global.hpp"
#include "Constants.hpp"
#include "LTexture.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include <SDL.h>
#include <SDL_image.h>

#define JUMP 1
#define FALL 2
#define RUN 0

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

    int runCounter, jumpCounter, fallCounter;

};
