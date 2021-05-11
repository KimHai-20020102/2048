#include <bits/stdc++.h>
#include <ctime>
#include <SDL_ttf.h>
#include "engine.h"
#include "game.h"
#include "action.h"

using namespace std;


int main(int argc, char *argv[]) {
    srand(time(NULL));
    Game game;
    newGame();
    game.init();
    game.renderBoxes();
    while(true) {
        while(!is_game_over()) {
            getAction();
            game.renderBoxes();
        }
        game.game_over();
        newGame();
    }

    return 0;
}
