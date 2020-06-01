// measure things during fhp sim
#include <iostream>

#include <gsl/gsl_rng.h>

#include "utils.hpp"

// return velX / nParticles in a sector (minY,minY+6)
double velXSector(unsigned char board[HEIGHT][WIDTH], int minY);
// return velocity field
void velField(unsigned char board[HEIGHT][WIDTH],float velBoardX[HEIGHT][WIDTH],float velBoardY[HEIGHT][WIDTH]);
// return density of particles in board
float density(unsigned char board[HEIGHT][WIDTH]);
// check value of a half of convergance parameter
float converge(unsigned char board[HEIGHT][WIDTH]);
// check if sim converges, it check
bool ifConverge(float valConv1, float valConv150, float parConv=0.01);
