#!/bin/bash

rm fhp.o
echo "old exec removed"
rm data/data*
echo "old data removed"
g++ -o fhp.o fhp.cpp init.cpp utils.cpp -L/home/izochor/Pobrane/gsl/lib -I/home/izochor/Pobrane/gsl/include -lgsl -lgslcblas -lm -std=c++11
./fhp.o
