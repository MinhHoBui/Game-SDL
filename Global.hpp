#pragma once

#include "LTexture.hpp"
#include "Constants.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

//The window will be rendered
extern SDL_Window* gWindow;

//The renderer of the window
extern SDL_Renderer* gRenderer;

//Run texture
extern LTexture gRunTexture;
extern SDL_Rect gRunClips [ RUN_ANIMATION_FRAMES ];

//Jump texture
extern LTexture gJumpTexture;
extern SDL_Rect gJumpClips [ JUMP_ANIMATION_FRAMES ];

//Fall texture
extern LTexture gFallTexture;
extern SDL_Rect gFallClips [ FALL_ANIMATION_FRAMES ];
