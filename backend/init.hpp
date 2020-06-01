// initialize fhp sim and bit operations
#ifndef INIT_H
#define INIT_H

#include <gsl/gsl_rng.h>
#include <time.h>

#define HEIGHT 86
#define WIDTH 422
#define bins (HEIGHT-2)/6
#define iterations 5000
#define measurement iterations-1000
#define leftDens 4000
#define rightDens 2000

// table with collision rules
void initTable(unsigned char table[3][162]);
// initialize board with preset conditions
void initBoard(unsigned char board[HEIGHT][WIDTH]);
// initialize truly empty board
void initBlankBoard(unsigned char board[HEIGHT][WIDTH]);

// check if bit of given position(direction) is full
bool bitCheck(unsigned char& node, int direction);
// set value of given bit to 1
void bitSet(unsigned  char&  node , int pos);
// set value of given bit to 0
void bitClear(unsigned char& node, int pos);

#endif
