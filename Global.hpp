#pragma once

#include "LTexture.hpp"
#include "Constants.hpp"

using namespace std;

//The window will be rendered
extern SDL_Window* gWindow;

//The renderer of the window
extern SDL_Renderer* gRenderer;

//The font of the window
extern TTF_Font* gFont;

//Run texture
extern class LTexture gRunTexture;
extern SDL_Rect gRunClips [ RUN_ANIMATION_FRAMES ];

//Jump texture
extern LTexture gJumpTexture;
extern SDL_Rect gJumpClips [ JUMP_ANIMATION_FRAMES ];

//Fall texture
extern LTexture gFallTexture;
extern SDL_Rect gFallClips [ FALL_ANIMATION_FRAMES ];

//background texture
extern LTexture gBackgroundTexture[ BACKGROUND_LAYERS ];
static string BACKGROUND_FILE[ BACKGROUND_LAYERS ] = {
    "assets/Background layers/layer1.png",
    "assets/Background layers/layer2.png",
    "assets/Background layers/layer3.png",
    "assets/Background layers/layer4.png",
    "assets/Background layers/layer5.png",
    "assets/Background layers/layer6.png",
    "assets/Background layers/layer7.png",
    "assets/Background layers/layer8.png",
    "assets/Background layers/layer9.png",
    "assets/Background layers/layer10.png"
};

//ground texture
extern LTexture gGroundTexture;
