#ifndef PUBLIC__H_
#define PUBLIC__H_


const int SCREEN_WIDTH = 900;
const int SCREEN_HEIGHT = 700;
const char* WINDOW_TITLE = "simple 2048";

int board[4][4];
int dirLine[4] = {1, 0, -1, 0};
int dirColumn[4]= {0, 1, 0, -1};

#endif // _PUBLIC__H_
