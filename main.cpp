#include "LTexture.hpp"
#include "Global.hpp"
#include "Constants.hpp"
#include "UTIL.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include <SDL.h>
#include <SDL_image.h>

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

            //While the game is running
            while ( !quit )
            {
                //Handle events on queue
                while ( SDL_PollEvent ( &e ) != 0 )
                {
                    //User requests quit
                    if ( e.type == SDL_QUIT )
                    {
                        quit = true;
                    }
                }
            }
        }
    }
    //Free resource and close SDL
    close();

    return 0;

}
