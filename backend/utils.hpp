// some nice colors for console and writing out data
#ifndef UTILS_H
#define UTILS_H 

#include <QFile>
#include <QTextStream>

#include <iostream>
#include <fstream>

#include "init.hpp"

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

// write out board to terminal 
void printOut(unsigned char board[HEIGHT][WIDTH]);
// write out state of board to file
void writeBoard(unsigned char board[HEIGHT][WIDTH], int iteration);
//// write out data concerning Poisseulle flow
//void writePoisseule(double board[2][bins], int iteration);
// writes convergance data to a file
void writeConverge(float arrConv[iterations], int name);

#endif
