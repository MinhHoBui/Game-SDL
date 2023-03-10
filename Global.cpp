#include "LTexture.hpp"
#include "Global.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

SDL_Window* gWindow = NULL;

SDL_Renderer* gRenderer = NULL;

LTexture gBGTexture;

LTexture gPlayerTexture;
