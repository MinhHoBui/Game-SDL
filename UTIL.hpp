#pragma once

#include "LTexture.hpp"
#include "Global.hpp"
#include "Constants.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

//Starts SDL and create window
extern bool init();

//Loads media
extern bool loadMedia();

//Free resources and close SDL
extern void close();


