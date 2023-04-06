#include "UTIL.hpp"

using namespace std;

bool init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if ( SDL_Init ( SDL_INIT_VIDEO ) < 0 )
    {
        cout << "Could not initialize SDL!" << SDL_GetError() << endl;
        success = false;
    }
    else
    {
        //Set filtering texture to linear
        if ( !SDL_SetHint ( SDL_HINT_RENDER_SCALE_QUALITY , "1" ) )
        {
            cout << "Warning: Linear filtering texture not enabled!" << endl;
        }

        //Create window
        gWindow = SDL_CreateWindow ( "Game v1.0" , SDL_WINDOWPOS_UNDEFINED , SDL_WINDOWPOS_UNDEFINED , SCREEN_WIDTH , SCREEN_HEIGHT , SDL_WINDOW_SHOWN );
        if ( gWindow == NULL )
        {
            cout << "Could not create window!" << endl;
            success = false;
        }
        else
        {
            //Create renderer from window
            gRenderer = SDL_CreateRenderer ( gWindow , -1 , SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
            if ( gRenderer == NULL )
            {
                cout << "Could not create renderer!" << endl;
                success = false;
            }
            else
            {
                //Set renderer color
                SDL_SetRenderDrawColor ( gRenderer , 0xFF , 0xFF , 0xFF , 0xFF );

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if ( !( IMG_Init ( imgFlags ) && imgFlags ) )
                {
                    cout << "Could not initialize SDL image!" << IMG_GetError() << endl;
                    success = false;
                }

                //Initialize SDL_ttf
                if( TTF_Init() == -1 )
                {
                    cout << "SDL_ttf could not initialize!" << TTF_GetError() << endl;
                    success = false;
                }
            }
        }
    }

    return success;
}

bool loadMedia()
{
    //Loading success flag
    bool success = true;

    //Load player running texture
    if ( !gRunTexture.loadFromFile ( "assets/player/_Run.png") )
    {
        cout << "Unable to load player running texture!" << endl;
        success = false;
    }
    else
    {
        for (int i = 0 ; i < RUN_ANIMATION_FRAMES ; i++ )
        {
            gRunClips[ i ] = { i * 180 , 0 , 180 , 120 };
        }
    }

    //Load player jumping texture
    if ( !gJumpTexture.loadFromFile ( "assets/player/_Jump.png") )
    {
        cout << "Unable to load player jumping texture!" << endl;
        success = false;
    }
    else
    {
        for ( int i = 0 ; i < JUMP_ANIMATION_FRAMES ; i++ )
        {
            gJumpClips[ i ] = { i * 180 , 0 , 180 , 120 };
        }
    }

    //Load player falling texture
    if ( !gFallTexture.loadFromFile ( "assets/player/_Fall.png") )
    {
        cout << "Unable to load player falling texture!" << endl;
        success = false;
    }
    else
    {
        for ( int i = 0 ; i < FALL_ANIMATION_FRAMES ; i++ )
        {
            gFallClips[ i ] = { i * 180 , 0 , 180 , 120 };
        }
    }

    //Load background layers
    for ( int i = 0 ; i < BACKGROUND_LAYERS ; i++ )
    {
        if ( !gBackgroundTexture[ i ].loadFromFile ( BACKGROUND_FILE[ i ].c_str() ) )
        {
            cout << "Unable to load background texture at layer " << i + 1 << "!" << endl;
            success = false;
        }
    }

    //Load ground texture
    if ( !gGroundTexture.loadFromFile ( "assets/Background layers/ground.png" ) )
    {
        cout << "Unable to load ground texture!" << endl;
        success = false;
    }

    return success;
}

void close()
{
    //Free texture resource
    gRunTexture.free();
    gJumpTexture.free();
    gFallTexture.free();
    gGroundTexture.free();

    for ( int i = 0 ; i < BACKGROUND_LAYERS ; i++ )
    {
        gBackgroundTexture[ i ].free();
    }

    //Destroy window
    SDL_DestroyWindow ( gWindow );
    SDL_DestroyRenderer ( gRenderer );
    gWindow = NULL;
    gRenderer = NULL;

    //Quit SDL
    IMG_Quit();
    SDL_Quit();
}

void ScrollingBackground( vector <double> &offsetSpeed , LTexture(&gBackgroundTexture)[ BACKGROUND_LAYERS ] )
{
    //Input layer speed
    vector <double> layer_speed;
    layer_speed.push_back( LAYER_1_SPEED );
    layer_speed.push_back( LAYER_2_SPEED );
    layer_speed.push_back( LAYER_3_SPEED );
    layer_speed.push_back( LAYER_4_SPEED );
    layer_speed.push_back( LAYER_5_SPEED );
    layer_speed.push_back( LAYER_6_SPEED );
    layer_speed.push_back( LAYER_7_SPEED );
    layer_speed.push_back( LAYER_8_SPEED );
    layer_speed.push_back( LAYER_9_SPEED );
    layer_speed.push_back( LAYER_10_SPEED );


    //scrolling
    for ( int i = 0 ; i < BACKGROUND_LAYERS ; i++ )
    {
        //Creating offset
        offsetSpeed[ i ] -= layer_speed[ i ];
        if ( offsetSpeed[ i ] < -gBackgroundTexture[ i ].getWidth() )
        {
            offsetSpeed[ i ] = 0;
        }

        //render scrolling background
        gBackgroundTexture[ i ].render ( offsetSpeed[ i ] , 0 );
        gBackgroundTexture[ i ].render ( offsetSpeed[ i ] + gBackgroundTexture[ i ].getWidth() , 0 );
    }
}

void ScrollingGround ( int& speed , const int acceleration , LTexture &gGroundTexture )
{
    //creating offset
    speed -= GROUND_SPEED + acceleration;
    if ( speed < -gGroundTexture.getWidth()  )
    {
        speed = 0;
    }

    //render scrolling ground
    gGroundTexture.render ( speed , 0 );
    gGroundTexture.render ( speed + gGroundTexture.getWidth() , 0 );
}
