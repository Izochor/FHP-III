#include <iostream>
#include <gsl/gsl_rng.h>
#include <time.h>

#include "init.hpp"
#include "utils.hpp"

unsigned char collide(unsigned char inState, unsigned char table[3][161]){

    //inicjalizacja generatora liczby losowej
    gsl_rng *r = gsl_rng_alloc(gsl_rng_mt19937);//ran3,r250,mt19937
    gsl_rng_set(r,time(NULL));
    int rand = gsl_rng_uniform_int(r,2);

    return table[rand+1][inState];
}

bool bitCheck(unsigned char& node, int direction){
    return node & (1 << direction); 
}

void bitSet(unsigned  char&  node , int pos){
    node |= (1 << pos);
}

void bitClear(unsigned char& node, int pos){
    node &= !(1 << pos);
}

void propagate(unsigned char board[height][width], unsigned char temp[height][width],int y, int x){
    int move = y%2; //przemienność względem parzystości linijki
    if(bitCheck(board[y+1][x+move-1],0)){//1 dobrze!
	    bitSet(temp[y][x],0);
    }
    if(bitCheck(board[y][x-1],1)){//2 dobrze!
        bitSet(temp[y][x],1);
    }
    if(bitCheck(board[y-1][x+move-1],2)){//4 dobrze!
        bitSet(temp[y][x],2);
    }
    if(bitCheck(board[y-1][x+move],3)){//8 dobrze!
        bitSet(temp[y][x],3);
    }
    if(bitCheck(board[y][x+1],4)){//16 dobrze!
        bitSet(temp[y][x],4);
    }
    if(bitCheck(board[y+1][x+move],5)){//32 dobrze!
        bitSet(temp[y][x],5);
    }
}

int main()
{
    std::cout << BOLDGREEN << "START" << RESET << std::endl;

    unsigned char table[3][161];
    initTable(table);
    std::cout << GREEN << "TABLE READY" << RESET << std::endl;

    unsigned char board[height][width];
    initBoard(board);
    std::cout << GREEN << "BOARD READY" << RESET << std::endl;

    // printOut(board);
    plotData(board,0);

    std::cout << BLUE << "PROPAGATION + COLLISION: " << iterations << " ITERATIONS" << RESET << std::endl;

    for(int iters = 1;iters<=iterations;iters++){
        unsigned char blank[height][width];
        initBlankBoard(blank);

        for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                propagate(board,blank,i,j);//propagiation step
            }
        }

        // printOut(blank);

        for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                board[i][j] = blank[i][j];
            }
        }

        for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                board[i][j] = collide(board[i][j],table);//collision step
            }
        }

        // printOut(board);
        plotData(board,iters);
        // std::cout << iters << "------------------------------------------" << std::endl;
    }
    std::cout << BOLDGREEN << "END" << RESET << std::endl;
    return 0;
}