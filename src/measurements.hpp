// measure things during fhp sim
#include <iostream>

#include "utils.hpp"

// return velX / nParticles in a sector (minY,minY+6)
double velXSector(unsigned char board[height][width], int minY);
// return velocity field
void velField(unsigned char board[height][width],float velBoardX[height][width],float velBoardY[height][width]);
// return density of particles in board
float density(unsigned char board[height][width]);