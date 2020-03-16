#include "measurements.hpp"

double velXSector(unsigned char board[height][width], int minY){
    int nParticles = 0;
    float vx = 0;
    float vy = 0;
    
    for(int y=minY;y<minY+6;y++){
        for(int x=60;x<360;x++){
            if(bitCheck(board[y][x],0)){//1 dobrze!
                vx += 1;
                vy += 1;
                nParticles++;
            }
            if(bitCheck(board[y][x],1)){//2 dobrze!
                vx += 1;
                nParticles++;
            }
            if(bitCheck(board[y][x],2)){//4 dobrze!
                vx += 1;
                vy -= 1;
                nParticles++;
            }
            if(bitCheck(board[y][x],3)){//8 dobrze!
                vx -= 1;
                vy -= 1;
                nParticles++;
            }
            if(bitCheck(board[y][x],4)){//16 dobrze!
                vx -= 1;
                nParticles++;
            }
            if(bitCheck(board[y][x],5)){//32 dobrze!
                vx -= 1;
                vy += 1;
                nParticles++;
            }
            if(bitCheck(board[y][x],6)){//32 dobrze!
                nParticles++;
            }

        }
    }
    // std::cout << minY << "\t" << minY+5<< "\t";
    // std::cout <<"vx: "<< vx << "\t\t <vx>: " << vx/nParticles;
    // std::cout << "\t\t vy: " <<  vy  << "\t\t <vy>: " << vy/nParticles << std::endl;
    return vx/nParticles;
}

void velField(unsigned char board[height][width],float velBoardX[height][width],float velBoardY[height][width]){
    int nParticles = 0;

    for(int y=0;y<height;y++){
        for(int x=0;x<width;x++){
            nParticles = 0;
            if(bitCheck(board[y][x],0)){//1 dobrze!
                velBoardX[y][x] += 1;
                velBoardY[y][x] += 1;
                nParticles++;
            }
            if(bitCheck(board[y][x],1)){//2 dobrze!
                velBoardX[y][x] += 1;
                nParticles++;
            }
            if(bitCheck(board[y][x],2)){//4 dobrze!
                velBoardX[y][x] += 1;
                velBoardY[y][x] -= 1;
                nParticles++;
            }
            if(bitCheck(board[y][x],3)){//8 dobrze!
                velBoardX[y][x] -= 1;
                velBoardY[y][x] -= 1;
                nParticles++;
            }
            if(bitCheck(board[y][x],4)){//16 dobrze!
                velBoardX[y][x] -= 1;
                nParticles++;
            }
            if(bitCheck(board[y][x],5)){//32 dobrze!
                velBoardX[y][x] -= 1;
                velBoardY[y][x] += 1;
                nParticles++;
            }
            if(bitCheck(board[y][x],6)){//32 dobrze!
                nParticles++;
            }
            velBoardX[y][x] /= nParticles;
            velBoardY[y][x] /= nParticles;
        }
    }

}

float density(unsigned char board[height][width]){
    float dens = 0;
    for(int i=1;i<height-2;i++){
        for(int j=60;j<360-2;j++){
            for(int k=0;k<8;k++){
                dens += bitCheck(board[i][j],k);
            }
        }
    }
    int maxDens = (height-3)*(360-60);
    return dens/maxDens;
}