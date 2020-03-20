// measure things during fhp sim
#include <iostream>

#include "utils.hpp"

// return velX / nParticles in a sector (minY,minY+6)
double velXSector(unsigned char board[height][width], int minY);
// return velocity field
void velField(unsigned char board[height][width],float velBoardX[height][width],float velBoardY[height][width]);
// return density of particles in board
float density(unsigned char board[height][width]);
// check value of a half of convergance parameter
float converge(unsigned char board[height][width]);
// check if sim converges, it check
bool ifConverge(float valConv1, float valConv150, float parConv=0.01);