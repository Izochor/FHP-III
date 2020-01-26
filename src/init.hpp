#ifndef INIT_H
#define INIT_H

#include <gsl/gsl_rng.h>
#include <time.h>

#define height 60
#define width 120
#define iterations 1

void initTable(unsigned char table[3][162]);
void initBoard(unsigned char board[height][width]);
void initBlankBoard(unsigned char board[height][width]);

#endif
