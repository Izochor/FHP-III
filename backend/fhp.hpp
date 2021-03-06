// main fhp functions
#include <iostream>
#include <vector>

#include <gsl/gsl_rng.h>

#include "init.hpp"
#include "utils.hpp"

// do collision step (read right value from collision table)
unsigned char collide(unsigned char inState, unsigned char table[3][162], int rand);
// do propagation step
void propagate(unsigned char board[HEIGHT][WIDTH], unsigned char temp[HEIGHT][WIDTH],int y, int x);

// check number of full positions from xStart, yStart to x,y 
int checkNodes(unsigned char board[HEIGHT][WIDTH], int x, int y, int xStart = 0, int yStart = 0);
// add particle to a creation sector on left or right, on left x=1, right x=WIDTH-21
void addParticle(unsigned char board[HEIGHT][WIDTH],int trueDensity, int wantedDensity, int x);
// subtract particle from a creation sector on left or right, on left x=1, right x=WIDTH-21
void substactParticle(unsigned char board[HEIGHT][WIDTH],int trueDensity, int wantedDensity, int x);
// set value of all bits in all nodes on maxX and minX positions to 0
void destroy(unsigned char board[HEIGHT][WIDTH]);
