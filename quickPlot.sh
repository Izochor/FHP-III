#!/bin/bash

make
echo "make done"
./build/sim
echo "sim done"
rm plots/*
echo "old plots deleted"
python src/plot.py
echo "plot done"
