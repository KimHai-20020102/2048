#ifndef ENGINE__H_
#define ENGINE__H_

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "public.h"

using namespace std;

void addPiece() {
    vector<pair<int,int> >  vec;

    for(int i = 0 ; i < 4 ; ++i)
        for(int j = 0 ; j < 4 ; ++j)
            if(!board[i][j])
                vec.push_back(pair<int,int>(i, j));

    int index = rand() % (int)vec.size();

    int x = vec[index].first;
    int y = vec[index].second;

    board[x][y] = 2;
}

void newGame() {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            board[i][j] = 0;
        }
    }
    addPiece();
}


bool canDoMove(int line, int column, int nextLine, int nextColumn) { // ham kiem tra xem co the thuc hien Move
    if(nextLine < 0 || nextColumn < 0 || nextLine >= 4 || nextColumn >= 4
       || (board[line][column] != board[nextLine][nextColumn] && board[nextLine][nextColumn] != 0)) {
       return false;
    }
    return true;
}

void Move(int direction) {
    int startLine = 0, startColumn = 0, lineStep = 1, columnStep = 1;
    if(direction == 0) { // huong phai
        startLine = 3; // bat dau thao tac tu dong thu 4
        lineStep = -1; // thao tac tu dong thu 4 den dong thu 1 nen moi lan -1
    }

    if(direction == 1) { // huong sang xuong
        startColumn = 3; // bat dau thao tac tu cot thu 4
        columnStep = -1; // thao tac tu cot thu 4 den cot thu 1 nen moi lan -1
    }

    int movePossible = 0; // kiem tra xem co the thuc hien Move it nhat 1 lan khong
    int canAddPiece = 0; // kiem tra xem co the tao them so moi khong

    do{
        movePossible = 0;
        for(int i = startLine; i >= 0 && i < 4; i += lineStep) {
            for(int j = startColumn; j >= 0 && j < 4; j += columnStep) {
                int nextI = i + dirLine[direction], nextJ = j + dirColumn[direction]; // toa do cua o can check xem co the thuc hien thao tac Move hay khong
                if(board[i][j] && canDoMove(i, j, nextI, nextJ)) {
                    board[nextI][nextJ] += board[i][j];
                    board[i][j] = 0;
                    movePossible = canAddPiece = 1; // thuc hien Move it nhat 1 lan
                }
            }
        }
    } while(movePossible);
    if(canAddPiece) addPiece();
}



bool is_game_over() {
    for(int i = 0 ; i < 4 ; i++ )
        for(int j = 0 ; j < 4 ; j ++)
        {
            if(board[i][j] == 0) return false;
            if(j < 3 && board[i][j] == board[i][j + 1]) return false;
            if(i < 3 && board[i + 1][j] == board[i][j]) return false;
        }
    return true;
}


#endif // ENGINE__H_
