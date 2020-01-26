#!/bin/bash

make
echo "make done"
./build/fhp.o
echo "sim done"
python src/plot.py
echo "plot done"
