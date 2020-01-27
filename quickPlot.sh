#!/bin/bash

make
echo "make done"
./build/fhp.o
echo "sim done"
rm plots/*
echo "old plots deleted"
python src/plot.py
echo "plot done"
