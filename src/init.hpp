#ifndef INIT_H
#define INIT_H

#include <gsl/gsl_rng.h>
#include <time.h>

#define height 60
#define width 220
#define iterations 10000

void initTable(unsigned char table[3][162]);
void initBoard(unsigned char board[height][width]);
void initBlankBoard(unsigned char board[height][width]);
int checkNodes(unsigned char board[height][width], int x, int y, int xStart = 0, int yStart = 0);

bool bitCheck(unsigned char& node, int direction);
void bitSet(unsigned  char&  node , int pos);
void bitClear(unsigned char& node, int pos);

#endif
