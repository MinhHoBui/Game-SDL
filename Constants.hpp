#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#define BASE_OFFSET_SPEED 0

#define MENU_BUTTON 0
#define INGAME_BUTTON 1
#define UI_BUTTON 2

using namespace std;

//The window dimensions
const int SCREEN_WIDTH = 928;
const int SCREEN_HEIGHT = 675;

//player velocity
const int JUMP_VEL = 8;
const int FALL_VEL = 8;
const int MAX_HEIGHT = 315;
const int GROUND = 490;

//animation frame
const int RUN_ANIMATION_FRAMES = 10;
const int JUMP_ANIMATION_FRAMES = 3;
const int FALL_ANIMATION_FRAMES = 3;

//the background layers and its offset speed
const int BACKGROUND_LAYERS = 10;

const double LAYER_1_SPEED = 0.0;
const double LAYER_2_SPEED = 0.25;
const double LAYER_3_SPEED = 0.5;
const double LAYER_4_SPEED = 0.75;
const double LAYER_5_SPEED = 1.0;
const double LAYER_6_SPEED = 1.25;
const double LAYER_7_SPEED = 1.5;
const double LAYER_8_SPEED = 1.75;
const double LAYER_9_SPEED = 2.0;
const double LAYER_10_SPEED = 2.25;

//the ground and its offset speed
const int GROUND_SPEED = 2;
const int acceleration = 0;

//button dimensions
const int MENU_BUTTON_WIDTH = 190;
const int MENU_BUTTON_HEIGHT = 80;
const int INGAME_BUTTON_WIDTH = 80;
const int INGAME_BUTTON_HEIGHT = 80;
const int UI_BUTTON_WIDTH = 80;
const int UI_BUTTON_HEIGHT = 80;

//Buttons constants
const int TOTAL_BUTTON = 4;

enum LButtonSprite
{
    BUTTON_SPRITE_MOUSE_OUT = 0,
    BUTTON_SPRITE_MOUSE_OVER_MOTION = 1,
    BUTTON_SPRITE_MOUSE_DOWN = 2,
    BUTTON_SPRITE_MOUSE_UP = 3,
    BUTTON_SPRITE_TOTAL = 4
};

//Frame rate
const int FPS = 120;
const int FrameDelay = 1000 / FPS;
