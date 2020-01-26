#include <iostream>
#include <gsl/gsl_rng.h>
#include <time.h>
#include <vector>

#include "init.hpp"
#include "utils.hpp"

unsigned char collide(unsigned char inState, unsigned char table[3][162], int rand){
    return table[rand+1][inState];
}

void propagate(unsigned char board[height][width], unsigned char temp[height][width],int y, int x){
    int move = y%2; //przemienność względem parzystości linijki
    if(bitCheck(board[y+1][x+move-1],0)){//1 dobrze!
        if(y < height-1){
            bitSet(temp[y][x],0);
        }
    }
    if(bitCheck(board[y][x-1],1)){//2 dobrze!
        if(x > 0){
            bitSet(temp[y][x],1);
        }
    }
    if(bitCheck(board[y-1][x+move-1],2)){//4 dobrze!
        if(y > 0){
            bitSet(temp[y][x],2);
        }
    }
    if(bitCheck(board[y-1][x+move],3)){//8 dobrze!
        if(y > 0){
            bitSet(temp[y][x],3);
        }
    }
    if(bitCheck(board[y][x+1],4)){//16 dobrze!
        if(x < height-1){
            bitSet(temp[y][x],4);
        }
    }
    if(bitCheck(board[y+1][x+move],5)){//32 dobrze!
        if(y < height-1){
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

// void velocityField(unsigned char board[height][width]){
//     for(int x=0;x<height;x++){
//         for(int y=0;y<width;y++){
//             float vx = 0;
//             float vy = 0;
//             if(bitCheck(board[y][x],0)){//1 dobrze!
//                 vx += 0.5;
//                 vy += 0.866;
//             }
//             if(bitCheck(board[y][x],1)){//2 dobrze!
//                 vx += 1;
//             }
//             if(bitCheck(board[y][x],2)){//4 dobrze!
//                 vx += 0.5;
//                 vy -= 0.866;
//             }
//             if(bitCheck(board[y][x],3)){//8 dobrze!
//                 vx -= 0.5;
//                 vy -= 0.866;
//             }
//             if(bitCheck(board[y][x],4)){//16 dobrze!
//                 vx -= 1;
//             }
//             if(bitCheck(board[y][x],5)){//32 dobrze!
//                 vx -= 0.5;
//                 vy += 0.866;
//             }          
//             std::cout << "vx " << vx << " vy " << vy << std::endl;
//         }
//     }
// }

double N_i(unsigned char node){
    double answer = 0;
    for(int i = 0; i<7;i++){
        if(bitCheck(node,i)){
            answer +=1;
        }
    }
    answer /= 7;
    return answer;
}

// double d(unsigned char board[height][width], int x, int y){
//     int move = y%2; //przemienność względem parzystości linijki
//     if(bitCheck(board[y+1][x+move-1],0)){//1 dobrze!

//     }
//     if(bitCheck(board[y][x-1],1)){//2 dobrze!

//     }
//     if(bitCheck(board[y-1][x+move-1],2)){//4 dobrze!

//     }
//     if(bitCheck(board[y-1][x+move],3)){//8 dobrze!

//     }
//     if(bitCheck(board[y][x+1],4)){//16 dobrze!

//     }
//     if(bitCheck(board[y+1][x+move],5)){//32 dobrze!

//     }    
// }

int main()
{
    std::cout << BOLDGREEN << "START" << RESET << std::endl;
    
    int randX = 0;
    int randY = 0;
    int randDir = 0;
    int rand = 0;

    std::cout << GREEN << "VARIABLES READY" << RESET << std::endl;

    unsigned char table[3][162];
    initTable(table);
    std::cout << GREEN << "TABLE READY" << RESET << std::endl;

    unsigned char board[height][width];
    initBoard(board);
    std::cout << GREEN << "BOARD READY" << RESET << std::endl;

    //inicjalizacja generatora liczby losowej
    gsl_rng *r = gsl_rng_alloc(gsl_rng_mt19937);//ran3,r250,mt19937
    gsl_rng_set(r,time(NULL));

    std::cout << GREEN << "RANDOMNESS READY" << RESET << std::endl;

    // printOut(board);
    plotData(board,0);
    std::cout << checkNodes(board,20,height) << std::endl;
    std::cout << checkNodes(board,width,height,width-20) << std::endl;

    std::cout << BLUE << "PROPAGATION + COLLISION: " << iterations << " ITERATIONS" << RESET << std::endl;
    unsigned char blank[height][width];

    for(int iters = 1;iters<=iterations;iters++){
        initBlankBoard(blank);

        for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                propagate(board,blank,i,j);//propagiation step
            }
        }

        for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                board[i][j] = blank[i][j];
            }
        }

        for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                rand = gsl_rng_uniform_int(r,2);
                board[i][j] = collide(board[i][j],table,rand);//collision step
            }
        }

        int leftNodes = checkNodes(board,20,height); //make even number of nodes
        if( leftNodes < 60){
            for (int i=0;i<60-leftNodes;i++){
                randX = gsl_rng_uniform_int(r,20);
                randY = gsl_rng_uniform_int(r,height-1) + 1;
                randDir = gsl_rng_uniform_int(r,6);

                while(bitCheck(board[randY][randX],randDir) == 1){
                    randX = gsl_rng_uniform_int(r,20);
                    randY = gsl_rng_uniform_int(r,height-1) + 1;  
                    randDir = gsl_rng_uniform_int(r,6);
                }
                bitSet(board[randY][randX],randDir);
            }
        }

        int rightNodes = checkNodes(board,width,height,width-20); 
        if( rightNodes < 40){
            for (int i=0;i<60-leftNodes;i++){
                randX = gsl_rng_uniform_int(r,20)+200;
                randY = gsl_rng_uniform_int(r,height-1) + 1;
                randDir = gsl_rng_uniform_int(r,6);

                while(bitCheck(board[randY][randX],randDir) == 1){
                    randX = gsl_rng_uniform_int(r,20)+200;
                    randY = gsl_rng_uniform_int(r,height-1) + 1;  
                    randDir = gsl_rng_uniform_int(r,6);
                }
                bitSet(board[randY][randX],randDir);
            }
        }

        plotData(board,iters);
        // std::cout << iters << "/" << iterations << std::endl;
    }
    std::cout << BOLDGREEN << "END" << RESET << std::endl;
    return 0;
}