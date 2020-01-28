#include "utils.hpp"
#include <string>

void printOut(unsigned char board[height][width]){
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(i%2){
                std::cout << " " << +board[i][j];
            }
            else{
                std::cout << +board[i][j] << " ";
            }
            
        }
        std::cout << std::endl;
    }
}


void plotData(unsigned char board[height][width], int iteration)
{
    std::string filename = "data/data"+std::to_string(iteration)+".dat";
    std::ofstream myfile;
    myfile.open (filename.c_str());
    // myfile << "#X\tY" << std::endl;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(board[i][j]){
                if(i%2){
                    myfile << static_cast<double>(j)+0.5 << "\t" << static_cast<double>(i)*0.866 << "\t" << +board[i][j] << std::endl;
                }
                else{
                    myfile << j << "\t" << static_cast<double>(i)*0.866 << "\t" << +board[i][j] << std::endl;;
                }
            }
        }
    }
    myfile.close();
}

void plotFinal(double board[2][10], int iteration)
{
    std::string filename = "final/final"+std::to_string(iteration)+".dat";
    std::ofstream myfile;
    myfile.open (filename.c_str());
    for(int j=0;j<10;j++){
        myfile << board[0][j] << "\t" << board[1][j] << std::endl;
    }
    myfile.close();
}