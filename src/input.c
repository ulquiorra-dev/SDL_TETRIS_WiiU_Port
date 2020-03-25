#include "input.h"

void getInput() {    

    SDL_Event event;

    /* Loop through waiting messages and process them */

    while (SDL_PollEvent(&event)) {        

            if(event.type == SDL_USEREVENT){
                TETROMINO_ACTION = AUTO_DROP;
            }
            
            if(event.type == SDL_JOYBUTTONDOWN) {
                switch (event.jbutton.button) {
                    
                    case SDL_CONTROLLER_BUTTON_START:  //TODO Chech with key is this
                    case SDL_CONTROLLER_BUTTON_GUIDE:  //TODO Chech with key is this
                    case SDL_CONTROLLER_BUTTON_Y:
                        exit(0);
                    break;

                    
                    case SDL_CONTROLLER_BUTTON_MAX:
                        TETROMINO_ACTION = DOWN;
                    break;

                    
                    case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:
                        TETROMINO_ACTION = RIGHT;
                    break;

                    
                    case SDL_CONTROLLER_BUTTON_DPAD_DOWN:
                        TETROMINO_ACTION = LEFT;
                    break;

                    case SDL_CONTROLLER_BUTTON_A:
                    case SDL_CONTROLLER_BUTTON_DPAD_LEFT:
                        TETROMINO_ACTION = ROTATE;
                    break;

                    case SDL_CONTROLLER_BUTTON_BACK:
                        TETROMINO_ACTION = RESTART;
                    break;

                    case SDL_CONTROLLER_BUTTON_B:
                        TETROMINO_ACTION = DROP;
                    break;

                    default:                        
                    break;
                }            
            }else {                

                if(event.type == SDL_QUIT) exit(0);
            }
            
        }
    
}
