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

// table with collision rules
void initTable(unsigned char table[3][162]);
// initialize board with preset conditions
void initBoard(unsigned char board[height][width]);
// initialize truly empty board
void initBlankBoard(unsigned char board[height][width]);
// check number of full positions from xStart, yStart to x,y 
int checkNodes(unsigned char board[height][width], int x, int y, int xStart = 0, int yStart = 0);

// check if bit of given position(direction) is full
bool bitCheck(unsigned char& node, int direction);
// set value of given bit to 1
void bitSet(unsigned  char&  node , int pos);
// set value of given bit to 0
void bitClear(unsigned char& node, int pos);
// set value of all bits in all nodes on maxX and minX positions to 0
void destroy(unsigned char board[height][width]);

#endif
