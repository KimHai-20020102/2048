#ifndef GAME__H_
#define GAME__H_

#include <string>
#include <SDL.h>
#include "SDL_Utils.h"
#include "public.h"


class Game {
    public:

        const SDL_Color BGR_COLOR = {255, 255, 255};

        SDL_Window* window;
        SDL_Renderer* renderer;
        SDL_Surface* surface;
        SDL_Texture* texture;


        void init() {
            initSDL(window, renderer, WINDOW_TITLE, SCREEN_WIDTH, SCREEN_HEIGHT);
        }


        void clearScreen() {
            SDL_SetRenderDrawColor(renderer, BGR_COLOR.r, BGR_COLOR.g, BGR_COLOR.b, 0);
            SDL_RenderClear(renderer);
        }


        void renderBoxes() {
            SDL_SetRenderDrawColor(renderer, 192, 192, 192, 192);

            SDL_RenderClear(renderer);

            SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);

            int x = 0, y = 0; // goc toa do
            int box_width = 150, box_height = 150, distance = 5;
            for(int i = 0; i < 4; i ++){
                y = 0;
                for(int j = 0; j < 4; j ++){
                    SDL_Rect box;
                    box.x = x;
                    box.y = y;
                    box.w = box_width;
                    box.h = box_height;
                    SDL_RenderFillRect(renderer, &box);
                    if(board[i][j]) {
                        int a = board[i][j];
                        string text = to_string(board[i][j]);
                        TTF_Font* font = NULL;
                        font = TTF_OpenFont("VeraMoBd.ttf", 100);

                        SDL_Color fg1 = {223 , 0 , 41};
                        SDL_Color fg2 = {148 , 83 , 5};
                        SDL_Color fg3 = {249 , 244 , 0};
                        SDL_Color fg4 = {91 , 189 , 43};
                        SDL_Color fg5 = {0 , 174 , 114};
                        SDL_Color fg6 = {0 , 178 , 191};
                        SDL_Color fg7 = {32 , 90 , 167};
                        SDL_Color fg8 = {81 , 31 , 144};
                        SDL_Color fg9 = {100 , 0 , 75};



                        if(a < 8)
                            surface = TTF_RenderText_Solid(font, text.c_str(), fg1);
                        else if(a < 16 )
                            surface = TTF_RenderText_Solid(font, text.c_str(), fg2);
                        else if(a < 32 )
                            surface = TTF_RenderText_Solid(font, text.c_str(), fg3);
                        else if( a < 64)
                            surface = TTF_RenderText_Solid(font, text.c_str(), fg4);
                        else if( a < 128)
                            surface = TTF_RenderText_Solid(font, text.c_str(), fg5);
                        else if(a < 256)
                            surface = TTF_RenderText_Solid(font, text.c_str(), fg6);
                        else if(a < 512)
                            surface = TTF_RenderText_Solid(font, text.c_str(), fg7);
                        else if(a < 1024)
                            surface = TTF_RenderText_Solid(font, text.c_str(), fg8);
                        else
                            surface = TTF_RenderText_Solid(font, text.c_str(), fg9);


                        texture = SDL_CreateTextureFromSurface(renderer, surface);
                        SDL_FreeSurface(surface);

                        SDL_Rect srcRest;

                        TTF_SizeText(font, text.c_str(), &srcRest.w, &srcRest.h);

                        srcRest.x = 0;
                        srcRest.y = 0;

                        SDL_RenderCopy(renderer, texture, &srcRest, &box);
                    }
                    y += distance + box_height;
                }
                x += distance + box_height;
            }

            SDL_RenderPresent(renderer);
            SDL_Delay(10);
        }

        void game_over() {
            string text1 = "GAME OVER";

            TTF_Font* font = NULL;
            font = TTF_OpenFont("VeraMoBd.ttf", 50);

            SDL_Color fg = {0 , 0 , 0};
            surface = TTF_RenderText_Solid(font, text1.c_str(), fg);
            texture = SDL_CreateTextureFromSurface(renderer, surface);
            SDL_FreeSurface(surface);
            SDL_RenderCopy(renderer, texture, nullptr, nullptr);
            SDL_RenderPresent(renderer);
        }


};

#endif // GAME__H_
