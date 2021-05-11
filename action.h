#ifndef ACTION__H_
#define ACTION__H_

#include "engine.h"

void getAction() {
    while(true) {
        SDL_Event e;
        if (SDL_PollEvent(&e) == 0) continue;
        else if (e.type == SDL_QUIT) return SDL_Quit();
        else if (e.type == SDL_KEYDOWN) {
            if(e.key.keysym.sym == SDLK_ESCAPE) return SDL_Quit();
            else if(e.key.keysym.sym == SDLK_a) {
                Move(2);
                break;
            }

            else if(e.key.keysym.sym == SDLK_d) {
                Move(0);
                break;
            }

            else if(e.key.keysym.sym == SDLK_s) {
                Move(1);
                break;
            }

            else if(e.key.keysym.sym == SDLK_w) {
                Move(3);
                break;
            }

            else if(e.key.keysym.sym == SDLK_n) {
                Game game;
                game.renderBoxes();
                break;
            }
        }
        else continue;
    }
}

#endif // ACTION__H_
