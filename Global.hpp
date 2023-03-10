#pragma once

#include "LTexture.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

//The window dimenions
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

//The window will be rendered
extern SDL_Window* gWindow;

//The renderer of the window
extern SDL_Renderer* gRenderer;

//Scene texture
extern LTexture gBGTexture;
extern LTexture gPlayerTexture;
