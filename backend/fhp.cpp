#include "fhp.hpp"

unsigned char collide(unsigned char inState, unsigned char table[3][162], int rand){
    return table[rand+1][inState];
}

void propagate(unsigned char board[HEIGHT][WIDTH], unsigned char temp[HEIGHT][WIDTH],int y, int x){
    int move = y%2; //przemienność względem parzystości linijki
    if(bitCheck(board[y+1][x+move-1],0)){//1 dobrze!
        if(y < HEIGHT-1 && x > 0){
            bitSet(temp[y][x],0);
        }
    }
    if(bitCheck(board[y][x-1],1)){//2 dobrze!
        if(x > 0){
            bitSet(temp[y][x],1);
        }
    }
    if(bitCheck(board[y-1][x+move-1],2)){//4 dobrze!
        if(y > 0 && x > 0){
            bitSet(temp[y][x],2);
        }
    }
    if(bitCheck(board[y-1][x+move],3)){//8 dobrze!
        if(y > 0 && x < WIDTH-1){
            bitSet(temp[y][x],3);
        }
    }
    if(bitCheck(board[y][x+1],4)){//16 dobrze!
        if(x < WIDTH-1){
            bitSet(temp[y][x],4);
        }
    }
    if(bitCheck(board[y+1][x+move],5)){//32 dobrze!
        if(y < HEIGHT-1 && x < WIDTH-1){
            bitSet(temp[y][x],5);
        }
    }
    if(bitCheck(board[y][x],6)){ // cząstka stoi, czy to dobrze?
        bitSet(temp[y][x],6);
    }
    if(bitCheck(board[y][x],7)){ // ściana
        bitSet(temp[y][x],7);
    }
}

int checkNodes(unsigned char board[HEIGHT][WIDTH], int x, int y, int xStart, int yStart){
    int fullNodes = 0;
    for(int i=yStart;i<y;i++){
        for(int j=xStart;j<x;j++){
            for(int k=0;k<7;k++)
            fullNodes += bitCheck(board[i][j],k);
        }
    }
    return fullNodes;
}

void addParticle(unsigned char board[HEIGHT][WIDTH],int trueDensity, int wantedDensity, int x){
    //initialize random number generator
    gsl_rng *r = gsl_rng_alloc(gsl_rng_mt19937);//ran3,r250,mt19937
    gsl_rng_set(r,time(NULL));
    
    int randX = 0;
    int randY = 0;
    int randDir = 0;

    for (int i=0;i<wantedDensity-trueDensity;i++){
        randX = gsl_rng_uniform_int(r,20) + x;
        randY = gsl_rng_uniform_int(r,HEIGHT-2) + 1;
        randDir = gsl_rng_uniform_int(r,6);

        while(bitCheck(board[randY][randX],randDir) == 1){
            randX = gsl_rng_uniform_int(r,20) + x;
            randY = gsl_rng_uniform_int(r,HEIGHT-2) + 1;
            randDir = gsl_rng_uniform_int(r,6);
        }
        bitSet(board[randY][randX],randDir);
    }
}

void substactParticle(unsigned char board[HEIGHT][WIDTH],int trueDensity, int wantedDensity, int x){
    //initialize random number generator
    gsl_rng *r = gsl_rng_alloc(gsl_rng_mt19937);//ran3,r250,mt19937
    gsl_rng_set(r,time(NULL));
    
    int randX = 0;
    int randY = 0;
    int randDir = 0;

    for (int i=0;i<trueDensity - wantedDensity;i++){
        randX = gsl_rng_uniform_int(r,20) + x;
        randY = gsl_rng_uniform_int(r,HEIGHT-2) + 1;
        randDir = gsl_rng_uniform_int(r,6);

        while(bitCheck(board[randY][randX],randDir) == 0){
            randX = gsl_rng_uniform_int(r,20) + x;
            randY = gsl_rng_uniform_int(r,HEIGHT-2) + 1;
            randDir = gsl_rng_uniform_int(r,6);
        }
        bitClear(board[randY][randX],randDir);
    }
}

void destroy(unsigned char board[HEIGHT][WIDTH]){
    for(int i=0;i<HEIGHT;i++){
        board[i][0] = 0;
        board[i][WIDTH-1] = 0;
    }
}
