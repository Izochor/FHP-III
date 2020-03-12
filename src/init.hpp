#ifndef INIT_H
#define INIT_H

#include <gsl/gsl_rng.h>
#include <time.h>

#define height 86
#define width 422
#define bins (height-2)/6
#define iterations 11000
#define measurement iterations-1000
#define leftDens 800
#define rightDens 400

void initTable(unsigned char table[3][162]);
void initBoard(unsigned char board[height][width]);
void initBlankBoard(unsigned char board[height][width]);
int checkNodes(unsigned char board[height][width], int x, int y, int xStart = 0, int yStart = 0);

bool bitCheck(unsigned char& node, int direction);
void bitSet(unsigned  char&  node , int pos);
void bitClear(unsigned char& node, int pos);
void destroy(unsigned char board[height][width]);

#endif
