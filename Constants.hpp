#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

//The window dimensions
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

//player dimensions
const int PLAYER_WIDTH = 120;
const int PLAYER_HEIGHT = 80;

//player velocity
const int PLAYER_VEL = 15;
const int JUMP_VEL = 15;
const int FALL_VEL = 15;
const int MAX_HEIGHT = 60;
const int GROUND = 200;

//animation frame
const int RUN_ANIMATION_FRAMES = 10;
const int JUMP_ANIMATION_FRAMES = 3;
const int FALL_ANIMATION_FRAMES = 3;

