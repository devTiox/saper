
#ifndef STRUKTURY_H
#define STRUKTURY_H


typedef struct board {
    int PosX;
    int PosY;
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
    int PosX;
    int PosY;
    char output;
} PlayBoard


#endif 

