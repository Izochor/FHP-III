#!/bin/bash

rm fhp.o
echo "old file removed"
g++ -o fhp.o fhp.cpp init.cpp utils.cpp -L/home/izochor/Pobrane/gsl/lib -I/home/izochor/Pobrane/gsl/include -lgsl -lgslcblas -lm
./fhp.o
