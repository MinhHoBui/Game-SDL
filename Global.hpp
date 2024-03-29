#pragma once

#include "LTexture.hpp"
#include "Constants.hpp"
#include "Enemy.hpp"

using namespace std;

extern SDL_Window* gWindow;

extern SDL_Renderer* gRenderer;

extern TTF_Font* gFont;

extern class LTexture gRunTexture;
extern SDL_Rect gRunClips [ RUN_ANIMATION_FRAMES ];

extern LTexture gJumpTexture;
extern SDL_Rect gJumpClips [ JUMP_ANIMATION_FRAMES ];

extern LTexture gFallTexture;
extern SDL_Rect gFallClips [ FALL_ANIMATION_FRAMES ];

extern LTexture gCrouchTexture;
extern SDL_Rect gCrouchClips [ CROUCH_ANIMATION_FRAMES ];

extern LTexture gBackgroundTexture[ BACKGROUND_LAYERS ];
static string BACKGROUND_FILE[ BACKGROUND_LAYERS ] = {
    "assets/Background layers/7.png",
    "assets/Background layers/6.png",
    "assets/Background layers/5.png",
    "assets/Background layers/4.png",
    "assets/Background layers/3.png",
    "assets/Background layers/2.png",
    "assets/Background layers/1.png"
};

extern LTexture gGroundTexture;

extern SDL_Rect gBatClips[ BAT_FRAMES ];

extern LTexture gMenuTexture;

extern LTexture gPlayTexture;

extern LTexture gInstructionTexture;

extern LTexture gPauseAndContinueTexture;
extern SDL_Rect gPauseAndContinueClips[ TOTAL_BUTTON ];

extern LTexture gSpaceTexture;
extern SDL_Rect gSpaceClips[ TOTAL_BUTTON ];

extern LTexture gEscTexture;
extern SDL_Rect gEscClips[ TOTAL_BUTTON ];

extern LTexture gSkeyTexture;
extern SDL_Rect gSkeyClips[ TOTAL_BUTTON ];

extern LTexture gIkeyTexture;
extern SDL_Rect gIkeyClips[ TOTAL_BUTTON ];

extern LTexture gYourScoreTextTexture;
extern LTexture gHighScoreTextTexture;

extern LTexture gScoreTexture;
extern LTexture gHiScoreTexture;

extern LTexture gGameOverTexture;

extern SDL_Color textColor;

extern Mix_Chunk* gJump;
extern Mix_Chunk* gPress;
extern Mix_Chunk* gPause;
extern Mix_Chunk* gGameStart;
extern Mix_Chunk* gGameOver;
extern Mix_Music* gMenuMusic;
extern Mix_Music* gInstructionMusic;
extern Mix_Music* gBackgroundMusic;

