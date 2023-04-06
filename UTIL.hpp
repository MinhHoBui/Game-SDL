#pragma once

#include "LTexture.hpp"
#include "Global.hpp"
#include "Constants.hpp"

using namespace std;

//Starts SDL and create window
extern bool init();

//Loads media
extern bool loadMedia();

//Free resources and close SDL
extern void close();

//Scrolling background
extern void ScrollingBackground( vector <double> &offsetSpeed , LTexture(&gBackgroundTexture)[ BACKGROUND_LAYERS ] );

//Scrolling ground
extern void ScrollingGround ( int& speed , const int acceleration , LTexture &gGroundTexture );


