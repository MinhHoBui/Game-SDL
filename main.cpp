#include "LTexture.hpp"
#include "LButton.hpp"
#include "Global.hpp"
#include "UTIL.hpp"
#include "Player.hpp"
#include "Constants.hpp"

using namespace std;

int main ( int argc , char* args[] )
{
    //Start SDL and create window
    if ( !init() )
    {
        cout << "Failed to initialize!" << endl;
    }
    else
    {
        //Loads media
        if ( !loadMedia() )
        {
            cout << "Failed to load media!" << endl;
        }
        else
        {
            //Main loop flag
            bool quit = false;

            //Event handler
            SDL_Event e;

            //the player
            Player knight;

            //Offset speed scrolling
            int OffsetSpeed_Ground = BASE_OFFSET_SPEED;
            vector <double> offsetSpeed_BG ( BACKGROUND_LAYERS , BASE_OFFSET_SPEED );

            //While the game is running
            while ( !quit )
            {
                int startloop = SDL_GetTicks();

                //Handle events on queue
                while ( SDL_PollEvent ( &e ) != 0 )
                {
                    //User requests quit
                    if ( e.type == SDL_QUIT )
                    {
                        quit = true;
                    }

                    knight.handleEvent( e );

                }

                knight.move();

                //Clear screen
                SDL_SetRenderDrawColor ( gRenderer , 0xFF , 0xFF , 0xFF , 0xFF );
                SDL_RenderClear ( gRenderer );

                //Render background
                ScrollingBackground ( offsetSpeed_BG , gBackgroundTexture );
                ScrollingGround ( OffsetSpeed_Ground , acceleration , gGroundTexture );

                //render player
                knight.render();

                //Update screen
                SDL_RenderPresent ( gRenderer );

                int delta = SDL_GetTicks() - startloop;
                if (delta < FrameDelay )
                {
                    SDL_Delay( FrameDelay - delta );
                }

            }

        }

    //Free resource and close SDL
    close();

    }

    return 0;

}
