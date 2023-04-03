#include "Constants.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

SDL_Window* gWindow = NULL;

SDL_Renderer* gRenderer = NULL;

LTexture gRunTexture;
SDL_Rect gRunClips [ RUN_ANIMATION_FRAMES ];

LTexture gJumpTexture;
SDL_Rect gJumpClips [ JUMP_ANIMATION_FRAMES ];

LTexture gFallTexture;
SDL_Rect gFallClips [ FALL_ANIMATION_FRAMES ];
