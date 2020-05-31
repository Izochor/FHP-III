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


void writeBoard(unsigned char board[height][width], int iteration)
{
    std::string filename = "data/data"+std::to_string(iteration)+".dat";
    std::ofstream myfile;
    myfile.open (filename.c_str());
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

void writePoisseule(double board[2][bins], int iteration)
{
    std::string filename = "final/final"+std::to_string(iteration)+".dat";
    std::ofstream myfile;
    myfile.open (filename.c_str());
    for(int j=0;j<bins;j++){
        myfile << board[0][j] << "\t" << board[1][j] << std::endl;
    }
    myfile.close();
}

void writeConverge(float arrConv[iterations], int name){
    std::string filename = "converge/converge"+std::to_string(name)+".dat";
    std::ofstream myfile;
    myfile.open (filename.c_str());
    for(int j=0;j<iterations-150;j++){
        myfile << j << "\t" << abs(arrConv[j]/arrConv[j+150]-1) << std::endl;
    }
    myfile.close();    
}