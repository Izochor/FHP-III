#include "utils.hpp"

void printOut(unsigned char board[HEIGHT][WIDTH]){
    for(int i=0;i<HEIGHT;i++){
        for(int j=0;j<WIDTH;j++){
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


void writeBoard(unsigned char board[HEIGHT][WIDTH], int iteration)
{
    QString filename = "data/data"+QString::number(iteration)+".dat";
    QFile myfile(filename);
    QTextStream stream(&myfile);

    for(int i=0;i<HEIGHT;i++){
        for(int j=0;j<WIDTH;j++){
            if(board[i][j]){
                if(i%2){
                    stream << static_cast<double>(j)+0.5 << "\t" << static_cast<double>(i)*0.866 << "\t" << +board[i][j] << endl;
                }
                else{
                    stream << j << "\t" << static_cast<double>(i)*0.866 << "\t" << +board[i][j] << endl;;
                }
            }
        }
    }
    myfile.close();
}

//void writePoisseule(double board[2][bins], int iteration)
//{
//    QString filename = "final/final"+QString::number(iteration)+".dat";
//    QFile myfile(filename);
//    QTextStream stream(&myfile);

//    if ( myfile.open(QIODevice::ReadWrite) )
//    {
//        for(int j=0;j<bins;j++){
//            stream << board[0][j] << "\t" << board[1][j] << endl;
//        }
//    }
//    myfile.close();
//}

//void writeConverge(float arrConv[iterations], int name){
//    QString filename = "converge/converge"+QString::number(name)+".dat";
//    QFile myfile(filename);
//    QTextStream stream(&myfile);

//    for(int j=0;j<iterations-150;j++){
//        stream << j << "\t" << abs(arrConv[j]/arrConv[j+150]-1) << endl;
//    }
//    myfile.close();
//}
