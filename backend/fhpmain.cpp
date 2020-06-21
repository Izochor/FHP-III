#include "fhpmain.h"

int fhpmain(QVector<double> &x,QVector<double> &y, QVector<double> &conv, double boardFinal[HEIGHT][WIDTH], int &finalIter)
{
    std::cout << BOLDGREEN << "START" << RESET << std::endl;
    
    int rand = 0;
    double arrVel[iterations][bins];
    float arrConverge[iterations];
    int lastIter = 0;
    int convCounter = 0;

    std::cout << GREEN << "VARIABLES READY" << RESET << std::endl;

    unsigned char table[3][162];
    initTable(table);
    std::cout << GREEN << "TABLE READY" << RESET << std::endl;

    unsigned char board[HEIGHT][WIDTH];
    initBoard(board);
    std::cout << GREEN << "BOARD READY" << RESET << std::endl;

    //initialize random number generator
    gsl_rng *r = gsl_rng_alloc(gsl_rng_mt19937);//ran3,r250,mt19937
    gsl_rng_set(r,time(NULL));

    std::cout << GREEN << "RANDOMNESS READY" << RESET << std::endl;

    std::cout << GREEN << "FLOW: " << iterations << " ITERATIONS" << RESET << std::endl;
    unsigned char blank[HEIGHT][WIDTH];

    for(int iters = 1;iters<=iterations;iters++){
        initBlankBoard(blank);

        for(int i=0;i<HEIGHT;i++){
            for(int j=0;j<WIDTH;j++){
                propagate(board,blank,i,j);//propagiation step
            }
        }

        for(int i=0;i<HEIGHT;i++){
            for(int j=0;j<WIDTH;j++){
                board[i][j] = blank[i][j]; //copy main board to tmp board
            }
        }

        destroy(board); // destroy off board particles

        for(int i=0;i<HEIGHT;i++){
            for(int j=0;j<WIDTH;j++){
                rand = gsl_rng_uniform_int(r,2);
                board[i][j] = collide(board[i][j],table,rand);//collision step
            }
        }

        int leftNodes = checkNodes(board,21,HEIGHT,1); //check number of nodes on the left
        if( leftNodes < leftDens){
            addParticle(board,leftNodes,leftDens,1); // add
        } else {
            substactParticle(board,leftNodes,leftDens,1);// subtract
        }

        int rightNodes = checkNodes(board,WIDTH-1,HEIGHT,WIDTH-21); //check number of nodes on the right
        if( rightNodes < rightDens){
            addParticle(board,rightNodes,rightDens,WIDTH-21);// add
        } else {
            substactParticle(board,rightNodes,rightDens,WIDTH-21);// subtract
        }

        arrConverge[iters] = converge(board);

        for(int y=1, i=0;y<HEIGHT-1;y+=6,i++){
            arrVel[iters][i] = velXSector(board,y); //measure velX in sectors
        }

        if(iters%1000 == 0){
        std::cout << iters << "/" << iterations << std::endl;
        std::cout << BLUE << abs(arrConverge[iters-150]/arrConverge[iters]-1) << RESET << std::endl;
        }

        if(abs(arrConverge[iters-150]/arrConverge[iters]-1)<0.1){
            convCounter += 1;
        }else{
            convCounter = 0;
        }

        if(convCounter == 500){
            lastIter = iters;
            break;
        }
    }
    std::cout << GREEN << "FLOW READY" << RESET << std::endl;

    for(int k =0;k<bins;k++){
        x[k] = k+0.5;
        y[k] = 0;
        for(int i=lastIter-500;i<lastIter;i++){
            y[k] += arrVel[i][k];
        }
        y[k] /= 500;
    }
    finalIter = lastIter;

    for(int i=0;i<iterations-150;i++){
        conv[i] = abs(arrConverge[i]/arrConverge[i+150]-1) ;
//        std::cout<<conv[i]<<std::endl;
    }

    float arrVelX[HEIGHT][WIDTH];
    float arrVelY[HEIGHT][WIDTH];
    velField(board,arrVelX,arrVelY);

    for(int i=0;i<HEIGHT;i++){
        for(int j=0;j<WIDTH;j++){
            boardFinal[i][j] = arrVelX[i][j];
        }
    }

//    writeBoard(board,0);
//    printOut(board);


    std::cout << GREEN << "FLOW DATA READY" << RESET << std::endl;

    std::cout << GREEN << "FINAL MEAN DENSITY: " << density(board) << RESET << std::endl;
    std::cout << BOLDGREEN << "END" << RESET << std::endl;
    return 0;
}
