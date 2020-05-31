#include <iostream>

#include <gsl/gsl_rng.h>

#include "init.hpp"
#include "utils.hpp"
#include "fhp.hpp"
#include "measurements.hpp"

//int main()
//{
//    std::cout << BOLDGREEN << "START" << RESET << std::endl;
    
//    int randX = 0;
//    int randY = 0;
//    int randDir = 0;
//    int rand = 0;
//    double arrVel[1000][bins];
//    float arrConverge[iterations];
//    int nArrVel = 0;

//    std::cout << GREEN << "VARIABLES READY" << RESET << std::endl;

//    unsigned char table[3][162];
//    initTable(table);
//    std::cout << GREEN << "TABLE READY" << RESET << std::endl;

//    unsigned char board[height][width];
//    initBoard(board);
//    std::cout << GREEN << "BOARD READY" << RESET << std::endl;

//    //initialize random number generator
//    gsl_rng *r = gsl_rng_alloc(gsl_rng_mt19937);//ran3,r250,mt19937
//    gsl_rng_set(r,time(NULL));

//    std::cout << GREEN << "RANDOMNESS READY" << RESET << std::endl;

//    std::cout << GREEN << "FLOW: " << iterations << " ITERATIONS" << RESET << std::endl;
//    unsigned char blank[height][width];

//    for(int iters = 1;iters<=iterations;iters++){
//        initBlankBoard(blank);

//        for(int i=0;i<height;i++){
//            for(int j=0;j<width;j++){
//                propagate(board,blank,i,j);//propagiation step
//            }
//        }

//        for(int i=0;i<height;i++){
//            for(int j=0;j<width;j++){
//                board[i][j] = blank[i][j]; //copy main board to tmp board
//            }
//        }

//        destroy(board); // destroy off board particles

//        for(int i=0;i<height;i++){
//            for(int j=0;j<width;j++){
//                rand = gsl_rng_uniform_int(r,2);
//                board[i][j] = collide(board[i][j],table,rand);//collision step
//            }
//        }

//        int leftNodes = checkNodes(board,21,height,1); //check number of nodes on the left
//        if( leftNodes < leftDens){
//            addParticle(board,leftNodes,leftDens,1); // add
//        } else {
//            substactParticle(board,leftNodes,leftDens,1);// subtract
//        }

//        int rightNodes = checkNodes(board,width-1,height,width-21); //check number of nodes on the right
//        if( rightNodes < rightDens){
//            addParticle(board,rightNodes,rightDens,width-21);// add
//        } else {
//            substactParticle(board,rightNodes,rightDens,width-21);// subtract
//        }

//        arrConverge[iters] = converge(board);
//        if(iters>measurement){
//            for(int y=1, i=0;y<height-1;y+=6,i++){
//                arrVel[nArrVel][i] = velXSector(board,y); //measure velX in sectors
//            }
//            nArrVel++;
//        }

//        if(iters%1000 == 0){
//        std::cout << iters << "/" << iterations << std::endl;
//        std::cout << BLUE << abs(arrConverge[iters-150]/arrConverge[iters]-1) << RESET << std::endl;
//        }
//    }
//    std::cout << GREEN << "FLOW READY" << RESET << std::endl;

//    double arrVelFinal[2][bins];

//    for(int k =0;k<bins;k++){
//        arrVelFinal[0][k] = k+0.5;
//        arrVelFinal[1][k] = 0;
//        for(int i=0;i<1000;i++){
//            arrVelFinal[1][k] += arrVel[i][k];
//        }
//        arrVelFinal[1][k] /= 1000;
//    }
//    writePoisseule(arrVelFinal,23);
//    writeConverge(arrConverge,23);

//    std::cout << GREEN << "FLOW DATA READY" << RESET << std::endl;

//    std::cout << GREEN << "FINAL MEAN DENSITY: " << density(board) << RESET << std::endl;
//    std::cout << BOLDGREEN << "END" << RESET << std::endl;
//    return 0;
//}
