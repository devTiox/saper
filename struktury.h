#ifndef STRUKTURY_H
#define STRUKTURY_H

typedef struct board {
    int IsMine;
    int bomby_blisko;
} board;

typedef struct PlayBoard {
    char *output;
} PlayBoard;

PlayBoard**stworz_plansze(int y,int x);
board**pole_minowe(int y,int x);
void ustaw_sasiadow(int y,int x,board**bomby);

#endif

