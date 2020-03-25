#include "main.h"

#include <romfs-wiiu.h>


int main(int argc, const char *argv[]) {

    romfsInit();
	chdir("romfs:/");

    // Start up SDL, and make sure it went ok
    //
    uint32_t flags = SDL_INIT_TIMER | SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_JOYSTICK;
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {

        fprintf(stderr,
                "\nUnable to initialize SDL:  %s\n",
                SDL_GetError());

        return 1;
    }   

    atexit(cleanup);

    init();

    unsigned int emergency_out = 0;

    bool quit = false;    

    // Start SDL_Joystick
    for (int i = 0; i < SDL_NumJoysticks(); i++) {
		if (SDL_JoystickOpen(i) == NULL) {
			printf("Failed to open joystick %d!\n", i);
			quit = true;
		}
    }

    while(!quit) {

        preRender();

        getInput();

        updateTetris();

        updateRender();

        // Set to ~60 fps.
        // 1000 ms/ 60 fps = 1/16 s^2/frame
        SDL_Delay(16);
        
        emergency_out ++;
        if (emergency_out > 30*60) quit = true;
    }

    return 0;
}
