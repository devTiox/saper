#ifndef STRUKTURY_H
#define STRUKTURY_H

typedef struct board {
    int PosY;
    int PosX;
    int IsMine;
    struct board *left;
    struct board *right;
    struct board *up;
    struct board *down;
    struct board *lup;
    struct board *pup;
    struct board *ldown;
    struct board *pdown;
} board;

typedef struct PlayBoard {
    char *output;
} PlayBoard;

PlayBoard**stworz_plansze(int rozmiar);
#endif
